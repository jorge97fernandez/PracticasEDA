//*********************************************
// Archivo: albumCanciones.h
// Autor: Andrés Gavín Murillo 716358
// Autor: Jorge Fernández Muñoz 721529
// Fecha: 4 Noviembre 2018
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
int numCanciones(const albumCanciones &a);
int duracion (const albumCanciones &a);
string tituloDeAlbum(const albumCanciones &a);
bool existeCancion(const albumCanciones &a,const string s);
void obtenerCancion(const albumCanciones &a,const  string s, Cancion &c, bool &error);
void anyadirCancion(albumCanciones &a,const string s,const Cancion c);
void eliminarCancion(albumCanciones &a, int puesto);
void puestodeCancion(const albumCanciones &a,const string s, int &puesto, bool &error);
void canciondePuesto(const albumCanciones &a, int puesto, string &clave, bool &error);
void intercambiarCanciones( albumCanciones &a,const string s,const string b);
void listarAlbum( albumCanciones &a);

struct albumCanciones{
   friend void crear(albumCanciones &a,string titulo);
   friend int numCanciones(const albumCanciones &a);
   friend int duracion (const albumCanciones &a);
   friend string tituloDeAlbum(const albumCanciones &a);
   friend bool existeCancion(const albumCanciones &a,const string s);
   friend void obtenerCancion(const albumCanciones &a,const string s, Cancion &c, bool &error);
   friend void anyadirCancion(albumCanciones &a,const string s,const Cancion c);
   friend void eliminarCancion(albumCanciones &a, int puesto);
   friend void puestodeCancion(const albumCanciones &a,const string s, int &puesto, bool &error);
   friend void canciondePuesto(const  albumCanciones &a, int puesto, string &clave, bool &error);
   friend void intercambiarCanciones( albumCanciones &a,const string s,const string b);
   friend void listarAlbum( albumCanciones &a);

private:
    string tituloAlbum;
    Recopilacion<string,Cancion> Canciones;
    int duracionTotal;
};
#endif ALBUMCANCIONES_H