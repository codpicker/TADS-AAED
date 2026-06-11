#ifndef CONSULTORIO_HPP
#define CONSULTORIO_HPP

#include<iostream>
#include "colaenla.h"
#include "listaenla.h"

using namespace std;

struct Paciente{
    int id_paciente;

    Paciente(int id):id_paciente(id){}
};

struct Medico{
    int id_medico;

    Medico(int id):id_medico(id){}

    Cola<Paciente> pacientes;
};

class Consultorio{
    public: 
        Consultorio();
        void AltaMedico(int medico);
        void BajaMedico(int medico);
        void NuevoPaciente(int medico, int paciente);
        Paciente Turno(int medico);
        void AtenderPaciente(int medico);
        bool TienePacientes(int medico);

    private:
        Lista<Medico> medicos;
        Lista<Medico>::posicion buscarMedico(int m);
};

//Implementacion de funcion privada
Lista<Medico>::posicion Consultorio::buscarMedico(int m){
    Lista<Medico>::posicion pos=medicos.primera();

    while(pos!=medicos.fin())
    {
        if(medicos.elemento(pos).id_medico==m)
        {
            return pos;
        }
        pos=medicos.siguiente(pos);
    }
    return medicos.fin();
}

Consultorio::Consultorio(){}

void Consultorio::AltaMedico(int medico){
    Lista<Medico>::posicion posMedico=buscarMedico(medico);
    if(posMedico==medicos.fin()){
        medicos.insertar(Medico(medico), medicos.fin());
    }
}

void Consultorio::BajaMedico(int medico)
{
    Lista<Medico>::posicion posMedico=buscarMedico(medico);
    if(posMedico!=medicos.fin()){
        medicos.eliminar(posMedico);
    }
}

void Consultorio::NuevoPaciente(int medico, int paciente){
    Lista<Medico>::posicion posMedico=buscarMedico(medico);
    if(posMedico!=medicos.fin()){
        medicos.elemento(posMedico).pacientes.push(Paciente(paciente));
    }
}

Paciente Consultorio::Turno(int medico){
    Lista<Medico>::posicion posMedico = buscarMedico(medico);
    if(!medicos.elemento(posMedico).pacientes.vacia())
    {
        auto elemento=medicos.elemento(posMedico).pacientes.frente();
        return elemento;
    }
    
}


void Consultorio::AtenderPaciente(int medico){

    Lista<Medico>::posicion posMedico=buscarMedico(medico);
    if(posMedico!=medicos.fin()){
        medicos.elemento(posMedico).pacientes.pop();
    }
}

bool Consultorio::TienePacientes(int medico){
    Lista<Medico>::posicion posMedico = buscarMedico(medico);
    if(!medicos.elemento(posMedico).pacientes.vacia())
    {
        return true;
    }
   return false;
}


#endif