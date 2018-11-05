#include "albumCanciones.h"
#include <iostream>
#include <fstream>

using namespace std;


void ordenac(albumCanciones &a, ifstream &f, ofstream &s){
    string clave,nombre,autor,anyo,segundos;
    getline(f,clave);
    getline(f,nombre);
    getline(f,autor);
    getline(f,anyo);
    getline(f,segundos);
    int lng=clave.size();
    if(clave[lng-1]=='\r'){
        clave.erase(lng-1,1);
    }
    lng=nombre.size();
    if(nombre[lng-1]=='\r'){
        nombre.erase(lng-1,1);
    }
    lng=autor.size();
    if(autor[lng-1]=='\r'){
        autor.erase(lng-1,1);
    }
    int anyo_cancion= stoi(anyo,nullptr,10);
    int segundos_cancion= stoi(segundos,nullptr,10);
    if(existeCancion(a,clave)){
        s << "ACTUALIZACION: ";
    }
    else{
        s << "INSERCION: ";
    }
    Cancion c= crear(nombre,autor,anyo_cancion,segundos_cancion);
    anyadirCancion(a,clave,c);
    s << generaCadena(clave) << ":::<* " << generaCadena(c) << "*>" <<endl;
}

void ordenlc(albumCanciones &a, ifstream &f, ofstream &s){
    string clave;
    getline(f,clave);
    int lng=clave.size();
    if(clave[lng-1]=='\r'){
        clave.erase(lng-1,1);
    }
    if(existeCancion(a,clave)){
        s << "ENCONTRADA: ";
        int puesto;
        bool error;
        puestodeCancion(a,clave,puesto,error);
        s << puesto << " ... ";
        Cancion c;
        obtenerCancion(a,clave,c,error);
        s << generaCadena(clave) << ":::<* " << generaCadena(c) << "*>" <<endl;
    }
    else{
        s <<"cancion DESCONOCIDA: " << generaCadena(clave) <<endl;
    };
}

void ordenep(albumCanciones &a, ifstream &f, ofstream &s){
    string pista;
    getline(f,pista);
    int pista_cancion= stoi(pista,nullptr,10);
    string clave;
    bool error;
    canciondePuesto(a,pista_cancion,clave,error);
    if(error){
        s << "eliminacion de pista INNECESARIA: " << generaCadena(pista_cancion) <<endl;
    }
    else{
        s << "pista ELIMINADA: " << generaCadena(pista_cancion) << " ... ";
        Cancion c;
        obtenerCancion(a,clave,c,error);
        s << generaCadena(clave) << ":::<* " << generaCadena(c) << "*>" <<endl;
        eliminarCancion(a,pista_cancion);
    }
}

void ordenlp(albumCanciones &a, ifstream &f, ofstream &s){
    string pista;
    getline(f,pista);
    int pista_cancion= stoi(pista,nullptr,10);
    string clave;
    bool error;
    canciondePuesto(a,pista_cancion,clave,error);
    if(error){
        s << "pista INEXISTENTE: " << generaCadena(pista_cancion) <<endl;
    }
    else{
        s << "PISTA: " << generaCadena(pista_cancion) << " ... ";
        Cancion c;
        obtenerCancion(a,clave,c,error);
        s << generaCadena(clave) << ":::<* " << generaCadena(c) << "*>" <<endl;
    }
}

void ordenoa(albumCanciones &a, ifstream &f, ofstream &s){
    string clave1,clave2;
    getline(f,clave1);
    getline(f,clave2);
    int lng=clave1.size();
    if(clave1[lng-1]=='\r'){
        clave1.erase(lng-1,1);
    }
    lng=clave2.size();
    if(clave2[lng-1]=='\r'){
        clave2.erase(lng-1,1);
    }
    if(existeCancion(a,clave1) && existeCancion(a,clave2)){
        int pista1,pista2;
        bool error;
        Cancion primera,segunda;
        puestodeCancion(a,clave1,pista1,error);
        puestodeCancion(a,clave2,pista2,error);
        obtenerCancion(a,clave1,primera,error);
        obtenerCancion(a,clave2,segunda,error);
        s << "INTERCAMBIAR: " <<endl;
        s << "pista A) " << generaCadena(pista1) << " ... " << generaCadena(clave1) << ":::<* " << generaCadena(primera) << "*>" <<endl;
        s << "pista B) " << generaCadena(pista2) << " ... " << generaCadena(clave2) << ":::<* " << generaCadena(segunda) << "*>" <<endl;
        intercambiarCanciones(a,clave1,clave2);
    }
    else{
        s << "intercambio IMPOSIBLE: " <<generaCadena(clave1) << " ### " <<generaCadena(clave2) <<endl;
    }

}

void ordenla(albumCanciones &a, ifstream &f, ofstream &s){
    s << "TITULO: " << generaCadena(tituloDeAlbum(a)) <<endl;
    s << "DURACION TOTAL: " << generaCadena(duracion(a)) <<endl;
    s << "NUMERO de canciones: " << generaCadena(numCanciones(a)) <<endl;
    s << listarAlbum(a);
}

void ejecutarOrden(string orden,albumCanciones &a,ifstream &f,ofstream &s){
    cout <<"Hola" <<endl;
    int lng=orden.size();
    if(orden[lng-1]=='\r'){
        orden.erase(lng-1,1);
    }
    cout << orden << endl;
    if(orden.compare("AC")==0){
        cout <<" Opcion correcta" <<endl;
        ordenac(a,f,s);
    }
    else if(orden.compare("LC")==0){
        ordenlc(a,f,s);
    }
    else if(orden.compare("EP")==0){
        ordenep(a,f,s);
    }
    else if(orden.compare("LP")==0){
        ordenlp(a,f,s);
    }
    else if(orden.compare("OA")==0){
        ordenoa(a,f,s);
    }
    else if(orden.compare("LA")==0){
        ordenla(a,f,s);
    }
}

int main () {
    ifstream f; //Declaramos flujo de entrada
    f.open("entrada.txt"); //Y lo asociamos al fichero rondaentrada.txt
    ofstream s; //Declaramos flujo de salida
    string orden;
    albumCanciones a;
    crear(a,"Mi lista de canciones");
    s.open("salida.txt"); //Asociamos la salida a rondasalida.txt
    cout << "Holi" <<endl;
    if(f.is_open()){
        cout <<"F Bien" <<endl;
    }
    if(f.is_open()&& s.is_open()){
        cout <<"Ey" <<endl;
        getline(f,orden); //Lee una line de el fichero de entrada
        ejecutarOrden(orden,a,f,s); //Y la ejecuta
        while(!f.eof()){ //Mientras que no lea el caracter fin de fichero, sigue leyendo las lineas y ejecutando la orden
            getline(f,orden);
            ejecutarOrden(orden,a,f,s);
        }
    }
    return 0;
}