#include <iostream>
#include "coleccionConMarca.h"

using namespace std;

int main() {
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
    return 0;
}