//**********************************************************************************************************************
// Archivo: practica2.cpp
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - Main
//**********************************************************************************************************************

#include "repertorio.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


// Añadir una Canción al repertorio
void ordenac (repertorio &a, ifstream &f, ofstream &s) {
    cout << "Entro en AC" << endl;
    string clave, nombre, autor, anyo, segundos;
    bool error = false;
    getline(f,clave);
    getline(f,nombre);
    getline(f,autor);
    getline(f,anyo);
    getline(f,segundos);

    unsigned long lng = clave.size();
    if (clave[lng-1] == '\r') clave.erase(lng-1, 1);

    lng = nombre.size();
    if (nombre[lng-1] == '\r') nombre.erase(lng-1, 1);

    lng = autor.size();
    if (autor[lng-1] == '\r') autor.erase(lng-1, 1);

    int anyo_cancion = stoi(anyo, nullptr, 10);
    int segundos_cancion = stoi(segundos, nullptr, 10);

    if (existeCancion(a, clave)) s << "ACTUALIZACION: ";

    else s << "INSERCION: ";

    Cancion c = crear(nombre, autor, anyo_cancion, segundos_cancion);
    anyadir(a, clave, c);
    s << clave << ":::<* " << to_string(c) << "*>";
    if(escuchada(a,clave,error)){
        s << "escuchada" << endl;
    }
    else{
        s << "NO escuchada" << endl;
    }
}

// Obtener los datos de una Canción
void ordenoc (repertorio &a, ifstream &f, ofstream &s) {
    cout << "Yeee" << endl;
    string clave;
    getline(f,clave);

    unsigned long lng = clave.size();
    if (clave[lng-1] == '\r') clave.erase(lng-1, 1);

    if (existeCancion(a, clave)) {
        s << "ENCONTRADA: ";
        bool error;
        Cancion c;
        obtenerCancion(a, clave, c, error);
        s << clave << ":::<* " << to_string(c) << "*>";
        if(escuchada(a,clave,error)){
            s << "escuchada" << endl;
        }
        else{
            s << "NO escuchada" << endl;
        }
    }
    else {
        s <<"cancion DESCONOCIDA: " << clave << endl;
    }
}

// Eliminar una canción
void ordenec (repertorio &a, ifstream &f, ofstream &s) {
    string clave;
    getline(f,clave);

    unsigned long lng = clave.size();
    if (clave[lng-1] == '\r') clave.erase(lng-1, 1);
    bool error;

    if (!existeCancion(a, clave)) {
        s << "eliminacion de cancion INNECESARIA: " <<clave << endl;
    }
    else {
        s << "cancion ELIMINADA: ";
        Cancion c;
        obtenerCancion(a, clave, c, error);
        s << clave << ":::<* " << to_string(c) << "*>";
        if(escuchada(a,clave,error)){
            s << "escuchada" << endl;
        }
        else{
            s << "NO escuchada" << endl;
        }
        quitarCancion(a, clave);
    }
}

void ordenmes (repertorio &a, ifstream &f, ofstream &s) {
    string clave,num_canc;
    getline(f, clave);
    getline(f,num_canc);
    unsigned long lng = clave.size();
    if (clave[lng-1] == '\r') clave.erase(lng-1, 1);
    int numero = stoi(num_canc, nullptr, 10);
    bool error;

    if (existeCancion(a, clave)) {
        Cancion c;
        obtenerCancion(a, clave, c, error);
        if(escuchada(a,clave,error) == numero){
            s << "ESCUCHADA INNECESARIO: ";
        }
        else {
            s << "cambio ESCUCHADA: ";
            modificarEscuchada(a,clave,numero);
        }
        s << clave << ":::<* " << to_string(c) << "*>";
        if(escuchada(a,clave,error)){
            s << "escuchada" << endl;
        }
        else{
            s << "NO escuchada" << endl;
        }
    }
    else {
        s << "cambio IMPOSIBLE: " << clave << endl;
    }
}



void ordenlr (repertorio &a, ifstream &f, ofstream &s) {
    s << "TITULO: " << to_string(tituloRepertorio(a)) << endl;
    s << "NUMERO de canciones: " << to_string(totalCanciones(a)) << endl;
    s << listarRepertorio(a);
}

void ejecutarOrden (string &orden, repertorio &a, ifstream &f, ofstream &s) {
    cout << " Voy a ejecutar orden" << endl;
    int lng=orden.size();
    if(orden[lng-1]=='\r'){
        orden.erase(lng-1,1);
    }
    if (orden.compare("AC")==0) ordenac(a, f, s); // Añadir una Canción al repertorio

    else if (orden.compare("OC")==0) ordenoc(a, f, s); // Obtener los datos de una Canción

    else if (orden.compare("EC")==0) ordenec(a, f, s); // Eliminar una canción //TODO: terminar

    else if (orden.compare("MES")==0) ordenmes(a, f, s); // Modificar Escuchada

    else if (orden.compare("LR")==0) ordenlr(a, f, s); // Listar todas las canciones del repertorio
    else {
        cout << "No ejecuto orden" << endl;
    }
}

int main () {
    ifstream f;
    f.open("entrada.txt");
    ofstream s;
    s.open("salida.txt");

    string orden;
    repertorio a;
    crear(a, "Mi repertorio de canciones");

    if (f.is_open() && s.is_open()) {
        while (!f.eof()) {
            getline(f, orden);
            ejecutarOrden(orden, a, f, s);
        }
    }

    return 0;
}