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

template<typename C, typename V> void anyadir<C,V> (coleccionConMarca<C,V> &d, const C &c, const V &v);

template<typename C, typename V> bool pertenece<C,V> (const coleccionConMarca<C,V> &d, const C &c);

template<typename C, typename V> void obtenerValor<C,V> (const coleccionConMarca<C,V> &d, const C &c, V &v, bool &error);

template<typename C, typename V> bool obtenerMarca<C,V> (const coleccionConMarca<C,V> &d, const C &c, bool &error);

template<typename C, typename V> void quitar<C,V> (coleccionConMarca<C,V> &d, const C &c);

template<typename C, typename V> int cardinal<C,V> (const coleccionConMarca<C,V> &d);

template<typename C, typename V> int cardinalConMarca<C,V> (const coleccionConMarca<C,V> &d);

template<typename C, typename V> void cambiarMarca<C,V> (coleccionConMarca<C,V> &d, const C &c);

template<typename C, typename V> bool esVacio<C,V> (const coleccionConMarca<C,V> &d);

template<typename C, typename V> void iniciarIterador<C,V> (coleccionConMarca<C,V> &d);

template<typename C, typename V> bool existeSiguiente<C,V> (const coleccionConMarca<C,V> &d);

template<typename C, typename V> void siguienteClave<C,V> (const coleccionConMarca<C,V> &d, C &c, bool &error);

template<typename C, typename V> void siguienteValor<C,V> (const coleccionConMarca<C,V> &d, V &v, bool &error);

template<typename C, typename V> bool siguienteMarca<C,V> (const coleccionConMarca<C,V> &d, bool &error);

template<typename C, typename V> void avanza<C,V> (coleccionConMarca<C,V> &d, bool &error);


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

#endif // fin de coleccionConMarca.h
