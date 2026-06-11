#ifndef CARTELERA_HPP
#define CARTELERA_HPP

using namespace std;

#include "listaenla.h"

struct Espectaculo{
    int id_espectaculo;

    Espectaculo(int id):id_espectaculo(id){}
};

struct Sala{
    int id_sala;

    Sala(int id):id_sala(id){}

    Lista<Espectaculo> espectaculos;
    Lista<Espectaculo>::posicion buscaespectaculo(int e);
};

class Cartelera{
    public: 
        Cartelera();
        void NuevaSala(int sala);
        void NuevoEspectaculo(int sala, int espectaculo);
        void EliminarSala(int sala);
        void EliminarEspectaculo(int sala, int espectaculo);

    private:
        Lista<Sala> salas;
        Lista<Sala>::posicion buscarsala(int sala);
};

//Implementacion de metodos privados
Lista<Sala>::posicion Cartelera::buscarsala(int sala){
    Lista<Sala>::posicion pos=salas.primera();
    while(pos!=salas.fin())
    {
        if(salas.elemento(pos).id_sala==sala)
        {
            return pos;
        }

        pos=salas.siguiente(pos);
    }

    return salas.fin();
}

Lista<Espectaculo>::posicion Sala::buscaespectaculo(int espectaculo)
{
    Lista<Espectaculo>::posicion pos=espectaculos.primera();
    while(pos!=espectaculos.fin())
    {
        if(espectaculos.elemento(pos).id_espectaculo==espectaculo)
        {
            return pos;
        }

        pos=espectaculos.siguiente(pos);
    }

    return espectaculos.fin();
}

//Implementacion del TAD

Cartelera::Cartelera(){}

void Cartelera::NuevaSala(int sala)
{
    Lista<Sala>::posicion pos=buscarsala(sala);
    if(pos==salas.fin()){
        salas.insertar(Sala(sala), salas.fin());
    }
}

void Cartelera::NuevoEspectaculo(int sala, int espectaculo)
{
    Lista<Sala>::posicion pos=buscarsala(sala);
    if(pos!=salas.fin()){
        Lista<Espectaculo>::posicion pose=salas.elemento(pos).buscaespectaculo(espectaculo);
        if(pose==salas.elemento(pos).espectaculos.fin())
        {
            salas.elemento(pos).espectaculos.insertar(Espectaculo(espectaculo), salas.elemento(pos).espectaculos.fin());
        }
    }
}

void Cartelera::EliminarSala(int sala){

    Lista<Sala>::posicion pos=buscarsala(sala);
    if(pos!=salas.fin()){
        salas.eliminar(pos);
    }
}

void Cartelera::EliminarEspectaculo(int sala, int espectaculo)
{
    Lista<Sala>::posicion pos=buscarsala(sala);
    if(pos!=salas.fin()){
        Lista<Espectaculo>::posicion pose=salas.elemento(pos).buscaespectaculo(espectaculo);
        if(pose!=salas.elemento(pos).espectaculos.fin())
        {
            salas.elemento(pos).espectaculos.eliminar(pose);
        }
    }
}

#endif