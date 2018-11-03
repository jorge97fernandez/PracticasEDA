//*********************************************
// Archivo: albumCanciones.h
// Autor: Andrés Gavín Murillo 716358
// Autor: Jorge Fernández Muñoz 721529
// Fecha: Noviembre 2018
// Coms: EDA - Practica 1 - TAD albumCanciones
//

#include "string"
#include "generico.h"
#include "cancion.h"
#include "recopilacion.h"

using namespace std;

#ifndef ALBUMCANCIONES_H
#define ALBUMCANCIONES_H
struct albumCanciones;
void crear(albumCanciones &a,string titulo);
int numCanciones(albumCanciones &a);
int duracion (albumCanciones &a);
bool existeCancion(albumCanciones &a, string s);
void obtenerCancion(albumCanciones &a, string s, Cancion &c, bool &error);
void anyadirCancion(albumCanciones &a, string s, Cancion c);
void eliminarCancion(albumCanciones &a, int puesto);
void puestodeCancion(albumCanciones &a, string s, int &puesto, bool &error);
void canciondePuesto(albumCanciones &a, int puesto, string &clave, bool &error);
void intercambiarCanciones( albumCanciones &a, string s, string b);
void listarAlbum( albumCanciones &a);

struct albumCanciones{
   friend void crear(albumCanciones &a,string titulo);
   friend int numCanciones(albumCanciones &a);
   friend int duracion (albumCanciones &a);
   friend bool existeCancion(albumCanciones &a, string s);
   friend void obtenerCancion(albumCanciones &a, string s, Cancion &c, bool &error);
   friend void anyadirCancion(albumCanciones &a, string s, Cancion c);
   friend void eliminarCancion(albumCanciones &a, int puesto);
   friend void puestodeCancion(albumCanciones &a, string s, int &puesto, bool &error);
   friend void canciondePuesto(albumCanciones &a, int puesto, string &clave, bool &error);
   friend void intercambiarCanciones( albumCanciones &a, string s, string b);
   friend void listarAlbum( albumCanciones &a);

private:
    string tituloAlbum;
    Recopilacion<string,Cancion> Canciones;
    int duracionTotal;
};
#endif ALBUMCANCIONES_H