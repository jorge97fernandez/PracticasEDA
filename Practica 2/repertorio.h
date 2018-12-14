//**********************************************************************************************************************
// Archivo: coleccionConMarca.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD repertorio
//**********************************************************************************************************************

#ifndef REPERTORIO_H
#define REPERTORIO_H

#include <string>
#include "coleccionConMarca.h"
#include "cancion.h"
#include "string_lib.h"
using namespace std;
struct repertorio;
void crear(string titulo,repertorio &r);
string tituloRepertorio(repertorio &r);
bool existeCancion(repertorio &r, string &tCanc);
void anyadir();
void obtenerCancion();
bool escuchada();
void modificarEscuchada();
void quitarCancion();
int totalCanciones();
int totalCancionesEscuchadas();
void listarRepertorio();

struct repertorio{
    friend void crear(string titulo, repertorio &r);
    friend string tituloRepertorio(repertorio &r);
private:
    string titulo;
    coleccionConMarca<string,Cancion> canciones;

};

void crear(string titulo,repertorio &r){
    r.titulo = titulo;
    crear(r.canciones);
}

string tituloRepertorio(repertorio &r){
    return r.titulo;
}
#endif REPERTORIO_H