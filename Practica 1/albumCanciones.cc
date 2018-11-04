//*********************************************
// Archivo: albumCanciones.cc
// Autor: Andrés Gavín Murillo 716358
// Autor: Jorge Fernández Muñoz 721529
// Fecha: 4 Noviembre 2018
// Coms: EDA - Practica 1 - TAD albumCanciones
//

#include "albumCanciones.h"
#include <string>
#include <iostream>

using namespace std;

void crear(albumCanciones &a,string titulo){
    a.tituloAlbum= titulo;
    a.duracionTotal=0;
    crear(a.Canciones);
}
int numCanciones(const albumCanciones &a){
    return cardinal(a.Canciones);
}
int duracion (const albumCanciones &a){
    return a.duracionTotal;
}
string tituloDeAlbum(const albumCanciones &a){
    return a.tituloAlbum;
}
bool existeCancion(const albumCanciones &a,const string s){
    return existe(a.Canciones,s);
}
void obtenerCancion(const albumCanciones &a,const string s, Cancion &c, bool &error){
    obtenerDato(a.Canciones,s,c,error);
}
void anyadirCancion(albumCanciones &a,const string s,const Cancion c){
    introducir(a.Canciones,s,c);
    a.duracionTotal+= duracion(c);
}
void eliminarCancion(albumCanciones &a, int puesto){
    eliminarXPuesto(a.Canciones,puesto);
}
void puestodeCancion(const albumCanciones &a,const string s, int &puesto, bool &error){
    puestoDeClave(a.Canciones,s,puesto,error);
}
void canciondePuesto(const albumCanciones &a, int puesto, string &clave, bool &error){
    obtenerXPuesto(a.Canciones,puesto,clave,error);
}
void intercambiarCanciones( albumCanciones &a,const string s,const string b){
    int puestoa,puestob;
    bool errora,errorb;
    puestoDeClave(a.Canciones,s,puestoa,errora);
    puestoDeClave(a.Canciones,b,puestob,errorb);
    if(!errora && !errorb){
        if(puestoa>puestob){
            recolocarEnPuesto(a.Canciones,s,puestob - puestoa);
            recolocarEnPuesto(a.Canciones,b,puestoa - puestob -1);
        }
        else{
            recolocarEnPuesto(a.Canciones,b,puestoa - puestob);
            recolocarEnPuesto(a.Canciones,s,puestob - puestoa -1);
        }
    }

}
void listarAlbum( albumCanciones &a){
    iniciarIterador(a.Canciones);
    string Clave;
    Cancion dato;
    bool error;
    int puesto;
    while( existeSiguiente(a.Canciones)){
        siguienteClave(a.Canciones,Clave,error);
        siguienteDato(a.Canciones,dato,error);
        puestoDeClave(a.Canciones,Clave,puesto,error);
        cout << puesto <<") " << generaCadena(Clave) << ":::" << "<* "<< generaCadena(dato) << "*>" <<endl;
        avanza(a.Canciones,error);
    }
}

