//**********************************************************************************************************************
// Archivo: coleccionConMarca.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD colecciónConMarca
//**********************************************************************************************************************

#ifndef COLECCIONCONMARCA_H
#define COLECCIONCONMARCA_H


// Interfaz del TAD colecciónConMarca. Pre-declaraciones:

/* Los valores del TAD representan ... TODO
 *
 * El TAD que se use para la clave, debe tener definidas las siguientes operaciones:
 *    bool operator< (clave c1, clave c2) {Devuelve verdad si y sólo si c1 es menor que c2}
 */
template<typename C, typename V> struct coleccionConMarca;

/* Devuelve una colecciónConMarca vacía, sin elementos (tripletas). */
template<typename C, typename V> void crear (coleccionConMarca<C,V> &d);

template<typename C, typename V> void anyadir (coleccionConMarca<C,V> &d, const C &c, const V &v);

template<typename C, typename V> bool pertenece (const coleccionConMarca<C,V> &d, const C &c);

template<typename C, typename V> void obtenerValor (const coleccionConMarca<C,V> &d, const C &c, V &v, bool &error);

template<typename C, typename V> bool obtenerMarca (const coleccionConMarca<C,V> &d, const C &c, bool &error);

template<typename C, typename V> void quitar (coleccionConMarca<C,V> &d, const C &c);

template<typename C, typename V> int cardinal (const coleccionConMarca<C,V> &d);

template<typename C, typename V> int cardinalConMarca (const coleccionConMarca<C,V> &d);

template<typename C, typename V> void cambiarMarca (coleccionConMarca<C,V> &d, const C &c);

template<typename C, typename V> bool esVacio (const coleccionConMarca<C,V> &d);

template<typename C, typename V> void iniciarIterador (coleccionConMarca<C,V> &d);

template<typename C, typename V> bool existeSiguiente (const coleccionConMarca<C,V> &d);

template<typename C, typename V> void siguienteClave (const coleccionConMarca<C,V> &d, C &c, bool &error);

template<typename C, typename V> void siguienteValor (const coleccionConMarca<C,V> &d, V &v, bool &error);

template<typename C, typename V> bool siguienteMarca (const coleccionConMarca<C,V> &d, bool &error);

template<typename C, typename V> void avanza (coleccionConMarca<C,V> &d, bool &error);

//Funciones auxiliares:
template<typename C, typename V> char anyadir_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c, const V &v);

template<typename C, typename V> bool pertenece_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c);

template<typename C, typename V> void obtenerValor_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c, V &v, bool &error);

template<typename C, typename V> bool obtenerMarca_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c, bool &error);

template<typename C, typename V> char quitar_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c);

template<typename C, typename V> void max (typename coleccionConMarca<C,V>::Nodo *a, C &c);

template<typename C, typename V> char cambiarMarca_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c);


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

    Nodo *iterador;

    // Funciones auxiliares
    friend char anyadir_aux<C,V> (typename coleccionConMarca<C,V>::Nodo *a, const C &c, const V &v);
    friend bool pertenece_aux<C,V> (typename coleccionConMarca<C,V>::Nodo *a, const C &c);
    friend void obtenerValor_aux<C,V> (typename coleccionConMarca<C,V>::Nodo *a, const C &c, V &v, bool &error);
    friend bool obtenerMarca_aux<C,V> (typename coleccionConMarca<C,V>::Nodo *a, const C &c, bool &error);
    friend char quitar_aux<C,V> (typename coleccionConMarca<C,V>::Nodo *a, const C &c);
    friend void max<C,V> (typename coleccionConMarca<C,V>::Nodo *a, C &c);
    friend char cambiarMarca_aux<C,V> (typename coleccionConMarca<C,V>::Nodo *a, const C &c);
};


// Implementación del TAD colecciónConMarca:

/* Devuelve una colecciónConMarca vacía, sin elementos (tripletas). */
template<typename C, typename V>
void crear (coleccionConMarca<C,V> &d) {
    d.raiz = nullptr;
    d.num = 0;
    d.numMarca = 0;
    d.iterador = nullptr;
}; // O(1)

/* Si en d no hay ninguna tripleta con clave c, devuelve una colecciónConMarca igual a la
 * resultante de añadir la tripleta (c,v,falso) a d; si en d hay una tripleta (c,v’,b), entonces
 * devuelve una colecciónConMarca igual a la resultante de sustituir (c,v’,b) por (c,v,falso). */
template<typename C, typename V>
void anyadir (coleccionConMarca<C,V> &d, const C &c, const V &v) {
    char anyadido = anyadir_aux(d.raiz, c, v);
    if (anyadido == 0) {
        d.num++;
    }
    else if (anyadido == 1) {
        d.numMarca--;
    }
};

template<typename C, typename V>
char anyadir_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c, const V &v) {
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
            anyadir_aux(a->izq, c, v);
        }
        else {
            anyadir_aux(a->der, c, v);
        }
    }
};

template<typename C, typename V>
bool pertenece (const coleccionConMarca<C,V> &d, const C &c) {
    return pertenece_aux(d.raiz, c);
};

template<typename C, typename V>
bool pertenece_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c) {
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
            pertenece_aux(a->izq, c);
        }
        else {
            pertenece_aux(a->der, c);
        }
    }
};

template<typename C, typename V>
void obtenerValor (const coleccionConMarca<C,V> &d, const C &c, V &v, bool &error) {
    obtenerValor_aux(d.raiz, c, v, error);
};

template<typename C, typename V>
void obtenerValor_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c, V &v, bool &error) {
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
            obtenerValor_aux(a->izq, c, v, error);
        }
        else {
            obtenerValor_aux(a->der, c, v, error);
        }
    }
};

template<typename C, typename V>
bool obtenerMarca (const coleccionConMarca<C,V> &d, const C &c, bool &error) {
    return obtenerMarca_aux(d.raiz, c, error);
};

template<typename C, typename V>
bool obtenerMarca_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c, bool &error) {
    if (a == nullptr) {
        // No existe un nodo con clave c
        error = true;
        return false;
    }
    else {
        if (c == a->c) {
            // Existe un nodo con clave c
            error = false;
            return a->v;
        }
        else if (c < a->c) {
            obtenerMarca_aux(a->izq, c, error);
        }
        else {
            obtenerMarca_aux(a->der, c, error);
        }
    }
};

template<typename C, typename V>
void quitar (coleccionConMarca<C,V> &d, const C &c) {
    char resul = quitar_aux(d.raiz, c);
    if (resul == 1) {
        d.num--;
        d.numMarca--;
    }
    else if (resul == 2) {
        d.num--;
    }
};

template<typename C, typename V>
char quitar_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c) {
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
                max(a->izq, a->c);
                quitar_aux(a->izq, a->c);
            }
        }
        else if (c < a->c) {
            quitar_aux(a->izq, c);
        }
        else {
            quitar_aux(a->der, c);
        }
    }
};

/* Precondición: a no es un árbol vacío */
template<typename C, typename V>
void max (typename coleccionConMarca<C,V>::Nodo *a, C &c) {
    if (a->der == nullptr) {
        c = a->c;
    }
    else {
        max(a->der, c);
    }
};

template<typename C, typename V>
int cardinal (const coleccionConMarca<C,V> &d) {
    return d.num;
};

template<typename C, typename V>
int cardinalConMarca (const coleccionConMarca<C,V> &d) {
    return d.numMarca;
};

template<typename C, typename V>
void cambiarMarca (coleccionConMarca<C,V> &d, const C &c) {
    char resul = cambiarMarca_aux(d.raiz, c);
    if (resul == 1) {
        d.numMarca--;
    }
    else if (resul == 2) {
        d.numMarca++;
    }
};

template<typename C, typename V>
char cambiarMarca_aux (typename coleccionConMarca<C,V>::Nodo *a, const C &c) {
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
            cambiarMarca_aux(a->izq, c);
        }
        else {
            cambiarMarca_aux(a->der, c);
        }
    }
};

template<typename C, typename V>
bool esVacio (const coleccionConMarca<C,V> &d) {
    return d.num == 0;
};

template<typename C, typename V>
void iniciarIterador (coleccionConMarca<C,V> &d) {

};

template<typename C, typename V>
bool existeSiguiente (const coleccionConMarca<C,V> &d) {
    return d.iterador != nullptr;
};

template<typename C, typename V>
void siguienteClave (const coleccionConMarca<C,V> &d, C &c, bool &error) {

};

template<typename C, typename V>
void siguienteValor (const coleccionConMarca<C,V> &d, V &v, bool &error) {

};

template<typename C, typename V>
bool siguienteMarca (const coleccionConMarca<C,V> &d, bool &error) {

};

template<typename C, typename V>
void avanza (coleccionConMarca<C,V> &d, bool &error) {

};

#endif // fin de coleccionConMarca.h
