//**********************************************************************************************************************
// Archivo: coleccionConMarca.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD colecciónConMarca
//**********************************************************************************************************************

#ifndef COLECCIONCONMARCA_H
#define COLECCIONCONMARCA_H

#include "pila.h"


// Interfaz del TAD colecciónConMarca. Pre-declaraciones:

/* Los valores del TAD representan conjuntos de tripletas (clave, valor, booleano) en los que no se permiten claves
 * repetidas, y que cuentan con las operaciones de un iterador que permite recorrer los datos de la colecciónConMarca
 * según el orden por clave, de menor a mayor. El valor booleano de cada tripleta diremos que es la marca asociada a
 * la clave.
 *
 * El TAD que se use para la clave, debe tener definidas las siguientes operaciones:
 *    bool operator< (clave c1, clave c2) {Devuelve verdad si y sólo si c1 es menor que c2}
 *    bool operator== (clave c1, clave c2) {Devuelve verdad si y sólo si c1 es igual que c2} */
template<typename C, typename V> struct coleccionConMarca;

/* Devuelve una colecciónConMarca vacía, sin elementos (tripletas). */
template<typename C, typename V> void crear (coleccionConMarca<C,V> &d);

/* Si en d no hay ninguna tripleta con clave c, devuelve una colecciónConMarca igual a la resultante de añadir la
 * tripleta (c,v,falso) a d; si en d hay una tripleta (c,v',b), entonces devuelve una colecciónConMarca igual a la
 * resultante de sustituir (c,v',b) por (c,v,falso). */
template<typename C, typename V> void anyadir (coleccionConMarca<C,V> &d, const C &c, const V &v);

/* Devuelve verdad si y sólo si en d hay alguna tripleta (c,v,b). */
template<typename C, typename V> bool pertenece (const coleccionConMarca<C,V> &d, const C &c);

/* Devuelve el valor asociado a la clave c en d, y en error devuelve falso.
 * Parcial: se precisa que pertenece(d, c); de lo contrario en error devuelve verdad. */
template<typename C, typename V> void obtenerValor (const coleccionConMarca<C,V> &d, const C &c, V &v, bool &error);

/* Devuelve la marca asociada a la clave c en d, y en error devuelve falso.
 * Parcial: se precisa que pertenece(d, c); de lo contrario en error devuelve verdad. */
template<typename C, typename V> bool obtenerMarca (const coleccionConMarca<C,V> &d, const C &c, bool &error);

/* Si c está en d, devuelve una colecciónConMarca igual a la resultante de borrar en d la tripleta con clave c; si c no
 * está en d, devuelve una colecciónConMarca igual a d. */
template<typename C, typename V> void quitar (coleccionConMarca<C,V> &d, const C &c);

/* Devuelve el número de elementos (tripletas) en la colecciónConMarca d. */
template<typename C, typename V> int cardinal (const coleccionConMarca<C,V> &d);

/* Devuelve el número de elementos (tripletas) en la colecciónConMarca d cuya marca es igual a verdad. */
template<typename C, typename V> int cardinalConMarca (const coleccionConMarca<C,V> &d);

/* Si pertenece(d,c), existe una tripleta (c,v,m) en la colecciónConMarca d, y devuelve la colecciónConMarca resultante
 * de sustituir (c,v,m) por (c,v,(not m)). Si not pertenece(d,c), devuelve una colecciónConMarca igual a d. */
template<typename C, typename V> void cambiarMarca (coleccionConMarca<C,V> &d, const C &c);

/* Devuelve verdad si y sólo si d no tiene elementos. */
template<typename C, typename V> bool esVacio (const coleccionConMarca<C,V> &d);


// Operaciones del iterador interno, para recorrer los datos de la colecciónConMarca en orden por clave de menor a mayor

/* Prepara el iterador y su cursor para que el siguiente elemento (tripleta) a visitar sea el primero de la
 * colecciónConMarca d (situación de no haber visitado ningún elemento). */
template<typename C, typename V> void iniciarIterador (coleccionConMarca<C,V> &d);

/* Devuelve falso si ya se ha visitado el último elemento. Devuelve verdad en caso contrario. */
template<typename C, typename V> bool existeSiguiente (const coleccionConMarca<C,V> &d);

/* Devuelve la clave del siguiente elemento (tripleta) de d, y en error devuelve falso.
 * Parcial: se precisa que existeSiguiente(d); de lo contrario en error devuelve verdad. */
template<typename C, typename V> void siguienteClave (const coleccionConMarca<C,V> &d, C &c, bool &error);

/* Devuelve el valor del siguiente elemento (tripleta) de d, y en error devuelve falso.
 * Parcial: se precisa que existeSiguiente(d); de lo contrario en error devuelve verdad. */
template<typename C, typename V> void siguienteValor (const coleccionConMarca<C,V> &d, V &v, bool &error);

/* Devuelve la marca del siguiente elemento (tripleta) de d, y en error devuelve falso.
 * Parcial: se precisa que existeSiguiente(d); de lo contrario en error devuelve verdad. */
template<typename C, typename V> bool siguienteMarca (const coleccionConMarca<C,V> &d, bool &error);

/* Devuelve la colecciónConMarca resultante de avanzar el cursor en d, y en error devuelve falso.
 * Parcial: se precisa que existeSiguiente(d); de lo contrario en error devuelve verdad. */
template<typename C, typename V> void avanza (coleccionConMarca<C,V> &d, bool &error);


// Funciones auxiliares:

/* a apunta a la raiz de una colecciónConMarca d, si en d no hay ninguna tripleta con clave c, devuelve una
 * colecciónConMarca igual a la resultante de añadir la tripleta (c,v,falso) a d, y el resultado es 0; si en d hay una
 * tripleta (c,v',b), entonces devuelve una colecciónConMarca igual a la resultante de sustituir (c,v',b) por
 * (c,v,falso), y si b era verdad, el resultado es 1, pero si era falso, el resultado es 2. */
template<typename C, typename V> char anyadir_aux (typename coleccionConMarca<C,V>::Nodo* &a, const C &c, const V &v);

/* a apunta a la raiz de una colecciónConMarca d, y devuelve verdad si y sólo si en d hay alguna tripleta (c,v,b). */
template<typename C, typename V> bool pertenece_aux (const typename coleccionConMarca<C,V>::Nodo* const &a, const C &c);

/* a apunta a la raiz de una colecciónConMarca d, devuelve el valor asociado a la clave c en d, y en error devuelve
 * falso.
 * Parcial: se precisa que pertenece(d, c); de lo contrario en error devuelve verdad. */
template<typename C, typename V> void obtenerValor_aux (const typename coleccionConMarca<C,V>::Nodo* const &a,
                                                            const C &c, V &v, bool &error);

/* a apunta a la raiz de una colecciónConMarca d, devuelve la marca asociada a la clave c en d, y en error devuelve
 * falso.
 * Parcial: se precisa que pertenece(d, c); de lo contrario en error devuelve verdad. */
template<typename C, typename V> bool obtenerMarca_aux (const typename coleccionConMarca<C,V>::Nodo* const &a,
                                                            const C &c, bool &error);

/* a apunta a la raiz de una colecciónConMarca d, si c está en d, devuelve una colecciónConMarca igual a la resultante
 * de borrar en d la tripleta con clave c, y si su marca es verdad, el resultado es 1, pero si es falso, el resultado es
 * 2; si c no está en d, devuelve una colecciónConMarca igual a d y el resultado es 0. */
template<typename C, typename V> char quitar_aux (typename coleccionConMarca<C,V>::Nodo* &a, const C &c);

/* a apunta a la raiz de una colecciónConMarca d, devuelve en c el la clave mayor de d.
 * Precondición: not esVacio(d) */
template<typename C, typename V> void max (const typename coleccionConMarca<C,V>::Nodo* const &a, C &c);

/* a apunta a la raiz de una colecciónConMarca d, si pertenece(d,c), existe una tripleta (c,v,m) en la colecciónConMarca
 * d, y devuelve la colecciónConMarca resultante de sustituir (c,v,m) por (c,v,(not m)) y si m es verdad, el resultado
 * es 1, pero si es falso, el resultado es 2. Si not pertenece(d,c), devuelve una colecciónConMarca igual a d, y el
 * resultado es 0. */
template<typename C, typename V> char cambiarMarca_aux (typename coleccionConMarca<C,V>::Nodo* &a, const C &c);


// Declaración:

template<typename C, typename V>
struct coleccionConMarca {
    friend void crear<C,V> (coleccionConMarca<C,V> &d);
    friend void anyadir<C,V> (coleccionConMarca<C,V> &d, const C &c, const V &v);
    friend bool pertenece<C,V> (const coleccionConMarca<C,V> &d, const C &c);
    friend void obtenerValor<C,V> (const coleccionConMarca<C,V> &d, const C &c, V &v, bool &error);
    friend bool obtenerMarca<C,V> (const coleccionConMarca<C,V> &d, const C &c, bool &error);
    friend void quitar<C,V> (coleccionConMarca<C,V> &d, const C &c);
    friend int cardinal<C,V> (const coleccionConMarca<C,V> &d);
    friend int cardinalConMarca<C,V> (const coleccionConMarca<C,V> &d);
    friend void cambiarMarca<C,V> (coleccionConMarca<C,V> &d, const C &c);
    friend bool esVacio<C,V> (const coleccionConMarca<C,V> &d);
    friend void iniciarIterador<C,V> (coleccionConMarca<C,V> &d);
    friend bool existeSiguiente<C,V> (const coleccionConMarca<C,V> &d);
    friend void siguienteClave<C,V> (const coleccionConMarca<C,V> &d, C &c, bool &error);
    friend void siguienteValor<C,V> (const coleccionConMarca<C,V> &d, V &v, bool &error);
    friend bool siguienteMarca<C,V> (const coleccionConMarca<C,V> &d, bool &error);
    friend void avanza<C,V> (coleccionConMarca<C,V> &d, bool &error);

private:
    /* El TAD colecciónConMarca se ha implementado como un árbol binario de búsqueda (ABB) dinámico. */
    struct Nodo {
        C c; // clave
        V v; // valor
        bool m; // marca
        Nodo *izq; // Nodo hijo izquierdo
        Nodo *der; // Nodo hijo derecho
    };
    Nodo *raiz;
    int num; // cardinal
    int numMarca; // cardinalConMarca

    // Iterador interno, para recorrer los datos de la colecciónConMarca en orden por clave de menor a mayor (in-orden)
    Nodo *iterador;
    Pila<Nodo*> pilaIteracion;

    // Funciones auxiliares
    friend char anyadir_aux<C,V> (typename coleccionConMarca<C,V>::Nodo* &a, const C &c, const V &v);
    friend bool pertenece_aux<C,V> (const typename coleccionConMarca<C,V>::Nodo* const &a, const C &c);
    friend void obtenerValor_aux<C,V> (const typename coleccionConMarca<C,V>::Nodo* const &a, const C &c, V &v,
                                            bool &error);
    friend bool obtenerMarca_aux<C,V> (const typename coleccionConMarca<C,V>::Nodo* const &a, const C &c, bool &error);
    friend char quitar_aux<C,V> (typename coleccionConMarca<C,V>::Nodo* &a, const C &c);
    friend void max<C,V> (const typename coleccionConMarca<C,V>::Nodo* const &a, C &c);
    friend char cambiarMarca_aux<C,V> (typename coleccionConMarca<C,V>::Nodo* &a, const C &c);
};


// Implementación del TAD colecciónConMarca:

/* Devuelve una colecciónConMarca vacía, sin elementos (tripletas). */
template<typename C, typename V>
void crear (coleccionConMarca<C,V> &d) {
    d.raiz = nullptr;
    d.num = 0;
    d.numMarca = 0;
    d.iterador = nullptr;
    crear(d.pilaIteracion);
};

/* Si en d no hay ninguna tripleta con clave c, devuelve una colecciónConMarca igual a la resultante de añadir la
 * tripleta (c,v,falso) a d; si en d hay una tripleta (c,v',b), entonces devuelve una colecciónConMarca igual a la
 * resultante de sustituir (c,v',b) por (c,v,falso). */
template<typename C, typename V>
void anyadir (coleccionConMarca<C,V> &d, const C &c, const V &v) {
    char anyadido = anyadir_aux<C,V>(d.raiz, c, v);
    if (anyadido == 0) {
        d.num++;
    }
    else if (anyadido == 1) {
        d.numMarca--;
    }
};

/* a apunta a la raiz de una colecciónConMarca d, si en d no hay ninguna tripleta con clave c, devuelve una
 * colecciónConMarca igual a la resultante de añadir la tripleta (c,v,falso) a d, y el resultado es 0; si en d hay una
 * tripleta (c,v',b), entonces devuelve una colecciónConMarca igual a la resultante de sustituir (c,v',b) por
 * (c,v,falso), y si b era verdad, el resultado es 1, pero si era falso, el resultado es 2. */
template<typename C, typename V>
char anyadir_aux (typename coleccionConMarca<C,V>::Nodo* &a, const C &c, const V &v) {
    if (a == nullptr) {
        // Se añade un nodo nuevo ya que no existe un nodo con clave c
        a = new typename coleccionConMarca<C,V>::Nodo;
        a->c = c;
        a->v = v;
        a->m = false;
        a->izq = nullptr;
        a->der = nullptr;
        return 0;
    }
    else {
        if (c == a->c) {
            // Ya existe un nodo con clave c
            a->v = v;

            if (a->m) {
                // Se restablece la marca
                a->m = false;
                return 1;
            }
            else {
                return 2;
            }
        }
        else if (c < a->c) {
            anyadir_aux<C,V>(a->izq, c, v);
        }
        else {
            anyadir_aux<C,V>(a->der, c, v);
        }
    }
};

/* Devuelve verdad si y sólo si en d hay alguna tripleta (c,v,b). */
template<typename C, typename V>
bool pertenece (const coleccionConMarca<C,V> &d, const C &c) {
    return pertenece_aux<C,V>(d.raiz, c);
};

/* a apunta a la raiz de una colecciónConMarca d, y devuelve verdad si y sólo si en d hay alguna tripleta (c,v,b). */
template<typename C, typename V>
bool pertenece_aux (const typename coleccionConMarca<C,V>::Nodo* const &a, const C &c) {
    if (a == nullptr) {
        // No existe un nodo con clave c
        return false;
    }
    else {
        if (c == a->c) {
            // Existe un nodo con clave c
            return true;
        }
        else if (c < a->c) {
            pertenece_aux<C,V>(a->izq, c);
        }
        else {
            pertenece_aux<C,V>(a->der, c);
        }
    }
};

/* Devuelve el valor asociado a la clave c en d, y en error devuelve falso.
 * Parcial: se precisa que pertenece(d, c); de lo contrario en error devuelve verdad. */
template<typename C, typename V>
void obtenerValor (const coleccionConMarca<C,V> &d, const C &c, V &v, bool &error) {
    obtenerValor_aux<C,V>(d.raiz, c, v, error);
};

/* a apunta a la raiz de una colecciónConMarca d, devuelve el valor asociado a la clave c en d, y en error devuelve
 * falso.
 * Parcial: se precisa que pertenece(d, c); de lo contrario en error devuelve verdad. */
template<typename C, typename V>
void obtenerValor_aux (const typename coleccionConMarca<C,V>::Nodo* const &a, const C &c, V &v, bool &error) {
    if (a == nullptr) {
        // No existe un nodo con clave c
        error = true;
    }
    else {
        if (c == a->c) {
            // Existe un nodo con clave c
            error = false;
            v = a->v;
        }
        else if (c < a->c) {
            obtenerValor_aux<C,V>(a->izq, c, v, error);
        }
        else {
            obtenerValor_aux<C,V>(a->der, c, v, error);
        }
    }
};

/* Devuelve la marca asociada a la clave c en d, y en error devuelve falso.
 * Parcial: se precisa que pertenece(d, c); de lo contrario en error devuelve verdad. */
template<typename C, typename V>
bool obtenerMarca (const coleccionConMarca<C,V> &d, const C &c, bool &error) {
    return obtenerMarca_aux<C,V>(d.raiz, c, error);
};

/* a apunta a la raiz de una colecciónConMarca d, devuelve la marca asociada a la clave c en d, y en error devuelve
 * falso.
 * Parcial: se precisa que pertenece(d, c); de lo contrario en error devuelve verdad. */
template<typename C, typename V>
bool obtenerMarca_aux (const typename coleccionConMarca<C,V>::Nodo* const &a, const C &c, bool &error) {
    if (a == nullptr) {
        // No existe un nodo con clave c
        error = true;
        return false;
    }
    else {
        if (c == a->c) {
            // Existe un nodo con clave c
            error = false;
            return a->m;
        }
        else if (c < a->c) {
            obtenerMarca_aux<C,V>(a->izq, c, error);
        }
        else {
            obtenerMarca_aux<C,V>(a->der, c, error);
        }
    }
};

/* Si c está en d, devuelve una colecciónConMarca igual a la resultante de borrar en d la tripleta con clave c; si c no
 * está en d, devuelve una colecciónConMarca igual a d. */
template<typename C, typename V>
void quitar (coleccionConMarca<C,V> &d, const C &c) {
    char resul = quitar_aux<C,V>(d.raiz, c);
    if (resul == 1) {
        d.num--;
        d.numMarca--;
    }
    else if (resul == 2) {
        d.num--;
    }
};

/* a apunta a la raiz de una colecciónConMarca d, si c está en d, devuelve una colecciónConMarca igual a la resultante
 * de borrar en d la tripleta con clave c, y si su marca es verdad, el resultado es 1, pero si es falso, el resultado es
 * 2; si c no está en d, devuelve una colecciónConMarca igual a d y el resultado es 0. */
template<typename C, typename V>
char quitar_aux (typename coleccionConMarca<C,V>::Nodo* &a, const C &c) {
    if (a == nullptr) {
        return 0;
    }
    else {
        if (c == a->c) {
            // Existe un nodo con clave c
            if (a->izq == nullptr) {
                typename coleccionConMarca<C,V>::Nodo *aux = a;
                a = a->der;

                char resul;
                if (aux->m) {
                    // Tiene marca
                    resul = 1;
                }
                else {
                    resul = 2;
                }

                delete aux;
                return resul;
            }
            else {
                max<C,V>(a->izq, a->c);
                quitar_aux<C,V>(a->izq, a->c);
            }
        }
        else if (c < a->c) {
            quitar_aux<C,V>(a->izq, c);
        }
        else {
            quitar_aux<C,V>(a->der, c);
        }
    }
};

/* a apunta a la raiz de una colecciónConMarca d, devuelve en c el la clave mayor de d.
 * Precondición: not esVacio(d) */
template<typename C, typename V>
void max (const typename coleccionConMarca<C,V>::Nodo* const &a, C &c) {
    if (a->der == nullptr) {
        c = a->c;
    }
    else {
        max<C,V>(a->der, c);
    }
};

/* Devuelve el número de elementos (tripletas) en la colecciónConMarca d. */
template<typename C, typename V>
int cardinal (const coleccionConMarca<C,V> &d) {
    return d.num;
};

/* Devuelve el número de elementos (tripletas) en la colecciónConMarca d cuya marca es igual a verdad. */
template<typename C, typename V>
int cardinalConMarca (const coleccionConMarca<C,V> &d) {
    return d.numMarca;
};

/* Si pertenece(d,c), existe una tripleta (c,v,m) en la colecciónConMarca d, y devuelve la colecciónConMarca resultante
 * de sustituir (c,v,m) por (c,v,(not m)). Si not pertenece(d,c), devuelve una colecciónConMarca igual a d. */
template<typename C, typename V>
void cambiarMarca (coleccionConMarca<C,V> &d, const C &c) {
    char resul = cambiarMarca_aux<C,V>(d.raiz, c);
    if (resul == 1) {
        d.numMarca--;
    }
    else if (resul == 2) {
        d.numMarca++;
    }
};

/* a apunta a la raiz de una colecciónConMarca d, si pertenece(d,c), existe una tripleta (c,v,m) en la colecciónConMarca
 * d, y devuelve la colecciónConMarca resultante de sustituir (c,v,m) por (c,v,(not m)) y si m es verdad, el resultado
 * es 1, pero si es falso, el resultado es 2. Si not pertenece(d,c), devuelve una colecciónConMarca igual a d, y el
 * resultado es 0. */
template<typename C, typename V>
char cambiarMarca_aux (typename coleccionConMarca<C,V>::Nodo* &a, const C &c) {
    if (a == nullptr) {
        // No existe un nodo con clave c
        return 0;
    }
    else {
        if (c == a->c) {
            // Existe un nodo con clave c
            if (a->m) {
                a->m = false;
                return 1;
            }
            else {
                a->m = true;
                return 2;
            }
        }
        else if (c < a->c) {
            cambiarMarca_aux<C,V>(a->izq, c);
        }
        else {
            cambiarMarca_aux<C,V>(a->der, c);
        }
    }
};

/* Devuelve verdad si y sólo si d no tiene elementos. */
template<typename C, typename V>
bool esVacio (const coleccionConMarca<C,V> &d) {
    return d.num == 0;
};

/* Prepara el iterador y su cursor para que el siguiente elemento (tripleta) a visitar sea el primero de la
 * colecciónConMarca d (situación de no haber visitado ningún elemento). */
template<typename C, typename V>
void iniciarIterador (coleccionConMarca<C,V> &d) {
    bool error;
    while (!esVacio(d.pilaIteracion)) {
        desapilar(d.pilaIteracion, error);
    }

    d.iterador = d.raiz;
    while (d.iterador->izq != nullptr) {
        apilar(d.pilaIteracion, d.iterador);
        d.iterador = d.iterador->izq;
    }
};

/* Devuelve falso si ya se ha visitado el último elemento. Devuelve verdad en caso contrario. */
template<typename C, typename V>
bool existeSiguiente (const coleccionConMarca<C,V> &d) {
    return d.iterador != nullptr;
};

/* Devuelve la clave del siguiente elemento (tripleta) de d, y en error devuelve falso.
 * Parcial: se precisa que existeSiguiente(d); de lo contrario en error devuelve verdad. */
template<typename C, typename V>
void siguienteClave (const coleccionConMarca<C,V> &d, C &c, bool &error) {
    if (existeSiguiente(d)) {
        c = d.iterador->c;
        error = false;
    }
    else {
        error = true;
    }
};

/* Devuelve el valor del siguiente elemento (tripleta) de d, y en error devuelve falso.
 * Parcial: se precisa que existeSiguiente(d); de lo contrario en error devuelve verdad. */
template<typename C, typename V>
void siguienteValor (const coleccionConMarca<C,V> &d, V &v, bool &error) {
    if (existeSiguiente(d)) {
        v = d.iterador->v;
        error = false;
    }
    else {
        error = true;
    }
};

/* Devuelve la marca del siguiente elemento (tripleta) de d, y en error devuelve falso.
 * Parcial: se precisa que existeSiguiente(d); de lo contrario en error devuelve verdad. */
template<typename C, typename V>
bool siguienteMarca (const coleccionConMarca<C,V> &d, bool &error) {
    if (existeSiguiente(d)) {
        error = false;
        return d.iterador->m;
    }
    else {
        error = true;
        return false;
    }
};

/* Devuelve la colecciónConMarca resultante de avanzar el cursor en d, y en error devuelve falso.
 * Parcial: se precisa que existeSiguiente(d); de lo contrario en error devuelve verdad. */
template<typename C, typename V>
void avanza (coleccionConMarca<C,V> &d, bool &error) { // Recorrido en in-orden
    if (existeSiguiente(d)) {
        if (d.iterador->der != nullptr) {
            d.iterador = d.iterador->der;
            while (d.iterador->izq != nullptr) {
                apilar(d.pilaIteracion, d.iterador);
                d.iterador = d.iterador->izq;
            }
        }

        else if (!esVacio(d.pilaIteracion)) {
            cima(d.pilaIteracion, d.iterador, error);
            desapilar(d.pilaIteracion, error);
        }

        else {
            d.iterador = nullptr;
        }

        error = false;
    }
    else {
        error = true;
    }
};

#endif // fin de coleccionConMarca.h
