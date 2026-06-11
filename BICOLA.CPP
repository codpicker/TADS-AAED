template<typename T>
class Bicola{
    public:
        Bicola(size_t tmax);
        void BicolaPopFin();
        void BicolaPushInicio(const T& x)
    
        private:
            T* elemento;
            int tmax,lamx,inicio,fin;
};

Bicola::Bicola(size_t tmax)
{
    elemento=(new T[tmax+1])
    lmax=tmax+1
    inicio=0
    fin=tmax
}

void BicolaPopFin()
{
    assert(!vacia())
    fin=fin-1%lmax
}


void BicolaPushInicio(const T& x)
{
    assert(!llena())
    inicio=iniicio-1%lmax
    elemento[inicio]=&x
}