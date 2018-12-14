//**********************************************************************************************************************
// Archivo: coleccionConMarca.h
// Autor:   Andrés Gavín Murillo 716358
// Autor:   Jorge Fernandez Muñoz 721529
// Fecha:   Diciembre 2018
// Coms:    EDA - Práctica 2 - TAD pila
//**********************************************************************************************************************

#ifndef PILA_H
#define PILA_H7

#include <iostream>
using namespace std;
template<typename T> struct Pila;
template<typename T> void crear(Pila<T>&l);
template<typename T> void introducir(Pila<T>&l, T& valor);
template<typename T> int tamanyo(const Pila<T>&l);
template<typename T> bool esVacio(const Pila<T>&l);
template<typename T> void iniciarIterador(Pila<T>&l);
template<typename T> bool existeSiguiente(const Pila<T>&l);
template<typename T> bool siguienteDato(const Pila<T>&l, T& valor);
template<typename T> void liberar(Pila<T>&l);
template<typename T> void avanza(Pila<T>&l);

template<typename T>
struct Pila{
	 friend void crear<T> (Pila<T>&l);
	 friend void introducir<T> (Pila<T>&l,T& valor);
	 friend int tamanyo<T>(const Pila<T>&l);
	 friend bool esVacio<T>(const Pila<T>&l);
	 friend void iniciarIterador<T>(Pila<T>&l);
	 friend bool existeSiguiente<T>(const Pila<T>&l);
	 friend bool siguienteDato<T>(const Pila<T>&l,T& valor);
	 friend void liberar<T>(Pila<T>&l);
    friend void avanza<T>(Pila<T> &l);

	private:
		struct Nodo{
			T valor;
			Nodo *siguiente;
		};
		Nodo *primerDato;		//Puntero al primer nodo del TAD.
		Nodo *ultimoDato;		//Puntero al ultimo nodo del TAD.
		Nodo *iterador;		//Puntero al siguiente nodo a visitar por el iterador, nullptr si esta al final
		int numDatos;			//Numero de datos del TAD.
};


template<typename T> void crear(Pila<T>&l){
	l.primerDato = nullptr;
	l.ultimoDato = nullptr;
	l.iterador = nullptr;
	l.numDatos = 0;
}

template<typename T> void introducir(Pila<T>&l,T& valor){
	typename Pila<T>::Nodo *dato = new typename Pila<T>::Nodo;
	dato->valor = valor;
	dato->siguiente = nullptr;
	if(l.numDatos == 0){
		l.primerDato = dato;
	}else{
		l.ultimoDato->siguiente = dato;
	}
	l.ultimoDato = dato;
	l.numDatos++;
	cout << (l.primerDato == nullptr) <<endl;
}

template<typename T> int tamanyo(const Pila<T>&l){
	return l.numDatos;
}

template<typename T> bool esVacio(const Pila<T>&l){
	return l.primerDato!=nullptr;
}

template<typename T> void iniciarIterador(Pila<T>&l){
	l.iterador = l.primerDato;
	cout << boolalpha << (l.iterador == nullptr)  <<endl;
    cout << (l.primerDato == nullptr) <<endl;
}

template<typename T> bool existeSiguiente(const Pila<T>&l){
	return l.iterador != nullptr;
}

template<typename T> bool siguienteDato(const Pila<T>&l,T& v){
	if(existeSiguiente<T>(l)){
		v = l.iterador->valor;
		return true;
	}

	return false;
}

template<typename T> void liberar(Pila<T>&l){
	typename Pila<T>::Nodo *pAux = l.primerDato, *pAux2;
	while(pAux != nullptr){
		pAux2 = pAux->siguiente;
		delete pAux;
		pAux = pAux2;
	}

	crear<T>(l);
}
template<typename T> void avanza(Pila<T>&l){
    l.iterador = l.iterador->siguiente;
}

#endif PILA_H