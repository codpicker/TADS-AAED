#ifndef ESCALONADA_HPP
#define ESCALONADA_HPP

#include "Listaenla.h"

// Un salto (xi, yi): a partir de x = xi, f(x) = yi
struct Salto {
    double x;
    double y;

    Salto(double _x, double _y) : x(_x), y(_y) {}
};

class Escalonada {
public:
    Escalonada();

    // Crear una función constante f(x)=y a partir de x
    void CrearFuncion(double y, double x);

    // Añadir o sustituir un salto
    void NuevoSalto(double y, double x);

    // Eliminar el escalón al que pertenece x
    void EliminarEscalon(double x);

    // Calcular f(x)
    double CalculaFuncion(double punto);

    // Calcular mínimo
    double CalcularMinimo();

    // Calcular máximo
    double CalcularMaximo();

    // Traslación: w horizontal, z vertical
    void Translacion(double w, double z);

    // Destruir función
    void Destruir();

    ~Escalonada() = default;

private:
    Lista<Salto> saltos;
};



// ================= IMPLEMENTACIÓN =================

Escalonada::Escalonada() {}


// Crear función constante
void Escalonada::CrearFuncion(double y, double x) {
    saltos = Lista<Salto>();           // Vaciar
    saltos.insertar(Salto(x, y), saltos.primera());
}


// Añadir nuevo salto ordenado por x
void Escalonada::NuevoSalto(double y, double x) {
    Lista<Salto>::posicion pos = saltos.primera();

    while (pos != saltos.fin() && saltos.elemento(pos).x < x) {
        pos = saltos.siguiente(pos);
    }

    // Si ya existe salto en x, se sustituye
    if (pos != saltos.fin() && saltos.elemento(pos).x == x) {
        saltos.elemento(pos).y = y;
    } 
    else {
        saltos.insertar(Salto(x, y), pos);
    }
}


// Eliminar escalón al que pertenece x
void Escalonada::EliminarEscalon(double x) {
    Lista<Salto>::posicion pos = saltos.primera();
    Lista<Salto>::posicion anterior = saltos.fin();

    while (pos != saltos.fin() && saltos.elemento(pos).x <= x) {
        anterior = pos;
        pos = saltos.siguiente(pos);
    }

    if (anterior != saltos.fin()) {
        saltos.eliminar(anterior);
    }
}


// Calcular f(x)
double Escalonada::CalculaFuncion(double punto) {
    Lista<Salto>::posicion pos = saltos.primera();
    double valor = 0;

    while (pos != saltos.fin() && saltos.elemento(pos).x <= punto) {
        valor = saltos.elemento(pos).y;
        pos = saltos.siguiente(pos);
    }

    return valor;
}


// Calcular mínimo
double Escalonada::CalcularMinimo() {
    Lista<Salto>::posicion pos = saltos.primera();
    double minimo = saltos.elemento(pos).y;

    while (pos != saltos.fin()) {
        if (saltos.elemento(pos).y < minimo) {
            minimo = saltos.elemento(pos).y;
        }
        pos = saltos.siguiente(pos);
    }

    return minimo;
}


// Calcular máximo
double Escalonada::CalcularMaximo() {
    Lista<Salto>::posicion pos = saltos.primera();
    double maximo = saltos.elemento(pos).y;

    while (pos != saltos.fin()) {
        if (saltos.elemento(pos).y > maximo) {
            maximo = saltos.elemento(pos).y;
        }
        pos = saltos.siguiente(pos);
    }

    return maximo;
}


// Traslación
void Escalonada::Translacion(double w, double z) {
    Lista<Salto>::posicion pos = saltos.primera();

    while (pos != saltos.fin()) {
        saltos.elemento(pos).x += w;
        saltos.elemento(pos).y += z;
        pos = saltos.siguiente(pos);
    }
}


// Destruir función
void Escalonada::Destruir() {
    saltos = Lista<Salto>();
}

#endif
