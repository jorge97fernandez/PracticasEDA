//
// Created by jorge on 04/10/2018.
//

#ifndef CANCION_H
#define CANCION_H
#include <string>

using namespace std;

struct Cancion;
Cancion crear(string nombreC, string nombreA, int anyo, int duracion);
string nombreCancion(Cancion& c);
string nombreAutor (Cancion& c);
int anyoComposicion(Cancion& c);
int duracion(Cancion& c);
string generaCadena(Cancion&c);
int tamanyo(Cancion&c);

struct Cancion{
    friend Cancion crear(string nombreC, string nombreA, int anyo, int duracion);
    friend string nombreCancion(Cancion& c);
    friend string nombreAutor (Cancion& c);
    friend int anyoComposicion(Cancion& c);
    friend int duracion(Cancion& c);
    friend string generaCadena(Cancion&c);
    friend int tamanyo(Cancion&c);

private:
    string nombreCanc;
    string nombreAut;
    int anyoComp;
    int durac;
};
#endif
