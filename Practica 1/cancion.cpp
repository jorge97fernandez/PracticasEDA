//**********************************************************************************************************************
// Archivo: cancion.cpp
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   4 Noviembre 2018
// Coms:    EDA - Práctica 1 - TAD Cancion
//**********************************************************************************************************************
#include "cancion.h"

Cancion crear(string nombreC, string nombreA, int anyo, int duracion){
    Cancion c;
    c.nombreCanc=nombreC;
    c.nombreAut=nombreA;
    c.anyoComp=anyo;
    c.durac=duracion;
    return c;
}
string nombreCancion(const Cancion& c){
    return c.nombreCanc;
}
string nombreAutor (const Cancion& c){
    return c.nombreAut;
}
int anyoComposicion(const Cancion& c){
    return c.anyoComp;
}
int duracion(const Cancion& c){
    return c.durac;
}
string generaCadena(const Cancion&c){
    return c.nombreCanc + " --- " + c.nombreAut + " --- "
           + to_string(c.anyoComp) + " ( " + to_string(c.durac)+ " )";
}
int tamanyo(const Cancion&c){
    return 8+ c.nombreAut.size() + c.nombreCanc.size();
}

