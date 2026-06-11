#ifndef TRESENRAYA_HPP
#define TRESENRAYA_HPP

using namespace std;

#include"listaenla.h"


struct Casilla{
    int fila, columna;

    Casilla(int f, int c): fila(f), columna(c){}
};

class TresEnRaya{
    public:
        TresEnRaya();
        void ColocarFichaJugador(char jugador, int fila, int columna);
        Lista<Casilla> FichasLibres();
        void LiberarCasilla(int fila, int columna);
        bool ComprobarGanador(char jugador);
        bool Empate();
        
        ~TresEnRaya()=default;
    private:
        char tablero[3][3];
};

//Constructor
//Postcondicion: Crear un tablero vacio
TresEnRaya::TresEnRaya(){
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            tablero[i][j]=' ';
        }
    }
}

//Precondicion: Que exista la posicion elegida y este vacia
//Postcondcion: Que se aplique la posicion para ese jugador correctamente
void TresEnRaya::ColocarFichaJugador(char jugador, int fila, int columna){
 
    if(tablero[fila][columna]!='X' && tablero[fila][columna]!='O')
    {
         tablero[fila][columna]=jugador;
    }

           
}

//Precondicion: Que exista la posicion elegida
//Postcondcion: Que se libere la casilla correctamente
void TresEnRaya::LiberarCasilla(int fila, int columna){
    tablero[fila][columna]=' ';

}

//Precondicion: que exista un jugador que tenga fichas en el tablero
//Postcondcion: Que se devuelva si el jugador ha ganado correctamente
bool TresEnRaya::ComprobarGanador(char jugador){

    for(int i=0; i<3; i++){
       if(tablero[i][0]==jugador && tablero[i][1]==jugador && tablero[i][2]==jugador)
       {
            return true;
       }
       if(tablero[0][i]==jugador && tablero[1][i]==jugador && tablero[2][i]==jugador)
       {
            return true;
       }
    }

  
    if(tablero[0][0]==jugador && tablero[1][1]==jugador && tablero[2][2]==jugador)
    {
        return true;
    }
    if(tablero[0][2]==jugador && tablero[1][1]==jugador && tablero[2][0]==jugador)
    {
        return true;
    }

    return false;
}

//Precondicion: que exista un tablero con fichas
//Postcondcion: Que se devuelva si tablero tiene todas sus posiciones ocupadas
bool TresEnRaya::Empate(){

    int contador=0;
    for(int i=0; i<3; i++){
        for(int j=0;j<3; j++){
           
            
            if(tablero[i][j]!=' ')
            {
                contador++;
            }
            
        }
    }

    if(contador == 9 && !ComprobarGanador('X') && !ComprobarGanador('O'))
    {
        return true;
    }


    return false;

}

Lista<Casilla> TresEnRaya::FichasLibres(){

    Lista<Casilla> libres;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(tablero[i][j] == ' ')
            {
                libres.insertar(Casilla(i,j), libres.fin());
            }
        }
    }

    return libres;
}
#endif
