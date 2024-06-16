#include "nodos.cpp"

class Pila
{
public:
    Pila();
    Pila(nodeArbol* data);
    int getSize();
    nodeArbol* pop();
    bool insert(nodeArbol* data);
    ~Pila();
private:
    nodoPila* pila;
    int size;
};

nodoPila::nodoPila(nodeArbol* dato)
{
    this->dato = dato;
    this->link = nullptr;
}

nodoPila::nodoPila(nodeArbol* dato, int altura)
{
    this->dato = dato;
    this->altura = altura;
    this->link = nullptr;
}

Pila::Pila()
{
    this->pila = nullptr;
    this->size = 0;
}

Pila::Pila(nodeArbol* data)
{
    this->pila = new nodoPila(data);
    this->size = 1;
}

int Pila::getSize()
{
    return this->size;
}

nodeArbol* Pila::pop()
{
    if (this->pila == nullptr)
        return nullptr;
    else{
        nodeArbol* aux = this->pila->dato;
        nodoPila* aux2 = this->pila;
        
        this->pila = aux2->link;
        this->size--;

        delete aux2;
        return aux;
    }
}

bool Pila::insert(nodeArbol* data)
{
    nodoPila* aux = new nodoPila(data);
    if (aux == nullptr)
        return false;
    aux->link = pila;
    pila = aux;
    this->size++;
    return true;
}

Pila::~Pila()
{
    while (pila != nullptr)
        this->pop();
}