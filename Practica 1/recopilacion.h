//**********************************************************************************************************************
// Archivo: recopilacion.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   7 Noviembre 2018
// Coms:    EDA - Práctica 1 - TAD Recopilación
//**********************************************************************************************************************

#ifndef RECOPILACION_H
#define RECOPILACION_H


// Interfaz del TAD Recopilación. Pre-declaraciones:

/* Los valores del TAD representan conjuntos de pares (clave,dato), en los que no se permiten claves repetidas, y que
 * cuentan con algunas operaciones de consulta y modificación guiadas por clave, pero también con operaciones que
 * permiten consultar, controlar y modificar la posición relativa (puesto) de los pares dentro de la recopilación, e
 * incluso operaciones para la consulta y modificación de los pares según su puesto en la recopilación.
 * El puesto de un par en la recopilación vendrá dado en todo momento por su posición relativa respecto al resto de los
 * pares, de tal forma que: el par con menor puesto ocupará el puesto número 1; no podrá haber más de un par en el mismo
 * puesto; y en ningún caso podrá haber puesto vacíos.
 *
 * El TAD ofrece además las operaciones de un iterador que permite visitar los pares de una recopilación por orden de
 * puesto, empezando por el del puesto número uno, y acabando por el del último puesto.
 *
 * El TAD que se use para la clave, debe tener definidas las siguientes operaciones:
 *    bool operator== (clave c1, clave c2) {Devuelve cierto si y sólo si c1 es igual que c2}
 *    string to_string (clave o) {Transformación a cadena}
 *
 * El TAD que se use para el dato, debe tener definidas las siguientes operaciones:
 *    string to_string (dato v) {Transformación a cadena}
 *    int tamanyo (dato v) {Devuelve el tamaño de un dato v}
 */
template<typename C, typename V> struct Recopilacion;

/* Devuelve una recopilación vacía, sin elementos (pares). */
template<typename C, typename V> void crear (Recopilacion<C,V> &r);

/* Devuelve el número de pares en la recopilación r. */
template<typename C, typename V> int cardinal (const Recopilacion<C,V> &r);

/* Devuelve el tamaño total de la recopilación r, es decir, la suma total de los tamaños de los datos de todos los pares
 * en la recopilación r.*/
template<typename C, typename V> int tamanyoTotal (const Recopilacion<C,V> &r);

/* Devuelve verdad si y sólo si en r existe un par con clave k. */
template<typename C, typename V> bool existe (const Recopilacion<C,V> &r, const C &k);

/* Si en r no existe ningún par con clave k (not existe(r,k)), devuelve la recopilación resultante de añadir en r un par
 * (k,v) ocupando su último puesto. Si en r ya existe un par (k,v1) entonces devuelve la recopilación resultante de
 * sustituir dicho par en r por un par (k,v), conservando el mismo puesto. */
template<typename C, typename V> void introducir (Recopilacion<C,V> &r, const C &k, const V &v);

/* Si en r existe un par (k,v), devuelve su dato v en dato, y en error devuelve false.
 * Parcial: se precisa que existe(r,k); de lo contrario, en error devuelve true. */
template<typename C, typename V> void obtenerDato (const Recopilacion<C,V> &r, const C &k, V &dato, bool &error);

/* Si not existe(r,k), devuelve una recopilación igual a r. Si existe(r,k), devuelve la recopilación resultante de
 * modificar el puesto relativo del par (k,v) entre los pares en r, alejándolo delta posiciones del primer puesto de r
 * si delta es positivo (o colocándolo el último si no hay tantos puesto), o acercándolo -delta posiciones al primer
 * puesto de r si delta es negativo (o colocándolo el primero, si no hay tantos puestos); en cualquier caso no se
 * modifican las posiciones relativas entre sí del resto de los pares. Si delta<0, el par que ocupaba en r el puesto
 * destino para el par con clave k, en la recopilación resultante quedará ocupando el puesto siguiente al que tenía en
 * r. Si delta>0, el par que ocupaba en r el puesto destino para el par con clave k, en la recopilación resultante
 * ocupará el puesto anterior al que tenía en r. */
template<typename C, typename V> void recolocarEnPuesto (Recopilacion<C,V> &r, const C &k, int delta);

/* Si 1<=p<=cardinal(r) existe un par en r en el puesto p, entonces devuelve una recopilación igual a la resultante de
 * eliminar de r el par que ocupaba el puesto p, con todos los demás pares iguales a los que hay en r, y en las mismas
 * posiciones relativas. En caso contrario, devuelve una recopilación igual a r. */
template<typename C, typename V> void eliminarXPuesto (Recopilacion<C,V> &r, int p);

/* Si 1<=p<=cardinal(r) existe un puesto p en r ocupado por un par (k,v), y devuelve su clave k en clave, y en error
 * devuelve false.
 * Parcial: se precisa que exista un puesto p en r; de lo contrario, en error devuelve true.*/
template<typename C, typename V> void obtenerXPuesto (const Recopilacion<C,V> &r, int p, C &clave, bool &error);

/* Si existe(r,k), devuelve el puesto del par (k,v) en r, en puesto, y en error devuelve false.
 * Parcial: se precisa que existe(r,k); de lo contrario, en error devuelve true. */
template<typename C, typename V> void puestoDeClave (const Recopilacion<C,V> &r, const C &k, int &puesto, bool &error);

/* Inicializa el iterador para recorrer los pares de la recopilación r, de forma que el siguiente par sea el del primer
 * puesto de la recopilación r (situación de no haber visitado ningún par). */
template<typename C, typename V> void iniciarIterador (Recopilacion<C,V> &r);

/* Devuelve verdad si y sólo si queda algún par por visitar con el iterador de la recopilación r. */
template<typename C, typename V> bool existeSiguiente (const Recopilacion<C,V> &r);

/* Devuelve la clave del siguiente par a visitar de r, en clave, y en error devuelve false.
 * Parcial: se precisa que no se haya visitado ya el último par; de lo contrario en error devuelve true. */
template<typename C, typename V> void siguienteClave (const Recopilacion<C,V> &r, C &clave, bool &error);

/* Devuelve el dato del siguiente par a visitar de r, en dato, y en error devuelve false.
 * Parcial: se precisa que no se haya visitado ya el último par; de lo contrario en error devuelve true. */
template<typename C, typename V> void siguienteDato (const Recopilacion<C,V> &r, V &dato, bool &error);

/* Prepara el iterador para visitar el par del siguiente puesto de la recopilación r, y en error devuelve false.
 * Parcial: se precisa que no se haya visitado ya el último par; de lo contrario en error devuelve true. */
template<typename C, typename V> void avanza (Recopilacion<C,V> &r, bool &error);


// Declaración:

template<typename C, typename V>
struct Recopilacion {
    friend void crear<C,V> (Recopilacion<C,V> &r);
    friend int cardinal<C,V> (const Recopilacion &r);
    friend int tamanyoTotal<C,V> (const Recopilacion &r);
    friend bool existe<C,V> (const Recopilacion &r, const C &k);
    friend void introducir<C,V> (Recopilacion<C,V> &r, const C &k, const V &v);
    friend void obtenerDato<C,V> (const Recopilacion<C,V> &r, const C &k, V &dato, bool &error);
    friend void recolocarEnPuesto<C,V> (Recopilacion<C,V> &r, const C &k, int delta);
    friend void eliminarXPuesto<C,V> (Recopilacion<C,V> &r, int p);
    friend void obtenerXPuesto<C,V> (const Recopilacion<C,V> &r, int p, C &clave, bool &error);
    friend void puestoDeClave<C,V> (const Recopilacion<C,V> &r, const C &k, int &puesto, bool &error);
    friend void iniciarIterador<C,V> (Recopilacion<C,V> &r);
    friend bool existeSiguiente<C,V> (const Recopilacion<C,V> &r);
    friend void siguienteClave<C,V> (const Recopilacion<C,V> &r, C &clave, bool &error);
    friend void siguienteDato<C,V> (const Recopilacion<C,V> &r, V &dato, bool &error);
    friend void avanza<C,V> (Recopilacion<C,V> &r, bool &error);

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


// Implementación del TAD Recopilación:

/* Inicializa r. */
template<typename C, typename V>
void crear (Recopilacion<C,V> &r) {
    r.numDatos = 0;
    r.tamanyo = 0;
    r.inicial = nullptr;
    r.final = nullptr;
    r.iterador = nullptr;
}; // O(1)

template<typename C, typename V>
int cardinal (const Recopilacion<C,V> &r) {
    return r.numDatos;
}; // O(1)

template<typename C, typename V>
int tamanyoTotal (const Recopilacion<C,V> &r) {
    return r.tamanyo;
}; // O(1)

/* Devuelve true si k pertenece a r; en otro caso devuelve false. */
template<typename C, typename V>
bool existe (const Recopilacion<C,V> &r, const C &k) {
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
}; // O(n)

/* Añade el Par (k,v), y, si ya existe, actualiza su dato por v. */
template<typename C, typename V>
void introducir (Recopilacion<C,V> &r, const C &k, const V &v) {
    typename Recopilacion<C,V>::Par *aux = r.inicial;
    bool encontrado = false;

    while (aux != nullptr && !encontrado) {
        // r no está vacía
        if (aux->clave == k) {
            // ya existe un Par con clave k
            encontrado = true;
            r.tamanyo -= tamanyo(aux ->valor); // Operación de V
            aux->valor = v;
            r.tamanyo += tamanyo(v); // Operación de V
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
        r.tamanyo += tamanyo(v); // Operación de V

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
}; // O(n)

/* Si existe el Par (k,v): dato=v y !error; sino: error. */
template<typename C, typename V>
void obtenerDato (const Recopilacion<C,V> &r, const C &k, V &dato, bool &error) {
    typename Recopilacion<C,V>::Par *aux = r.inicial;
    bool encontrado = false;

    while (aux != nullptr && !encontrado) {
        // r no está vacía
        if (aux->clave == k) {
            // existe un Par con clave k
            encontrado = true;
            dato = aux->valor;
            error = false;
        }
        else {
            aux = aux->siguiente;
        }
    }

    if (!encontrado) {
        // no existe un Par con clave k ó r está vacía
        error = true;
    }
}; // O(n)

/* Si existe el Par (k,v): mueve su posición relativa delta posiciones y !error; sino: error. */
template<typename C, typename V>
void recolocarEnPuesto (Recopilacion<C,V> &r, const C &k, int delta) {
    if (delta != 0) {
        typename Recopilacion<C,V>::Par *aux = r.inicial;
        typename Recopilacion<C,V>::Par *aux2 = nullptr;
        bool encontrado = false;
        int posPar = 1;

        while (aux != nullptr && !encontrado) {
            if (aux->clave == k) {
                // existe un Par con clave k
                encontrado = true;
            }
            else {
                aux2 = aux;
                aux = aux->siguiente;
                posPar++;
            }
        }

        if (encontrado) {
            // aux = *Par que se desea mover
            // aux2 = *Par anterior al que se desea mover
            // posPar = posición del par que se desea mover

            int posDes = posPar + delta;
            if (posDes > cardinal(r)) {
                posDes = cardinal(r);
            }
            else if (posDes < 1) {
                posDes = 1;
            }
            // posDes = posición destino

            if (posPar != posDes) {
                // el par se va a mover a una posición distina de la que estaba
                if (posPar == cardinal(r)) {
                    // el elemento a mover es el último
                    r.final = aux2;
                }

                if (posPar == 1) {
                    // el elemento a mover es el primero
                    r.inicial = aux->siguiente;
                }
                else {
                    // el elemento a mover no es el primero
                    aux2->siguiente = aux->siguiente;
                }

                if (posDes == cardinal(r)) {
                    // el destino es el final
                    r.final->siguiente = aux;
                    aux->siguiente = nullptr;
                    r.final = aux;
                }

                else if (posDes == 1) {
                    // el destino es el principio
                    aux->siguiente = r.inicial;
                    r.inicial = aux;
                }

                else {
                    // el destino no es el principio ni el final
                    encontrado = false;
                    int posAux;
                    if (posDes > posPar) {
                        aux2 = aux2->siguiente; // *Par siguiente al que se desea mover
                        posAux = posPar + 1;
                        // se parte desde el par que se desea mover
                    }
                    else {
                        aux2 = r.inicial;
                        posAux = 1;
                        // se parte desde el inicio
                    }

                    // posDes <= cardinal(r)
                    while (!encontrado) {
                        if (posAux >= posDes-1) {
                            encontrado = true;
                        }
                        else {
                            aux2 = aux2->siguiente;
                            posAux++;
                        }
                    }
                    // aux2 = *Par anterior al destino
                    // aux = *Par que se desea mover

                    aux->siguiente = aux2->siguiente;
                    aux2->siguiente = aux;
                }
            }
        }
    }
}; // O(2n)

/* Si 1<=p<=cardinal(r): elimina el Par que ocupe la posición p. */
template<typename C, typename V>
void eliminarXPuesto (Recopilacion<C,V> &r, int p) {
    if (1 <= p && p <= cardinal(r)) {
        // r no está vacía y p es un puesto de r
        typename Recopilacion<C,V>::Par *aux = r.inicial;
        typename Recopilacion<C,V>::Par *aux2 = nullptr;
        bool encontrado = false;
        int i = 1; // puesto de aux

        while (aux != nullptr && !encontrado) {
            if (i == p) {
                // aux tiene el puesto p y aux2 tiene el puesto p-1
                encontrado = true;

                if (p == cardinal(r)) {
                    // el elemento a borrar es el último
                    r.final = aux2;
                }

                r.numDatos--;
                r.tamanyo -= tamanyo(aux->valor);

                if (p == 1) {
                    // el elemento a borrar es el primero
                    r.inicial = aux->siguiente;
                }
                else {
                    // el elemento a borrar no es el primero
                    aux2->siguiente = aux->siguiente;
                }

                delete(aux);
            }
            else {
                aux2 = aux;
                aux = aux->siguiente;
                i++;
            }
        }
    }
}; // O(n)

/* Si 1<=p<=cardinal(r): clave=(clave del Par que ocupa la posición p) y !error; sino: error. */
template<typename C, typename V>
void obtenerXPuesto (const Recopilacion<C,V> &r, int p, C &clave, bool &error){
    if (p < 1 || p > cardinal(r)) {
        error = true;
    }
    else {
        typename Recopilacion<C,V>::Par *aux = r.inicial;
        int puesto = 1;

        while (puesto != p) {
            aux = aux->siguiente;
            puesto++;
        }

        clave = aux->clave;
        error = false;
    }
}; // O(n)

/* Si existe(r,k): puesto=(puesto del Par con clave k) y !error; sino: error. */
template<typename C, typename V>
void puestoDeClave (const Recopilacion<C,V> &r, const C &k, int &puesto, bool &error){
    bool encontrado = false;
    int puestoPar = 1;
    typename Recopilacion<C,V>::Par *aux = r.inicial;

    while (aux != nullptr && !encontrado) {
        // r no está vacía
        if (aux->clave == k) {
            // existe un Par con clave k
            encontrado = true;
            puesto = puestoPar;
        }
        else {
            aux = aux->siguiente;
            puestoPar++;
        }
    }

    error = !encontrado;
}; // O(n)

/* Inicializa el iterador. */
template<typename C, typename V>
void iniciarIterador (Recopilacion<C,V> &r) {
    r.iterador = r.inicial;
}; // O(1)

template<typename C, typename V>
bool existeSiguiente (const Recopilacion<C,V> &r) {
    return r.iterador != nullptr;
}; // O(1)

template<typename C, typename V>
void siguienteClave (const Recopilacion<C,V> &r, C &clave, bool &error) {
    if (existeSiguiente(r)) {
        clave = r.iterador->clave;
        error = false;
    }
    else {
        error = true;
    }
}; // O(1)

template<typename C, typename V>
void siguienteDato (const Recopilacion<C,V> &r, V &dato, bool &error) {
    if (existeSiguiente(r)) {
        dato = r.iterador->valor;
        error = false;
    }
    else {
        error = true;
    }
}; // O(1)

/* Avanza el iterador, sino: error. */
template<typename C, typename V>
void avanza (Recopilacion<C,V> &r, bool &error) {
    if (existeSiguiente(r)) {
        r.iterador = r.iterador->siguiente;
        error = false;
    }
    else {
        error = true;
    }
}; // O(1)

#endif // fin de recopilacion.h
