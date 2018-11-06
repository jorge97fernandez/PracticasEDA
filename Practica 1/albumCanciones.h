//**********************************************************************************************************************
// Archivo: albumCanciones.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   7 Noviembre 2018
// Coms:    EDA - Práctica 1 - TAD Álbum de Canciones (Interfaz)
//**********************************************************************************************************************

#ifndef ALBUMCANCIONES_H
#define ALBUMCANCIONES_H

#include "string_lib.h"
#include "cancion.h"
#include "recopilacion.h"

using namespace std;


// Interfaz del TAD Álbum de Canciones. Pre-declaraciones:

/* Los valores del TAD representan álbumes de canciones, caracterizados por la siguiente información: un título del
 * álbum (cadena), y una recopilación de canciones identificadas en el álbum por claves (únicas) de tipo cadena. Las
 * operaciones del TAD permiten gestionar las canciones que ocupan las pistas del álbum. La primera canción del álbum
 * estará en la pista número 1.
 */
struct albumCanciones;

/* Crea un álbum con el título dado y sin canciones. */
void crear (albumCanciones &a, string titulo);

/* Devuelve el número de canciones en el álbum a. */
int numCanciones (const albumCanciones &a);

/* Devuelve la duración total del álbum a, es decir, la suma de las duraciones de todas sus canciones. */
int duracion (const albumCanciones &a);

/* Devuelve el título del álbum a. */
string tituloDeAlbum (const albumCanciones &a);

/* Devuelve verdad si y sólo si en el álbum a existe una canción identificada por la clave s. */
bool existeCancion (const albumCanciones &a, string s);

/* Si existeCancion(a, s), devuelve la canción identificada por la clave s en a, y en error devuelve false.
 * Parcial: se precisa que existeCancion(a, s); de lo contrario, en error devuelve true. */
void obtenerCancion (const albumCanciones &a, string s, Cancion &c, bool &error);

/* Si not existeCancion(a, s), devuelve el álbum resultante de añadir en a una canción c identificada por una clave s,
 * ocupando la última pista entre las canciones del álbum.
 * Si existeCancion(a, s), en a existe una canción c1 identificada por la clave s, entonces devuelve el álbum resultante
 * de sustituir en a la canción c1 por la canción c, conservando la misma clave y la misma pista que c1 entre las
 * canciones del álbum a. */
void anyadirCancion (albumCanciones &a, string s, const Cancion &c);

/* Si 1<=puesto<=numCanciones(a), entonces existe una canción en a en la pista puesto, y devuelve un álbum igual al
 * resultante de eliminar de a la canción que ocupaba la pista puesto, con todas las demás canciones (y sus claves)
 * iguales a las que hay en a, y en las mismas posiciones relativas. En caso contrario, devuelve un álbum igual a a.*/
void eliminarCancion (albumCanciones &a, int puesto);

/* Si existeCancion(a, s), devuelve la pista de la canción identificada por la clave s en a, y en error devuelve false.
 * Parcial: se precisa que existeCancion(a, s); de lo contrario, en error devuelve true. */
void puestodeCancion (const albumCanciones &a, string s, int &puesto, bool &error);

/* Si 1<=puesto<=numCanciones(a), entonces existe una canción en a en la pista puesto, y devuelve la clave con la que se
 * identifica a la canción que ocupa dicha pista en a, y en error devuelve false.
 * Parcial: se precisa que existeCancion(a, s); de lo contrario, en error devuelve true. */
void canciondePuesto (const albumCanciones &a, int puesto, string &clave, bool &error);

/* Si existeCancion(a, s) AND existeCancion(a, b), devuelve el álbum resultante de intercambiar en a las pistas ocupadas
 * por las canciones identificadas respectivamente por las claves s y b, sin cambiar las claves que identifican a cada
 * canción y sin modificar la pista o la información de ninguna otra canción del álbum. Si not existeCancion(a, s) OR
 * existeCancion(a, a), devuelve un álbum igual a a. */
void intercambiarCanciones (albumCanciones &a, string s, string b);

/* Devuelve una cadena que contiene la representación como cadena de caracteres de toda la información sobre todas las
 * canciones del álbum, por orden de pista en sentido ascendente, y de tal forma que toda la información sobre una
 * canción esté separada de la siguiente canción con el carácter de salto de línea; y para cada canción su información
 * se incluya con el siguiente formato:
 * la cadena "n) ", siendo n su número de pista en el álbum a, seguida de la cadena que identifica a la canción en b,
 * seguida a continuación de una cadena ":::", seguida de una cadena "<*", seguida de una cadena con toda la información
 * de la canción, y seguida de la cadena "*>". */
string listarAlbum (albumCanciones &a);


// Declaración:

struct albumCanciones{
   friend void crear (albumCanciones &a, string titulo);
   friend int numCanciones (const albumCanciones &a);
   friend int duracion (const albumCanciones &a);
   friend string tituloDeAlbum (const albumCanciones &a);
   friend bool existeCancion (const albumCanciones &a, string s);
   friend void obtenerCancion (const albumCanciones &a, string s, Cancion &c, bool &error);
   friend void anyadirCancion (albumCanciones &a, string s, const Cancion &c);
   friend void eliminarCancion (albumCanciones &a, int puesto);
   friend void puestodeCancion (const albumCanciones &a, string s, int &puesto, bool &error);
   friend void canciondePuesto (const albumCanciones &a, int puesto, string &clave, bool &error);
   friend void intercambiarCanciones (albumCanciones &a, string s, string b);
   friend string listarAlbum (albumCanciones &a);

private:
    string tituloAlbum;
    Recopilacion<string, Cancion> Canciones;
    int duracionTotal;
};

#endif // fin de albumCanciones.h
