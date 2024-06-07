#include "cola.h"

cola::cola()
{
    this->first = nullptr;
    this->size = 0;
}

cola::cola(int data)
{
    nodeC* aux = new nodeC(data);
    this->first = aux;
    this->size = 1;
}

int cola::getSize()
{
    return this->size;
}

bool cola::push(int data)
{
    if (first == nullptr){
        first = new nodeC(data);
        this->size++;
        return true;
    }

    nodeC* aux = this->first;
    while(aux->next != nullptr)
        aux = aux->next;
    aux->next = new nodeC(data);

    if (aux->next == nullptr)
        return false;

    this->size++;
    return true;
}

int cola::pop()
{
    if (size == 0)
        return -1;
    nodeC* aux = first;

    int dato = aux->getData();
    first = first->next;

    delete aux;
    this->size--;
    return dato;
}

cola::~cola()
{
    while (first != nullptr)
        pop();
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
