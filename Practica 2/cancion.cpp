//**********************************************************************************************************************
// Archivo: cancion.cpp
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD Canción (Implementación)
//**********************************************************************************************************************

#include "cancion.h"


// Implementación del TAD Canción:

/* Devuelve una canción con nombre nombreC, autor nombreA, año de composición anyo, y duración en segundos duracion. */
Cancion crear (string nombreC, string nombreA, int anyo, int duracion) {
    Cancion c;
    c.nombreCanc = nombreC;
    c.nombreAut = nombreA;
    c.anyoComp = anyo;
    c.durac = duracion;

    return c;
};

/* Devuelve el nombre de la canción c. */
string nombreCancion (const Cancion &c) {
    return c.nombreCanc;
};

/* Devuelve el autor de la canción c. */
string nombreAutor (const Cancion &c) {
    return c.nombreAut;
};

/* Devuelve el año de composición de la canción c. */
int anyoComposicion (const Cancion &c) {
    return c.anyoComp;
};

/* Devuelve la duración en segundos de la canción c. */
int duracion (const Cancion &c) {
    return c.durac;
};

/* Devuelve una cadena conteniendo toda la información de la canción c con el siguiente formato:
 *      nombre --- autor --- año (duración) */
string to_string (const Cancion &c) {
    return c.nombreCanc + " --- " + c.nombreAut + " --- " + to_string(c.anyoComp) + " ( " + to_string(c.durac) + " )";
};

/* Devuelve el tamaño de la canción c. */
int tamanyo (const Cancion &c) {
    return duracion(c);
};
