#include "generico.h"
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
    //cout <<aux <<endl;
    aux = tamanyoTotal(r);
    //cout <<aux <<endl;
    b = existe(r, s);
    //cout <<b <<endl;
    introducir(r, s, c);
    aux = cardinal(r);
    //cout <<aux <<endl;
    aux = tamanyoTotal(r);
    //cout <<aux <<endl;
    Cancion d;
    obtenerDato(r, s, d, b);
    //cout <<generaCadena(d)<<endl;
    int puesto;
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
    //cout <<aux <<endl;
    puestoDeClave(r,s,puesto,b);
    //cout <<puesto <<endl;
    puestoDeClave(r,a,puesto,b);
    //cout <<puesto <<endl;
    string puesta;
    obtenerXPuesto(r,1,puesta,b);
    //cout<< generaCadena(puesta) <<endl;
    aux = tamanyoTotal(r);
    //eliminarXPuesto(r, 1);
    //eliminarXPuesto(r, 1);
    //aux = cardinal(r);
    //aux = tamanyoTotal(r);
    string cc = "ccc";
    Cancion c2 = crear("ccc", "ccc", 5, 6);
    introducir(r, cc, c2);
    obtenerXPuesto(r,1,puesta,b);
    cout<< generaCadena(puesta) <<endl;
    obtenerXPuesto(r,2,puesta,b);
    cout<< generaCadena(puesta) <<endl;
    obtenerXPuesto(r,3,puesta,b);
    cout<< generaCadena(puesta) <<endl;
    recolocarEnPuesto(r,s,2);
    obtenerXPuesto(r,1,puesta,b);
    cout<< generaCadena(puesta) <<endl;
    obtenerXPuesto(r,2,puesta,b);
    cout<< generaCadena(puesta) <<endl;
    obtenerXPuesto(r,3,puesta,b);
    cout<< generaCadena(puesta) <<endl;
    aux = cardinal(r);
    cout <<aux <<endl;

}