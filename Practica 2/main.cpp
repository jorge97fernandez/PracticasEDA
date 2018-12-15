#include <iostream>
#include "repertorio.h"

using namespace std;

void pruebas1() {
    coleccionConMarca<int,int> c;
    crear(c);
    int i1=5,j1=2;
    int i2=8,j2=2;
    int i3=3,j3=2;
    int i4=9,j4=2;
    int i5=4,j5=2;
    int i6=7,j6=2;
    int i7=6,j7=2;
    int i8=10,j8=2;
    int i9=2,j9=2;
    int i10=1,j10=2;
    cout << "true" <<endl;
    anyadir(c,i1,j1);
    cout << "doble true" <<endl;
    anyadir(c,i2,j2);
    anyadir(c,i3,j3);
    anyadir(c,i4,j4);
    anyadir(c,i5,j5);
    anyadir(c,i6,j6);
    anyadir(c,i7,j7);
    anyadir(c,i8,j8);
    anyadir(c,i9,j9);
    anyadir(c,i10,j10);
    cout << cardinal(c) << endl;
    cout <<boolalpha << esVacio(c) << endl;
    iniciarIterador(c);
    while(existeSiguiente(c)){
        int sig;
        bool error;
        siguienteClave(c,sig,error);
        cout << sig << endl;
        avanza(c,error);
    }
}

void pruebas2() {
    coleccionConMarca<int,int> c;
    crear(c);
    bool r = esVacio(c);

    int claves[10];
    int valores[10];
    for (int i = 0; i < 10; ++i) {
        claves[i] = i;
        valores[i] = i*5;
        anyadir(c, claves[i], valores[i]);
    }

    anyadir(c, claves[0], valores[1]);
    anyadir(c, claves[9], valores[1]);
    quitar(c, claves[0]);
    quitar(c, claves[9]);
    anyadir(c, claves[0], valores[0]);
    quitar(c, claves[1]);
    anyadir(c, claves[1], valores[1]);
    cambiarMarca(c, claves[0]);
    r = esVacio(c);
    int s = cardinal(c);
    s = cardinalConMarca(c);
    r = pertenece(c, claves[0]);
    r = pertenece(c, claves[9]);
    obtenerValor(c, claves[0], s, r);
    obtenerValor(c, claves[9], s, r);
    bool m = obtenerMarca(c, claves[0], r);
    m = obtenerMarca(c, claves[9], r);
    m = obtenerMarca(c, claves[1], r);
    quitar(c, claves[0]);
    anyadir(c, claves[0], valores[1]);
    m = obtenerMarca(c, claves[0], r);

    quitar(c, claves[3]);
    anyadir(c, claves[3], valores[3]);
    quitar(c, claves[4]);
    anyadir(c, claves[4], valores[4]);
    quitar(c, claves[3]);
    anyadir(c, claves[3], valores[3]);
    quitar(c, claves[5]);
    anyadir(c, claves[5], valores[5]);

    // Iterador:
    m = existeSiguiente(c);
    iniciarIterador(c);
    avanza(c, r);
    iniciarIterador(c);
    m = existeSiguiente(c);
    siguienteClave(c, s, r);
    m = siguienteMarca(c, r);
    siguienteValor(c, s, r);

    while (existeSiguiente(c)) {
        avanza(c, r);
    }
    avanza(c, r);
}

void pruebas3() {
    Pila<int> p;
    crear(p);
    bool b = esVacio(p);
    int c = 5555;
    cima(p, c, b);
    desapilar(p, b);

    for (int i = 0; i < 10; ++i) {
        apilar(p, i);
    }

    cima(p, c, b);
    b = esVacio(p);
    desapilar(p, b);
    cima(p, c, b);

    for (int i = 0; i < 9; ++i) {
        desapilar(p, b);
    }
}

void pruebas4() {
    repertorio r;
    crear(r, "repo");
    Cancion valor[5];
    string clave[5];
    for (int i = 0; i < 5; ++i) {
        clave[i] = to_string(i);
        valor[i] = crear(clave[i], to_string(i*5), i*2, i);
        anyadir(r, clave[i], valor[i]);
    }
    modificarEscuchada(r, clave[1], true);
    cout << listarRepertorio(r);
}

int main() {
    // Pruebas coleccion
    //pruebas1();
    //pruebas2();
    //pruebas3();

    // Pruebas repertorio
    pruebas4();
    return 0;
}