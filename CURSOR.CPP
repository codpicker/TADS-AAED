#ifndef CURSOR_HPP
#define CURSOR_HPP

#include<iostream>
#include "pilanela.h"



class Cursor{
    public:
        Cursor();
        void AvanzarCursor();
        void BorrarCaracter();
        void RetrasarCursor();
        void BorrarAnterior();
        void Final();
        void InsertarCaracter(char a);
        void Principio();
        void SobreEscribir(char a);
    private:
        Pila<char> Izquierda;//El cursor siempre esta en el tope de la pila izquieda
        Pila<char> Derecha;
};

Cursor::Cursor(){}

void Cursor::AvanzarCursor(){
    if(!Derecha.vacia())
    {
        Izquierda.push(Derecha.tope());
        Derecha.pop();
    }
}

void Cursor::BorrarCaracter(){
        if (!Izquierda.vacia())
        {
            Izquierda.pop();
        }
}

void Cursor::RetrasarCursor(){
    if(!Izquierda.vacia()){
        Derecha.push(Izquierda.tope());
        Izquierda.pop();
    }
}

void Cursor::BorrarAnterior(){
    if(!Izquierda.vacia())
    {
        Derecha.push(Izquierda.tope());
        Izquierda.pop();
        if(!Izquierda.vacia()){
            Izquierda.pop();
        }

    }

}


void Cursor::Final(){
    while(!Derecha.vacia()){
        Izquierda.push(Derecha.tope());
        Derecha.pop();

    }
}

void Cursor::Principio(){

    while(!Izquierda.vacia()){
        Derecha.push(Izquierda.tope());
        Izquierda.pop();
    }
}

void Cursor::InsertarCaracter(char a){
        Izquierda.push(a);
}

void Cursor::SobreEscribir(char a){
    if(!Derecha.vacia()){
        Derecha.pop();   // eliminamos el carácter bajo el cursor
    }
    Izquierda.push(a);   // insertamos el nuevo
}


#endif