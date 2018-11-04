//**********************************************************************************************************************
// Archivo: cancion.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   4 Noviembre 2018
// Coms:    EDA - Práctica 1 - TAD Cancion
//**********************************************************************************************************************

#ifndef CANCION_H
#define CANCION_H
#include <string>

using namespace std;

struct Cancion;
Cancion crear(string nombreC, string nombreA, int anyo, int duracion);
string nombreCancion(const Cancion& c);
string nombreAutor (const Cancion& c);
int anyoComposicion(const Cancion& c);
int duracion(const Cancion& c);
string generaCadena(const Cancion&c);
int tamanyo(const Cancion&c);

struct Cancion{
    friend Cancion crear(string nombreC, string nombreA, int anyo, int duracion);
    friend string nombreCancion(const Cancion& c);
    friend string nombreAutor (const Cancion& c);
    friend int anyoComposicion(const Cancion& c);
    friend int duracion(const Cancion& c);
    friend string generaCadena(const Cancion&c);
    friend int tamanyo(const Cancion&c);

private:
    string nombreCanc;
    string nombreAut;
    int anyoComp;
    int durac;
};
#endif
