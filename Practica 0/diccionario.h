//
// Created by jorge on 05/10/2018.
//

#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <string>

#define LIMIT 100

using namespace std;

template <typename C, typename V> struct Diccionario;
template <typename C, typename V> void crear(Diccionario<C,V> & d);
template <typename C, typename V> bool existe(const Diccionario<C,V> & d, C clave);
template <typename C, typename V> void introducir (Diccionario<C,V> & d, C clave, V valor);
template <typename C, typename V> bool obtenerDato (const Diccionario<C,V> & d, C clave, V & valor);
template <typename C, typename V> void borrar (Diccionario<C,V> & d,C clave);
template <typename C, typename V> int cardinal(const Diccionario<C,V> & d);
template <typename C, typename V> string listar (const Diccionario<C,V> & d);
template <typename C, typename V> void iniciarIterador(Diccionario<C,V> & d);
template <typename C, typename V> bool existeSiguiente(const Diccionario<C,V> & d);
template <typename C, typename V> bool siguienteClave(Diccionario<C,V> & d, C & clave);
template <typename C, typename V> bool siguienteDato(Diccionario<C,V> & d, V & dato);
template <typename C, typename V> bool avanza(Diccionario<C,V> & d);


template <typename C, typename V> struct Diccionario{
    friend void crear<C,V>(Diccionario & d);
    friend bool existe<C,V>(const Diccionario & d, C clave);
    friend void introducir<C,V>(Diccionario & d,C clave,V valor);
    friend bool obtenerDato<C,V>(const Diccionario & d,C clave, V & valor);
    friend void borrar<C,V>(Diccionario & d,C clave);
    friend int cardinal<C,V>(const Diccionario & d);
    friend string listar<C,V>(const Diccionario & d);
    friend void iniciarIterador<C,V>(Diccionario & d);
    friend bool existeSiguiente<C,V>(const Diccionario & d);
    friend bool siguienteClave<C,V>(Diccionario & d, C & clave);
    friend bool siguienteDato<C,V>(Diccionario & d, V & dato);
    friend bool avanza<C,V>(Diccionario & d);

private:
    struct Pares{
        C clave;
        V dato;
    };
    Pares datos[LIMIT];
    int numPares;
    int iterador;
};


#endif
