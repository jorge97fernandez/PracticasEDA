//
// Created by jorge on 29/10/2018.
//

#ifndef RECOPILACION_H
#define RECOPILACION_H
template <typename C,typename V> struct Recopilacion;
template <typename C,typename V> Recopilacion<C,V> crear();
template <typename C, typename V> int cardinal(Recopilacion<C,V> &r);
template <typename C, typename V> int tamanyoTotal(Recopilacion<C,V> &r);
template <typename C, typename V> bool existe(Recopilacion<C,V> &r, C &clave);

template <typename C,typename V> struct Recopilacion{
    friend Recopilacion crear<C,V>();
    friend int cardinal<C,V>(Recopilacion &r);
    friend int tamanyoTotal<C,V>(Recopilacion &r);
    friend bool existe<C,V>(Recopilacion &r,C &clave);
private:
    struct Par{
        C clave;
        V valor;
        int puesto;
        Par * anterior;
        Par * siguiente;
    };
    Par * inicial;
    int numDatos;
    int tamanyo;
    Par * iterador;
};

template <typename C,typename V> Recopilacion<C,V> crear(){
    Recopilacion<C,V> r;
    r.numDatos=0;
    r.tamanyo=0;
    r.inicial=nullptr;
    r.iterador=nullptr;
}

template <typename C, typename V> int cardinal(Recopilacion<C,V> &r){
    return r.numDatos;
}

template <typename C, typename V> int tamanyoTotal(Recopilacion<C,V> &r){
    return r.tamanyo;
}

template <typename C, typename V> bool existe(Recopilacion<C,V> &r, C &clave){
    if(r.tamanyo==0){
        return false;
    }
    typename Recopilacion<C,V>::Par *busqueda= new typename Recopilacion<C,V>::Par;
    busqueda= r.inicial;
    while(busqueda!=nullptr){
        if(busqueda->clave==clave){
            return true;
        }
        else{
            busqueda=busqueda->siguiente;
        }
    }
    return false;
}

#endif RECOPILACION_H