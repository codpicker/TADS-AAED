#ifndef SIMBOLO_CPP
#define SIMBOLO_CPP

#include "listaenla.h"
#include<string>
using namespace std;

struct Trazo{
    int trazo;
    string sentido; //Arriba, Abajo, Derecha, Izquierda

    Trazo(int n,string s):trazo(n),sentido(s){}
};

class Simbolo{
    public: 
        Simbolo();
        void AnadirTrazo(int n, string s);
        void DesacerTrazo(int n);
        Lista<Trazo> SimetriaX();
        Lista<Trazo> SimetriaY();
        Lista<Trazo> SimetriaXY();
    private:
        Lista<Trazo> principal;

};

Simbolo::Simbolo(){}

void Simbolo::AnadirTrazo(int n, string s){
    principal.insertar(Trazo(n,s), principal.fin());
}

void Simbolo::DesacerTrazo(int n){
    int contador=n;
    Lista<Trazo>::posicion p= principal.fin();
    p=principal.anterior(p);
    while(contador!=0)
    {
        principal.eliminar(p);
        p=principal.anterior(p);
        contador--;
    }
}

Lista<Trazo> Simbolo::SimetriaX(){

    Lista<Trazo> auxiliar=principal;
    Lista<Trazo>::posicion p=auxiliar.primera();
    while(p!=auxiliar.fin())
    {
        string elemento=auxiliar.elemento(p).sentido;
        if (elemento == "Arriba") {
            elemento = "Abajo";
        }
        else if (elemento == "Abajo") {
            elemento = "Arriba";
        }
        else if (elemento == "Derecha") {
            elemento = "Izquierda";
        }
        else if (elemento == "Izquierda") {
            elemento = "Derecha";
        }

        auxiliar.elemento(p).sentido=elemento;
    }
    return auxiliar;
    
}


Lista<Trazo> Simbolo::SimetriaX() {
    Lista<Trazo> aux = principal;
    auto p = aux.primera();

    while (p != aux.fin()) {
        if (aux.elemento(p).sentido == "Arriba")
            aux.elemento(p).sentido = "Abajo";
        else if (aux.elemento(p).sentido == "Abajo")
            aux.elemento(p).sentido = "Arriba";

        p = aux.siguiente(p);
    }
    return aux;
}

Lista<Trazo> Simbolo::SimetriaY() {
    Lista<Trazo> aux = principal;
    auto p = aux.primera();

    while (p != aux.fin()) {
        if (aux.elemento(p).sentido == "Izquierda")
            aux.elemento(p).sentido = "Derecha";
        else if (aux.elemento(p).sentido == "Derecha")
            aux.elemento(p).sentido = "Izquierda";

        p = aux.siguiente(p);
    }
    return aux;
}

Lista<Trazo> Simbolo::SimetriaXY() {
    Lista<Trazo> aux = principal;
    Lista<Trazo>::posicion p = aux.primera();

    while (p != aux.fin()) {
        if (aux.elemento(p).sentido == "Arriba")
            aux.elemento(p).sentido = "Abajo";
        else if (aux.elemento(p).sentido == "Abajo")
            aux.elemento(p).sentido = "Arriba";
        else if (aux.elemento(p).sentido == "Izquierda")
            aux.elemento(p).sentido = "Derecha";
        else if (aux.elemento(p).sentido == "Derecha")
            aux.elemento(p).sentido = "Izquierda";

        p = aux.siguiente(p);
    }
    return aux;
}

#endif
