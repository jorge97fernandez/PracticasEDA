//*****************************************************************
// Archivo: recopilacion.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge ...
// Fecha:   Noviembre 2018
// Coms:    EDA - Práctica 1 - TAD Recopilación
//*****************************************************************

#ifndef RECOPILACION_H
#define RECOPILACION_H

// Interfaz del TAD Recopilación. Pre-declaraciones:
template<typename C, typename V> struct Recopilacion;
template<typename C, typename V> Recopilacion<C,V> crear ();
template<typename C, typename V> int cardinal (Recopilacion<C,V> &r);
template<typename C, typename V> int tamanyoTotal (Recopilacion<C,V> &r);
template<typename C, typename V> bool existe (Recopilacion<C,V> &r, C &k);
template<typename C, typename V> void introducir (Recopilacion<C,V> &r, C &k, V &v);

// Declaración
template<typename C, typename V>
struct Recopilacion {
    friend Recopilacion crear<C,V> ();
    friend int cardinal<C,V> (Recopilacion &r);
    friend int tamanyoTotal<C,V> (Recopilacion &r);
    friend bool existe<C,V> (Recopilacion &r, C &k);
    friend void introducir<C,V> (Recopilacion<C,V> &r, C &k, V &v);
private:
    struct Par {
        C clave;
        V valor;
        Par *siguiente;
    };
    Par *inicial;
    Par *final;
    int numDatos;
    int tamanyo;
    Par *iterador;
};

// Implementación
template<typename C, typename V>
Recopilacion<C,V> crear () {
    Recopilacion<C,V> r;
    r.numDatos = 0;
    r.tamanyo = 0;
    r.inicial = nullptr;
    r.final = nullptr;
    r.iterador = nullptr;
    return r;
}

template<typename C, typename V>
int cardinal (Recopilacion<C,V> &r) {
    return r.numDatos;
}

template<typename C, typename V>
int tamanyoTotal (Recopilacion<C,V> &r) {
    return r.tamanyo;
}

template<typename C, typename V>
bool existe (Recopilacion<C,V> &r, C &k) {
    if (r.tamanyo == 0) {
        // r está vacía
        return false;
    }

    typename Recopilacion<C,V>::Par *busqueda = r.inicial;

    while (busqueda != nullptr) {
        // r no está vacía
        if (busqueda->clave == k) {
            // existe un Par con clave k
            return true;
        }
        else {
            busqueda = busqueda->siguiente;
        }
    }

    // no existe un Par con clave k
    return false;
}

template<typename C, typename V>
void introducir (Recopilacion<C,V> &r, C &k, V &v) {
    typename Recopilacion<C,V>::Par *aux = r.inicial;
    bool encontrado = false;

    while (aux != nullptr && !encontrado) {
        // r no está vacía
        if (aux->clave == k) {
            // ya existe un Par con clave k
            encontrado = true;
            r.tamanyo -= aux->valor.tamanyo(); // Operación de V
            aux->valor = v;
            r.tamanyo += aux->valor.tamanyo(); // Operación de V
        }
        else {
            aux = aux->siguiente;
        }
    }

    if (!encontrado) {
        // no existe un Par con clave k ó r está vacía
        aux = new typename Recopilacion<C,V>::Par;
        aux->valor = v;
        aux->clave = k;
        aux->siguiente = nullptr;
        r.numDatos++;
        r.tamanyo = v.tamanyo(); // Operación de V

        if (r.inicial == nullptr) {
            // r está vacía
            r.inicial = aux;
            r.final = aux;
        }
        else {
            // r no está vacía
            r.final->siguiente = aux;
            r.final = aux;
        }
    }
}

#endif // fin de recopilacion.h