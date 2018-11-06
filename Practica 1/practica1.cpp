//**********************************************************************************************************************
// Archivo: practica1.cpp
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   7 Noviembre 2018
// Coms:    EDA - Práctica 1 - Main
//**********************************************************************************************************************

#include "albumCanciones.h"
#include <iostream>
#include <fstream>

using namespace std;


void ordenac (albumCanciones &a, ifstream &f, ofstream &s) {
    string clave, nombre, autor, anyo, segundos;
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
    anyadirCancion(a, clave, c);
    s << to_string(clave) << ":::<* " << to_string(c) << "*>" << endl;
}

void ordenlc (albumCanciones &a, ifstream &f, ofstream &s) {
    string clave;
    getline(f,clave);

    unsigned long lng = clave.size();
    if (clave[lng-1] == '\r') clave.erase(lng-1, 1);

    if (existeCancion(a, clave)) {
        s << "ENCONTRADA: ";
        int puesto;
        bool error;
        puestodeCancion(a, clave, puesto, error);
        s << puesto << " ... ";
        Cancion c;
        obtenerCancion(a, clave, c, error);
        s << to_string(clave) << ":::<* " << to_string(c) << "*>" << endl;
    }
    else {
        s <<"cancion DESCONOCIDA: " << to_string(clave) << endl;
    }
}

void ordenep (albumCanciones &a, ifstream &f, ofstream &s) {
    string pista;
    getline(f, pista);
    int pista_cancion = stoi(pista, nullptr, 10);
    string clave;
    bool error;
    canciondePuesto(a, pista_cancion, clave, error);

    if (error) {
        s << "eliminacion de pista INNECESARIA: " << to_string(pista_cancion) << endl;
    }
    else {
        s << "pista ELIMINADA: " << to_string(pista_cancion) << " ... ";
        Cancion c;
        obtenerCancion(a, clave, c, error);
        s << to_string(clave) << ":::<* " << to_string(c) << "*>" << endl;
        eliminarCancion(a, pista_cancion);
    }
}

void ordenlp (albumCanciones &a, ifstream &f, ofstream &s) {
    string pista;
    getline(f, pista);
    int pista_cancion = stoi(pista, nullptr, 10);
    string clave;
    bool error;
    canciondePuesto(a, pista_cancion, clave, error);

    if (error) {
        s << "pista INEXISTENTE: " << to_string(pista_cancion) << endl;
    }
    else {
        s << "PISTA: " << to_string(pista_cancion) << " ... ";
        Cancion c;
        obtenerCancion(a, clave, c, error);
        s << to_string(clave) << ":::<* " << to_string(c) << "*>" << endl;
    }
}

void ordenoa (albumCanciones &a, ifstream &f, ofstream &s) {
    string clave1, clave2;
    getline(f, clave1);
    getline(f, clave2);

    unsigned long lng = clave1.size();
    if (clave1[lng-1] == '\r') clave1.erase(lng-1, 1);

    lng = clave2.size();
    if (clave2[lng-1]=='\r') clave2.erase(lng-1, 1);

    if (existeCancion(a, clave1) && existeCancion(a, clave2)) {
        int pista1, pista2;
        bool error;
        Cancion primera, segunda;

        puestodeCancion(a, clave1, pista1, error);
        puestodeCancion(a, clave2, pista2, error);
        obtenerCancion(a, clave1, primera, error);
        obtenerCancion(a, clave2, segunda, error);

        s << "INTERCAMBIAR:" << endl;
        s << "pista A) " << to_string(pista1) << " ... " << to_string(clave1) << ":::<* " << to_string(primera)
          << "*>" << endl;
        s << "pista B) " << to_string(pista2) << " ... " << to_string(clave2) << ":::<* " << to_string(segunda)
          << "*>" << endl;

        intercambiarCanciones(a,clave1,clave2);
    }
    else {
        s << "intercambio IMPOSIBLE: " << to_string(clave1) << " ### " << to_string(clave2) << endl;
    }

}

void ordenla (albumCanciones &a, ifstream &f, ofstream &s) {
    s << "TITULO: " << to_string(tituloDeAlbum(a)) << endl;
    s << "DURACION TOTAL: " << to_string(duracion(a)) << endl;
    s << "NUMERO de canciones: " << to_string(numCanciones(a)) << endl;
    s << listarAlbum(a);
}

void ejecutarOrden (const string &orden, albumCanciones &a, ifstream &f, ofstream &s) {
    if (orden == "AC") ordenac(a, f, s);

    else if (orden == "LC") ordenlc(a, f, s);

    else if (orden == "EP") ordenep(a, f, s);

    else if (orden == "LP") ordenlp(a, f, s);

    else if (orden == "OA") ordenoa(a, f, s);

    else if (orden == "LA") ordenla(a, f, s);
}

int main () {
    ifstream f;
    f.open("entrada.txt");
    ofstream s;
    s.open("salida.txt");

    string orden;
    albumCanciones a;
    crear(a,"Mi lista de canciones");

    if (f.is_open() && s.is_open()) {
        while (!f.eof()) {
            getline(f, orden);
            ejecutarOrden(orden, a, f, s);
        }
    }

    return 0;
}