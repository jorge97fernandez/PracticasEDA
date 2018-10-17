//
// Created by jorge on 04/10/2018.
//
#include "cancion.h"

Cancion crear(string nombreC, string nombreA, int anyo, int duracion){
    Cancion c;
    c.nombreCanc=nombreC;
    c.nombreAut=nombreA;
    c.anyoComp=anyo;
    c.durac=duracion;
    return c;
}
string nombreCancion(Cancion& c){
    return c.nombreCanc;
}
string nombreAutor (Cancion& c){
    return c.nombreAut;
}
int anyoComposicion(Cancion& c){
    return c.anyoComp;
}
int duracion(Cancion& c){
    return c.durac;
}
string generaCadena(Cancion&c){
    return c.nombreCanc + " --- " + c.nombreAut + " --- "
    + to_string(c.anyoComp) + " ( " + to_string(c.durac)+ " )";
}

