//
// Created by jorge on 11/12/2018.
//

#ifndef COLECCIONCONMARCA_H
#define COLECCIONCONMARCA_H


template<typename C,typename V> struct coleccionConMarca;
template<typename C,typename V> void crear(coleccionConMarca<C,V>& c);
template<typename C,typename V> bool pertenece(coleccionConMarca<C,V>& c,C& clave);
template<typename C,typename V> void anyadir(coleccionConMarca<C,V>& c,C& clave,V& valor);
template<typename C,typename V> int cardinal(coleccionConMarca<C,V>& c);

template<typename C,typename V> bool pertenece_aux(typename coleccionConMarca<C,V>::Nodo *n,C& clave);
template<typename C,typename V> void anyadir_aux(typename coleccionConMarca<C,V>::Nodo *n,C& clave,V& valor);

template <typename C,typename V>struct coleccionConMarca{
    friend void crear<C,V>(coleccionConMarca<C,V>& c);
    friend void anyadir<C,V>(coleccionConMarca<C,V>& c,C& clave,V& valor);
    friend bool pertenece<C,V>(coleccionConMarca<C,V>& c,C& clave);
    friend int cardinal<C,V>(coleccionConMarca<C,V>& c);
private:
    struct Nodo{
        C clave;
        V valor;
        bool marca;
        Nodo* izd;
        Nodo* dch;
    };
    friend bool pertenece_aux<C,V>(typename coleccionConMarca<C,V>::Nodo *n,C& clave);
    friend void anyadir_aux<C,V>(typename coleccionConMarca<C,V>::Nodo *n,C& clave,V& valor);
    Nodo* raiz;
    int numDatos;
};

template<typename C,typename V> void crear(coleccionConMarca<C,V>& c){
    c.raiz= nullptr;
    c.numDatos=0;
}
template<typename C,typename V> bool pertenece_aux(typename coleccionConMarca<C,V>::Nodo *n,C& clave){
    if(n->clave == clave){
        return true;
    }
    else{
        return false;
    }
}
template<typename C,typename V> bool pertenece(coleccionConMarca<C,V>& c,C& clave){
    if(c.raiz== nullptr){
        return false;
    }
    else if( c.raiz->clave == clave){
        return true;
    }
    else if( c.raiz != nullptr && c.raiz->clave > clave && c.raiz->izd != nullptr){
        return pertenece_aux<C,V>(c.raiz->izd ,clave);
    }
    else if( c.raiz != nullptr && c.raiz->clave < clave && c.raiz->dch != nullptr){
        return pertenece_aux<C,V>(c.raiz->dch ,clave);
    }
    else{
        return false;
    }
}
template<typename C,typename V> void anyadir_aux(typename coleccionConMarca<C,V>::Nodo *n,C& clave,V& valor){
    if(n->clave == clave){
        n->valor = valor;
        n->marca = false;
    }
    else{
        if(clave < n->clave && n->izd == nullptr){
            typename coleccionConMarca<C,V>::Nodo*aux;
            aux->clave = clave;
            aux->valor = valor;
            aux->marca = false;
            aux->izd = nullptr;
            aux->dch = nullptr;
            n->izd = aux;
        }
        else if(clave < n->clave && n->izd != nullptr){
            anyadir_aux<C,V>(n->izd,clave,valor);
        }
        else if( clave > n->clave && n->dch == nullptr){
            typename coleccionConMarca<C,V>::Nodo*aux;
            aux->clave = clave;
            aux->valor = valor;
            aux->marca = false;
            aux->izd = nullptr;
            aux->dch = nullptr;
            n->dch = aux;
        }
        else if(clave > n->clave && n->dch != nullptr){
            anyadir_aux<C,V>(n->dch,clave,valor);
        }
    }
}
template<typename C,typename V> void anyadir(coleccionConMarca<C,V>& c,C& clave,V& valor){
    if(c.raiz == nullptr){
        typename coleccionConMarca<C,V>::Nodo* aux;
        aux->clave = clave;
        aux->valor = valor;
        aux->marca = false;
        aux->izd = nullptr;
        aux->dch = nullptr;
        c.raiz = aux;
        c.numDatos = 1;
    }
    else{
        if(clave == c.raiz->clave){
            c.raiz->valor = valor;
            c.raiz->marca = false;
        }
        else{
            if(clave < c.raiz->clave && c.raiz->izd == nullptr){
                typename coleccionConMarca<C,V>::Nodo*aux;
                aux->clave = clave;
                aux->valor = valor;
                aux->marca = false;
                aux->izd = nullptr;
                aux->dch = nullptr;
                c.raiz->izd = aux;

            }
            else if(clave > c.raiz->clave && c.raiz->dch == nullptr){
                typename coleccionConMarca<C,V>::Nodo*aux;
                aux->clave = clave;
                aux->valor = valor;
                aux->marca = false;
                aux->izd = nullptr;
                aux->dch = nullptr;
                c.raiz->dch = aux;
            }
            else{
                if(clave < c.raiz->clave){
                    anyadir_aux<C,V>(c.raiz->izd,clave,valor);
                }
                else if( clave > c.raiz->clave){
                    anyadir_aux<C,V>(c.raiz->dch,clave,valor);
                }
            }
        }
    }

}
template<typename C,typename V> int cardinal(coleccionConMarca<C,V>& c){
    return c.numDatos;
}
#endif COLECCIONCONMARCA_H