//**********************************************************************************************************************
// Archivo: repertorio.cpp
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD repertorio
//**********************************************************************************************************************

#include "repertorio.h"

using namespace std;


// Implementación del TAD colecciónConMarca:

/* Devuelve un repertorio vacío (sin canciones), y título tit. */
void crear (repertorio &r, const string &tit) {
    r.tit = tit;
    crear(r.c);
};

/* Devuelve el título del repertorio r. */
string tituloRepertorio (const repertorio &r) {
    return r.tit;
};

/* Devuelve cierto si y solo si en el repertorio r existe una canción identificada por clave k. */
bool existeCancion (const repertorio &r, const string &k) {
    return pertenece(r.c, k);
};

/* Si not existeCancion(r,k), devuelve el repertorio resultante de añadir en r una canción no escuchada c e
 * identificada por la clave k. Si existeCancion(r,k), en r existe una canción c1 identificada por la clave k, entonces
 * devuelve el repertorio resultante de sustituir en r la canción c1 por la canción c, conservando la misma clave, pero
 * marcada como no escuchada. */
void anyadir (repertorio &r, const string &k, const Cancion &c) {
    anyadir(r.c, k, c);
};

/* Si existeCancion(r,k), devuelve la canción identificada por la clave k en r, y en error devuelve falso.
 * Parcial: se precisa que existeCancion(r,k); de lo contrario en error devuelve verdad. */
void obtenerCancion (const repertorio &r, const string &k, Cancion &c, bool &error) {
    obtenerValor(r.c, k, c, error);
};

/* Si existeCancion(r,k), devuelve verdad si y solo si la canción identificada por la clave k en r ha sido escuchada,
 * y en error devuelve falso.
 * Parcial: se precisa que existeCancion(r,k); de lo contrario en error devuelve verdad. */
bool escuchada (const repertorio &r, const string &k, bool &error) {
    return obtenerMarca(r.c, k, error);
};

/* Si existeCancion(r,k), devuelve el repertorio resultante de marcar la canción identificada por la clave k con m. Si
 * not existeCancion(r,k), devuelve un repertorio igual a r. */
void modificarEscuchada (repertorio &r, const string &k, const bool &m) {
    bool error;
    bool escu = escuchada(r, k, error);
    if (!error && escu != m) {
        cambiarMarca(r.c, k);
    }
};

/* Si existeCancion(r,k), devuelve el repertorio resultante de eliminar de r la canción identificada por k. En caso
 * contrario, devuelve un repertorio igual a r. */
void quitarCancion (repertorio &r, const string &k) {
    quitar(r.c, k);
};

/* Devuelve el número total de canciones en el repertorio r. */
int totalCanciones (const repertorio &r) {
    return cardinal(r.c);
};

/* Devuelve el número total de canciones escuchadas en el repertorio r. */
int totalCancionesEscuchadas (const repertorio &r) {
    return cardinalConMarca(r.c);
};

/* Devuelve una cadena que contiene la representación como cadena de caracteres de toda la información sobre todas las
 * canciones del repertorio. La cadena se formará como la concatenación de:
 *
 * - la cadena “CANCIONES NO ESCUCHADAS: ”, seguida del total de canciones no escuchadas, seguido de un salto de línea;
 *
 * - la información de todas las canciones no escuchadas del repertorio por orden de clave en sentido ascendente, y de
 * tal forma que toda la información sobre una canción esté separada de la siguiente canción con el carácter de salto de
 * línea. La información de cada canción tendrá el siguiente formato: la cadena que identifica a la canción en r,
 * seguida de la cadena “:::”, seguida de la cadena “<* ”, seguida de una cadena con la información de la canción1, y
 * finalmente, seguida de la cadena “*>”.
 *
 * - la cadena “CANCIONES ESCUCHADAS: ”, seguida del total de canciones escuchadas, seguido de un salto de línea;
 *
 * - la información de todas las canciones escuchadas del repertorio con el mismo formato que el indicado para las
 * canciones no escuchadas. */
string listarRepertorio (const repertorio &r) {

}