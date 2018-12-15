//**********************************************************************************************************************
// Archivo: repertorio.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD repertorio
//**********************************************************************************************************************

#ifndef REPERTORIO_H
#define REPERTORIO_H

#include <string>
#include "coleccionConMarca.h"
#include "cancion.h"


// Interfaz del TAD repertorio. Pre-declaraciones:

/* Los valores del TAD representan un repertorio de canciones con las siguientes características: una cadena de
 * caracteres para representar el título del repertorio, y un conjunto de canciones, cada una de ellas identificada por
 * una clave (cadena) y marcada con un valor booleano para indicar si la canción ha sido escuchada o no. */
struct repertorio;

/* Devuelve un repertorio vacío (sin canciones), y título tit. */
void crear (repertorio &r, const std::string &tit);

/* Devuelve el título del repertorio r. */
std::string tituloRepertorio (const repertorio &r);

/* Devuelve cierto si y solo si en el repertorio r existe una canción identificada por clave k. */
bool existeCancion (const repertorio &r, const std::string &k);

/* Si not existeCancion(r,k), devuelve el repertorio resultante de añadir en r una canción no escuchada c e
 * identificada por la clave k. Si existeCancion(r,k), en r existe una canción c1 identificada por la clave k, entonces
 * devuelve el repertorio resultante de sustituir en r la canción c1 por la canción c, conservando la misma clave, pero
 * marcada como no escuchada. */
void anyadir (repertorio &r, const std::string &k, const Cancion &c);

/* Si existeCancion(r,k), devuelve la canción identificada por la clave k en r, y en error devuelve falso.
 * Parcial: se precisa que existeCancion(r,k); de lo contrario en error devuelve verdad. */
void obtenerCancion (const repertorio &r, const std::string &k, Cancion &c, bool &error);

/* Si existeCancion(r,k), devuelve verdad si y solo si la canción identificada por la clave k en r ha sido escuchada,
 * y en error devuelve falso.
 * Parcial: se precisa que existeCancion(r,k); de lo contrario en error devuelve verdad. */
bool escuchada (const repertorio &r, const std::string &k, bool &error);

/* Si existeCancion(r,k), devuelve el repertorio resultante de marcar la canción identificada por la clave k con m. Si
 * not existeCancion(r,k), devuelve un repertorio igual a r. */
void modificarEscuchada (repertorio &r, const std::string &k, const bool &m);

/* Si existeCancion(r,k), devuelve el repertorio resultante de eliminar de r la canción identificada por k. En caso
 * contrario, devuelve un repertorio igual a r. */
void quitarCancion (repertorio &r, const std::string &k);

/* Devuelve el número total de canciones en el repertorio r. */
int totalCanciones (const repertorio &r);

/* Devuelve el número total de canciones escuchadas en el repertorio r. */
int totalCancionesEscuchadas (const repertorio &r);

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
std::string listarRepertorio (repertorio &r);


// Declaración:

struct repertorio {
    friend void crear (repertorio &r, const std::string &tit);
    friend std::string tituloRepertorio (const repertorio &r);
    friend bool existeCancion (const repertorio &r, const std::string &k);
    friend void anyadir (repertorio &r, const std::string &k, const Cancion &c);
    friend void obtenerCancion (const repertorio &r, const std::string &k, Cancion &c, bool &error);
    friend bool escuchada (const repertorio &r, const std::string &k, bool &error);
    friend void modificarEscuchada (repertorio &r, const std::string &k, const bool &m);
    friend void quitarCancion (repertorio &r, const std::string &k);
    friend int totalCanciones (const repertorio &r);
    friend int totalCancionesEscuchadas (const repertorio &r);
    friend std::string listarRepertorio (repertorio &r);

private:
    std::string tit; // Título
    coleccionConMarca<std::string, Cancion> c;
};

#endif //REPERTORIO_H