#ifndef CUBILETE_HPP
#define CUBILETE_HPP

#include "pilanela.h"

struct Cubo{
    int tama;
    bool abajo;

    Cubo(int t=0, bool a=false):tama(t),abajo(a){}
};

class tCubo{
public:
    Pila<Cubo> ordenarpila(Pila<Cubo> cubos);
};

Pila<Cubo> tCubo::ordenarpila(Pila<Cubo> cubos)
{
    Pila<Cubo> aux;
    Cubo t;


    t = cubos.tope();
    cubos.pop();
    t.abajo = true;
    aux.push(t);

    while(!cubos.vacia())
    {
        t = cubos.tope();
        cubos.pop();
        t.abajo = true;

        while(!aux.vacia() && aux.tope().tama < t.tama)
        {
            cubos.push(aux.tope());
            aux.pop();
        }

        aux.push(t);
    }
    return aux;
}

#endif
