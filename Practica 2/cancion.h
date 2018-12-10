//**********************************************************************************************************************
// Archivo: cancion.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD Canción (Interfaz)
//**********************************************************************************************************************

#ifndef CANCION_H
#define CANCION_H

#include <string>

using namespace std;


// Interfaz del TAD Canción. Pre-declaraciones:

/* Los valores del TAD Canción representan datos de una canción, identificada por su nombre. La canción incluye
 * información de su autor (identificado por su nombre y apellidos), que será uno solo. Además, incluye su año de
 * composición, y su duración en segundos, la cual también será considerada como el tamaño de la canción.
 *
 * La canción se creará mediante la operación crear, en cambio, no se podrá modificar ni borrar.
 *
 * El TAD ofrece además operaciones para mostrar la información de la canción, y también una operación to_string
 * que devuelve una cadena conteniendo toda la información de la canción.
 */
struct Cancion;

/* Devuelve una canción con nombre nombreC, autor nombreA, año de composición anyo, y duración en segundos duracion. */
Cancion crear (string nombreC, string nombreA, int anyo, int duracion);

/* Devuelve el nombre de la canción c. */
string nombreCancion (const Cancion &c);

/* Devuelve el autor de la canción c. */
string nombreAutor (const Cancion &c);

/* Devuelve el año de composición de la canción c. */
int anyoComposicion (const Cancion &c);

/* Devuelve la duración en segundos de la canción c. */
int duracion (const Cancion &c);

/* Devuelve una cadena conteniendo toda la información de la canción c con el siguiente formato:
 *      nombre --- autor --- año (duración) */
string to_string (const Cancion &c);

/* Devuelve el tamaño de la canción c. */
int tamanyo (const Cancion &c);


// Declaración:

struct Cancion {
    friend Cancion crear (string nombreC, string nombreA, int anyo, int duracion);
    friend string nombreCancion (const Cancion &c);
    friend string nombreAutor (const Cancion &c);
    friend int anyoComposicion (const Cancion &c);
    friend int duracion (const Cancion &c);
    friend string to_string (const Cancion &c);
    friend int tamanyo (const Cancion &c);

private:
    string nombreCanc; // Nombre de la canción
    string nombreAut; // Nombre y apellidos del autor
    int anyoComp; // Año de composición
    int durac; // Duración en segundos
};

#endif // fin de cancion.h
