#include <iostream>
#include "coleccionConMarca.h"

using namespace std;

int main() {
    coleccionConMarca<int,int> c;
    crear(c);
    int i=1,j=2;
    anyadir(c,i,j);
    int c1=2;
    cout << pertenece(c,c1) <<endl;
    cout << cardinal(c) << endl;
    return 0;
}