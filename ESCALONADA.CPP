    #ifndef ESCALONADA_HPP
    #define ESCALONADA_HPP

    using namespace std;

    #include "listadoble.h"

    struct Salto{
        double x; // identifica el escalón
        double y; // valor del escalón

        Salto(double y_, double x_) : y(y_), x(x_) {}
    };



    class Escalonada{
        public:
            void CrearFuncion(double y, double x);
            void NuevoSalto(double y, double x);
            void EliminarSalto(double x);
            double CalculoFuncion(double punto);
            double ValorMinimo();
            double ValorMaximo();
            void transicion(double w, double z);
            ~Escalonada()=default;

        private:
            Lista<Salto> funciones;
            Lista<Salto>::posicion buscarfuncion(double x);
    };


    Lista<Salto>::posicion Escalonada::buscarfuncion(double x){
        Lista<Salto>::posicion pos=funciones.primera();

        while(pos!= funciones.fin()){
            if(funciones.elemento(pos).x==x)
            {
                return pos;
            }
            pos=funciones.siguiente(pos);
        }

        return funciones.fin();
    }



    void Escalonada::CrearFuncion(double y, double x){
        funciones.insertar(Salto(y,x), funciones.primera());
    }

    void Escalonada::NuevoSalto(double y, double x)
    {
        Lista<Salto>::posicion pos=buscarfuncion(x);
        if(pos==funciones.fin())
        {
            Lista<Salto>::posicion indice=funciones.primera();
            while(indice!=funciones.fin() && x>funciones.elemento(indice).x)
            {
                indice=funciones.siguiente(indice);
            }
            if(x<funciones.elemento(indice).x)
            {
                funciones.insertar(Salto(y,x), funciones.anterior(indice));
            }
            else{
                funciones.insertar(Salto(y,x), funciones.fin());
            }
        }
        else{
            funciones.elemento(pos).y=y;
        }
    }
    
    void Escalonada::EliminarSalto(double x)
    {
        Lista<Salto>::posicion pos=buscarfuncion(x);

        if(pos!=funciones.fin())
        {
            funciones.eliminar(pos);
        }
    }

    double Escalonada::CalculoFuncion(double punto)
    {
        Lista<Salto>::posicion indice=funciones.primera();
        while(indice!=funciones.fin() && punto<funciones.elemento(indice).x)
        {
            indice=funciones.siguiente(indice);
        }

        return funciones.elemento(funciones.anterior(indice)).y;
    }

    double Escalonada::ValorMaximo(){
        if(!funciones.vacia()){
            return funciones.elemento(funciones.primera()).y;
        }
        else{
            return -1;
        }
    }
    double Escalonada::ValorMinimo(){
        if(!funciones.vacia())
        {
            return funciones.elemento(funciones.anterior(funciones.fin())).y;
        }
    }

    void Escalonada::transicion(double w, double z){
        Lista<Salto>::posicion indice=funciones.primera();
        while(indice!=funciones.fin())
        {
            funciones.elemento(indice).y+=w;
            funciones.elemento(indice).x+=z;
            indice=funciones.siguiente(indice);
        }   
    }
#endif

