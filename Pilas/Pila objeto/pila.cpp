#include "pila.h"
nodeStack::nodeStack(int dato)
{
    this->dato = dato;
}

int nodeStack::getDato()
{
    return this->dato;
}

Pila::Pila()
{
    this->last = nullptr;
    this->size = 0;
}

Pila::Pila(int data)
{
    this->last = new nodeStack(data);
    this->size = 1;
}

int Pila::getSize()
{
    return this->size;
}

int Pila::pop()
{
    if (this->last == nullptr)
        return -1;
    else{
        int aux = this->last->getDato();
        nodeStack* aux2 = this->last;
        this->last = aux2->previous;

        delete aux2;
        return aux;
    }
}

bool Pila::insert(int data)
{
    nodeStack* aux = new nodeStack(data);
    if (aux == nullptr)
        return false;
    aux->previous = last;
    last = aux;
    this->size++;
    return true;
}

Pila::~Pila()
{
    while (last != nullptr)
        this->pop();
}
