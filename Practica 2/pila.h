//**********************************************************************************************************************
// Archivo: pila.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD Pila
//**********************************************************************************************************************

#ifndef PILA_H
#define PILA_H

// Interfaz del TAD Pila. Pre-declaraciones:

/* Los valores del TAD representan valores ordenados siguiendo el estándar LIFO (último en entrar, primero en salir),
 * también conocido como pila.
 * El TAD incluye operaciones para crear, apilar, desapilar, obtener el valor en la cima (cima), y comprobar si está
 * vacía la pila (esVacio). */
template<typename T> struct Pila;

/* Devuelve una pila vacía, sin elementos. */
template<typename T> void crear (Pila<T> &l);

/* Devuelve una pila igual a la resultante de añadir valor a l. */
template<typename T> void apilar (Pila<T> &l, const T& valor);

/* Devuelve una pila igual a la resultante de eliminar de l el valor de la cima, y en error devuelve falso.
 * Parcial: se precisa que not esVacio(l); de lo contrario en error devuelve verdad. */
template<typename T> void desapilar (Pila<T> &l, bool &error);

/* Devuelve el valor de la cima de l en valor, y en error devuelve falso.
 * Parcial: se precisa que not esVacio(l); de lo contrario en error devuelve verdad. */
template<typename T> void cima (const Pila<T> &l, T &valor, bool &error);

/* Devuelve verdad si y sólo si l no tiene elementos. */
template<typename T> bool esVacio (const Pila<T> &l);

template<typename T>
struct Pila {
    friend void crear<T>  (Pila<T> &l);
    friend void apilar<T>  (Pila<T> &l, const T& valor);
    friend void desapilar<T>  (Pila<T> &l, bool &error);
    friend void cima<T>  (const Pila<T> &l, T &valor, bool &error);
    friend bool esVacio<T>  (const Pila<T> &l);

private:
    struct Nodo {
        T valor;
        Nodo *siguiente;
    };
    Nodo *dato; // Elemento en la cima
    int numDatos; // Número de elementos de la pila
};

/* Devuelve una pila vacía, sin elementos. */
template<typename T>
void crear (Pila<T> &l) {
    l.dato = nullptr;
    l.numDatos = 0;
};

/* Devuelve una pila igual a la resultante de añadir valor a l. */
template<typename T>
void apilar (Pila<T> &l, const T& valor) {
    typename Pila<T>::Nodo *aux = new typename Pila<T>::Nodo;
    aux->siguiente = l.dato;
    aux->valor = valor;
    l.dato = aux;
    l.numDatos++;
};

/* Devuelve una pila igual a la resultante de eliminar de l el valor de la cima, y en error devuelve falso.
 * Parcial: se precisa que not esVacio(l); de lo contrario en error devuelve verdad. */
template<typename T>
void desapilar (Pila<T> &l, bool &error) {
    if (!esVacio(l)) {
        typename Pila<T>::Nodo *aux = l.dato;
        l.dato = aux->siguiente;
        l.numDatos--;
        delete aux;
        error = false;
    }
    else {
        error = true;
    }
};

/* Devuelve el valor de la cima de l en valor, y en error devuelve falso.
 * Parcial: se precisa que not esVacio(l); de lo contrario en error devuelve verdad. */
template<typename T>
void cima (const Pila<T> &l, T &valor, bool &error) {
    if (!esVacio(l)) {
        valor = l.dato->valor;
        error = false;
    }
    else {
        error = true;
    }
};

/* Devuelve verdad si y sólo si l no tiene elementos. */
template<typename T>
bool esVacio (const Pila<T> &l) {
    return l.numDatos == 0;
};

#endif //PILA_H
