#ifndef DICCIONARIO_HPP
#define DICCIONARIO_HPP

using namespace std;

#include "listaenla.h"
#include<string.h>
#include<string>
#include<iostream>
struct Traduccion{
    string palabra;

    Traduccion(string s): palabra(s){}

    Lista<string> palabras_españolas;
    Lista<string>::posicion buscarespanol(string e);
};

class Diccionario{
    public:
        Diccionario();
        void InsertarTraduccion(string ingles, string español);
        void EliminarTraduccion(string ingles, string español);
        bool es_correcta(string ingles, string español );
        void Palabras(string ingles);

        ~Diccionario()=default;
    private:
        Lista<Traduccion> Ingles;
        Lista<Traduccion>::posicion buscarpalabra(string ingles);

};

//Implementacion metodo privado
 Lista<Traduccion>::posicion Diccionario::buscarpalabra(string ingles)
 {
    Lista<Traduccion>::posicion pos=Ingles.primera();
    while(pos!=Ingles.fin())
    {
        if( Ingles.elemento(pos).palabra==ingles)
        {
            return pos;
        }
        pos=Ingles.siguiente(pos);
    }
    return Ingles.fin();
}

 Lista<string>::posicion Traduccion::buscarespanol(string e){
    Lista<string>::posicion pos=palabras_españolas.primera();
    while(pos!=palabras_españolas.fin())
    {
        if( palabras_españolas.elemento(pos)==e)
        {
            return pos;
        }
        pos=palabras_españolas.siguiente(pos);
    }
    return palabras_españolas.fin();
 }

Diccionario::Diccionario(){}


void Diccionario::InsertarTraduccion(string ingles, string español){
    Lista<Traduccion>::posicion pos=buscarpalabra(ingles);
    if(pos!=Ingles.fin())
    {
        Lista<string>::posicion pose=Ingles.elemento(pos).buscarespanol(español);
        if(pose==Ingles.elemento(pos).palabras_españolas.fin())
        {
            Ingles.elemento(pos).palabras_españolas.insertar(español, pose);
        }
    }
    else{
        Ingles.insertar(Traduccion(ingles), Ingles.fin());
        Lista<Traduccion>::posicion pos=buscarpalabra(ingles);
        Lista<string>::posicion pose=Ingles.elemento(pos).buscarespanol(español);
        if(pose==Ingles.elemento(pos).palabras_españolas.fin())
        {
            Ingles.elemento(pos).palabras_españolas.insertar(español, pose);
        }
    }
}

void Diccionario::EliminarTraduccion(string ingles, string español){
    Lista<Traduccion>::posicion pos=buscarpalabra(ingles);
    if(pos!=Ingles.fin())
    {
        Lista<string>::posicion pose=Ingles.elemento(pos).buscarespanol(español);
        if(pose!=Ingles.elemento(pos).palabras_españolas.fin())
        {
            Ingles.elemento(pos).palabras_españolas.eliminar(pose);
        }
    }

}

bool Diccionario::es_correcta(string ingles, string español)
{
    Lista<Traduccion>::posicion pos=buscarpalabra(ingles);
    if(pos!=Ingles.fin())
    {
        Lista<string>::posicion pose=Ingles.elemento(pos).buscarespanol(español);
        if(pose!=Ingles.elemento(pos).palabras_españolas.fin())
        {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void Diccionario::Palabras(string ingles){
    Lista<Traduccion>::posicion pos=buscarpalabra(ingles);
    if(pos!=Ingles.fin())
    {
        if(!Ingles.elemento(pos).palabras_españolas.vacia())
        {
            Lista<string>::posicion pose=Ingles.elemento(pos).palabras_españolas.primera();
            while(pose!=Ingles.elemento(pos).palabras_españolas.fin())
            {
                cout<< "Palabra en español: "<<Ingles.elemento(pos).palabras_españolas.elemento(pose)<<endl;
                pose=Ingles.elemento(pos).palabras_españolas.siguiente(pose);
            }
        }
        else{
            cout<< "No hay palabras que mostrar"<<endl;
        }
    }

}

#endif