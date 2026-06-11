#ifndef TOKENBUS_HPP
#define TOKENBUS_HPP

#include <string>
#include "pilanela.h"

using namespace std;

struct Computador {
    string nombre;
    Computador(const string& n) : nombre(n) {}
};

class TokenBus {
public:
    TokenBus(const string& primerComp);

    void AnadirComputador(const string& nombre);
    void EliminarComputador();
    void PasarToken();
    string QuienTieneToken() const;
    void EnviarTrama(const string& origen, const string& destino);

private:
    static const int MAX = 25;
    Lista<Computador> red;
    Lista<Computador>::posicion token;
};

#endif
