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

    if (this->frente == nullptr){
        this->frente = aux;
        this->fondo = aux;
        this->length++;
        return true;
    }

    fondo->next = aux;
    this->fondo = aux;
    this->length++;
    return true;
}

int cola::get()
{
    if (frente == nullptr)
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
