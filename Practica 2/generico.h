//
// Created by jorge on 05/10/2018.
//

#ifndef PRUEBA_H
#define PRUEBA_H

#include <string>
using namespace std;
string to_string(string s);
template <typename T>string generaCadena(T n){
    return to_string(n);
}
#endif