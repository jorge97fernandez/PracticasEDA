//
// Created by andres on 30/10/18.
//

#include "recopilacion.h"
#include "cancion.h"
#include <iostream>

using namespace std;

int main () {
    Recopilacion<string, Cancion> r;
    string s = "ssss";
    Cancion c = crear("aaaa", "bbbb", 5, 6);
    bool b;
    int aux;
    crear(r);
    aux = cardinal(r);
    aux = tamanyoTotal(r);
    b = existe(r, s);
    introducir(r, s, c);
    aux = cardinal(r);
    aux = tamanyoTotal(r);
    Cancion d;
    obtenerDato(r, s, d, b);
    string a = "aa";
    obtenerDato(r, a, d, b);
    iniciarIterador(r);
    b = existeSiguiente(r);
    siguienteClave(r, a, b);
    avanza(r, b);
    b = existeSiguiente(r);
    siguienteClave(r, a, b);
    avanza(r, b);
    a = "aa";
    eliminarXPuesto(r, 5);
    eliminarXPuesto(r, 1);
    aux = cardinal(r);
    aux = tamanyoTotal(r);
    introducir(r, s, c);
    aux = cardinal(r);
    aux = tamanyoTotal(r);
    introducir(r, a, c);
    aux = cardinal(r);
    aux = tamanyoTotal(r);
    eliminarXPuesto(r, 1);
    eliminarXPuesto(r, 1);
    aux = cardinal(r);
    aux = tamanyoTotal(r);

}