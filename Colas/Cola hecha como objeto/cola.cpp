#include "cola.h"

cola::cola()
{
    this->frente = nullptr; 
    this->fondo = nullptr;
    this->length = 0;
}

cola::cola(int data)
{
    nodeC* aux = new nodeC(data);
    this->frente = aux;
    this->fondo = aux;
    this->length = 1;
}

int cola::size()
{
    return this->length;
}

bool cola::add(int data)
{
    nodeC* aux = new nodeC(data);

    if (frente == nullptr && fondo == nullptr){
        frente = aux;
        fondo = aux;
        this->length++;
        return true;
    }

    fondo->next = aux;
    fondo = aux;

    return true;
}

int cola::get()
{
    if (length == 0)
        return -1;
    nodeC* aux = frente;

    int dato = aux->getData();
    frente = frente->next;

    if (aux == fondo)
        fondo = frente;

    delete aux;
    this->length--;
    return dato;
}

cola::~cola()
{
    while (frente != nullptr)
        get();
}

int nodeC::getData()
{
    return this->data;
}

nodeC::nodeC(int data)
{
    this->data = data;
    this->next = nullptr;
}
