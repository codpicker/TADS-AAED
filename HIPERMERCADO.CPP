#ifndef HIPERMERCADO_HPP
#define HIPERMERCADO_HPP

using namespace std;

#include<vector>

#include <cassert>//Importantisimo para los assert


struct Caja{
    int id_cajero;
    double facturacion;
    bool abierta;
};

class Hipermercado{
    public:
        Hipermercado()=default;
        void AbrirCaja(int n,int id);
        double CerrarCaja(int n);
        void CobrarCliente(int caja, double factura);
        void SustituirCajero(int n,int id);
        double CambiarTurno();
        double CerrarCajas();

    private:
        Caja cajas[50];
};



void Hipermercado::AbrirCaja(int n,int id){
    assert(n >= 0 && n < 50);          // La caja existe
    assert(!cajas[n].abierta);        // La caja está cerrada


    cajas[n].abierta=true;
    cajas[n].id_cajero=id;
    cajas[n].facturacion=0.0;
}

double Hipermercado::CerrarCaja(int n){
    assert(n >= 0 && n < 50);          // La caja existe
    assert(cajas[n].abierta);          // La caja está abierta


    cajas[n].abierta=false;
    double recaudado=cajas[n].facturacion;
    cajas[n].facturacion=0.0;

    return recaudado;
}

void Hipermercado::CobrarCliente(int caja, double factura)
{
    assert(caja >= 0 && caja < 50);    // La caja existe
    assert(cajas[caja].abierta);       // La caja está abierta
    assert(factura >= 0);              // Importe válido


    if(cajas[caja].abierta)
    {
        cajas[caja].facturacion+=factura;
    }
}


void Hipermercado::SustituirCajero(int n,int id){
    assert(n >= 0 && n < 50);          // La caja existe
    assert(cajas[n].abierta);          // La caja está abierta

    cajas[n].id_cajero=id;
}

double Hipermercado::CambiarTurno(){
    double recaudacion=0;

    for(int i=0;i<50;i++){
        recaudacion+=cajas[i].facturacion;
        cajas[i].facturacion=0.0;
    }

    return recaudacion;
}

double Hipermercado::CerrarCajas(){
    double recaudacion=0;

    for(int i=0;i<50;i++){
        cajas[i].abierta=false;
        recaudacion+=cajas[i].facturacion;
        cajas[i].facturacion=0.0;
    }

    return recaudacion;
}

#endif
