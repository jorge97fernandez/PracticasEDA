//**********************************************************************************************************************
// Archivo: albumCanciones.cpp
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   7 Noviembre 2018
// Coms:    EDA - Práctica 1 - TAD Álbum de Canciones (Implementación)
//**********************************************************************************************************************

#include "albumCanciones.h"

using namespace std;


// Implementación del TAD Canción:

/* Inicializa a. */
void crear (albumCanciones &a, string titulo) {
    a.tituloAlbum = titulo;
    a.duracionTotal = 0;
    crear(a.Canciones);
};

int numCanciones (const albumCanciones &a) {
    return cardinal(a.Canciones);
};

int duracion (const albumCanciones &a) {
    return a.duracionTotal;
};

string tituloDeAlbum (const albumCanciones &a) {
    return a.tituloAlbum;
};

bool existeCancion (const albumCanciones &a, string s) {
    return existe(a.Canciones, s);
};

void obtenerCancion (const albumCanciones &a, string s, Cancion &c, bool &error) {
    obtenerDato(a.Canciones, s, c, error);
};

void anyadirCancion (albumCanciones &a, string s, const Cancion &c) {
    introducir(a.Canciones, s, c);
    a.duracionTotal = tamanyoTotal(a.Canciones);
};

void eliminarCancion (albumCanciones &a, int puesto) {
    eliminarXPuesto(a.Canciones, puesto);
    a.duracionTotal = tamanyoTotal(a.Canciones);
};

void puestodeCancion (const albumCanciones &a, string s, int &puesto, bool &error) {
    puestoDeClave(a.Canciones, s, puesto, error);
};

void canciondePuesto (const albumCanciones &a, int puesto, string &clave, bool &error) {
    obtenerXPuesto(a.Canciones, puesto, clave, error);
};

void intercambiarCanciones (albumCanciones &a, string s, string b) {
    int puestos, puestob;
    bool errors, errorb;

    puestoDeClave(a.Canciones,s,puestos,errors);
    puestoDeClave(a.Canciones,b,puestob,errorb);

    if (!errors && !errorb) {
        if (puestos > puestob) {
            recolocarEnPuesto(a.Canciones, s, puestob - puestos);
            recolocarEnPuesto(a.Canciones, b, puestos - puestob -1);
        }
        else {
            recolocarEnPuesto(a.Canciones, b, puestos - puestob);
            recolocarEnPuesto(a.Canciones, s, puestob - puestos -1);
        }
    }
};

string listarAlbum (albumCanciones &a) {
    iniciarIterador(a.Canciones);
    string clave;
    Cancion dato;
    bool error;
    int puesto;
    string respuesta = "";

    while (existeSiguiente(a.Canciones)) {
        siguienteClave(a.Canciones, clave, error);
        siguienteDato(a.Canciones, dato, error);
        puestoDeClave(a.Canciones, clave, puesto, error); // error = false
        respuesta += to_string(puesto) + ") " + to_string(clave) + ":::" + "<* "+
                    to_string(dato) + "*>" + '\n';

        avanza(a.Canciones,error); // error = false
    }
    return respuesta;
};

