#ifndef GESTOR_HPP
#define GESTOR_HPP

using namespace std;

#include "colaenla.h"
#include<string>
#include<vector>


struct Usuario{
    int id_usuario;

    Cola<string> Urgente;
    Cola<string> No_Urgente;
};

class Impresora{
    public: 
        Impresora(int num_usuarios);
        void NuevoTrabajo(int id,string trabajo, bool es_urgente);
        void EliminarTrabajo();
        void CancelarTrabajos(int id);
    
        private:
            int usuarios=0;
            Cola<int> Turno;
            vector<Usuario> Trabajadores;
           
};


Impresora::Impresora(int num_usuarios): usuarios(num_usuarios), Trabajadores(num_usuarios){}

void Impresora::NuevoTrabajo(int id,string trabajo, bool es_urgente){
   assert(id<usuarios);

   if(es_urgente)
   {
        Trabajadores[id].Urgente.push(trabajo);
   }
   else{
        Trabajadores[id].No_Urgente.push(trabajo);
   }

   Cola<int> aux;
   bool encola=false;

   while(!Turno.vacia())
   {
        if(Turno.frente()==id)
        {
            encola=true;
        }
        aux.push(Turno.frente());
        Turno.pop();
   }
   if(encola==false){
        aux.push(id);
   }

   while(!aux.vacia())
   {
        Turno.push(aux.frente());
        aux.pop();
   }
}

void Impresora::EliminarTrabajo(){
   assert(!Turno.vacia());

   if(!Trabajadores[Turno.frente()].Urgente.vacia())
   {
        Trabajadores[Turno.frente()].Urgente.pop();
   }
   else if (!Trabajadores[Turno.frente()].No_Urgente.vacia()){
        Trabajadores[Turno.frente()].No_Urgente.pop();
   }

   if(!Trabajadores[Turno.frente()].No_Urgente.vacia() || !Trabajadores[Turno.frente()].Urgente.vacia())
   {
        Turno.push(Turno.frente());
   }
   Turno.pop();
}


void Impresora::CancelarTrabajos(int id){
    assert(id<usuarios);

    while(!Trabajadores[id].Urgente.vacia())
    {
        Trabajadores[id].Urgente.pop();
    }

    while(!Trabajadores[id].No_Urgente.vacia())
    {
        Trabajadores[id].No_Urgente.pop();
    }

    Cola<int> aux;

   while(!Turno.vacia())
    {
        if(Turno.frente() != id)
            aux.push(Turno.frente());
        Turno.pop();
    }

    while(!aux.vacia())
    {
        Turno.push(aux.frente());
        aux.pop();
    }
}

#endif