#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H
#include <cstddef>  // size_t
#include <algorithm> // swap
#include <cassert>

template <typename T> class Lista {
    struct nodo; // Declaración adelantada privada
public:
    typedef nodo* posicion; // Posición de un elemento
    Lista(); // Requiere ctor. T()
    bool vacia() const;
    size_t tama() const;
    void insertar(const T& x, posicion p); // Requiere T copiable
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // Lec. elto. en Lista const
    T& elemento(posicion p); // Lec/Esc elto. en Lista no=const
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const;
    Lista(const Lista& Lis); // Ctor. de copia, req. T() y T copiable
    Lista& operator =(const Lista& Lis); // Asig. de listas, req. T() y T copiable
    ~Lista(); // Destructor
private:
    struct nodo {
        T elto;
        nodo *ant, *sig;
        nodo(const T& e = T(), nodo* a = nullptr, nodo* s = nullptr)
            : elto(e), ant(a), sig(s) {}
    };

    nodo* L; // Lista doblemente enlazada circular con cabecera
    size_t n; // Longitud de la lista
};

template <typename T>
inline Lista<T>::Lista() :
    L(new nodo), // Crear cabecera
    n(0)
{
    L->ant = L->sig = L; // Estructura circular
}

template <typename T>
inline bool Lista<T>::vacia() const
{
    return n == 0;
}

template <typename T>
inline size_t Lista<T>::tama() const
{
    return n;
}

template <typename T>
inline void Lista<T>::insertar(const T& x, posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    ++n;
}

template <typename T>
inline void Lista<T>::eliminar(posicion p)
{
    assert(p != fin());
    nodo* q = p->sig;
    p->sig = q->sig;
    p->sig->ant = p;
    delete q;
    --n;
}

template <typename T>
inline const T& Lista<T>::elemento(posicion p) const
{
    assert(p != fin());
    return p->sig->elto;
}

template <typename T>
inline T& Lista<T>::elemento(posicion p)
{
    assert(p != fin());
    return p->sig->elto;
} 

template <typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(posicion p) const
{
    assert(p != fin());
    return p->sig;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(posicion p) const
{
    assert(p != primera());
    return p->ant;
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::primera() const
{ 
    return L; 
}

template <typename T>
inline typename Lista<T>::posicion Lista<T>::fin() const
{ 
    return L->ant; 
}

// Constructor de copia
template <typename T>
Lista<T>::Lista(const Lista& Lis) : Lista()
{
    if (!Lis.vacia()) {
        for (nodo* p = Lis.L->sig; p != Lis.L; p = p->sig)
            L->ant = L->ant->sig = new nodo(p->elto, L->ant, L);
        n = Lis.n;
    }
}

// Asignación de listas
template <typename T>
inline Lista<T>& Lista<T>::operator =(const Lista& Lis)
{
    Lista L1(Lis);
    std::swap(L, L1.L);
    std::swap(n, L1.n);
    return *this;
}

// Destructor: vacía la lista y destruye el nodo cabecera
template <typename T> 
Lista<T>::~Lista()
{
    nodo* p;
    while (L != L->sig) {
        p = L->sig;
        L->sig = p->sig;
        delete p;
    }
    delete L;
}

#endif // LISTA_DOBLE_H