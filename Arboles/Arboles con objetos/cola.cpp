#include "nodos.cpp"

class cola
{
public:
    cola();
    cola(nodeArbol* data);
    int size();

    void add(nodeArbol* data);
    void add(nodeArbol* data, int altura);

    nodeArbol* get();
    nodeArbol* get(int &altura);
    ~cola();
private:
    nodoCola* frente;
    nodoCola* fondo;
    int length;
};

cola::cola()
{
    this->frente = nullptr;
    this->fondo = nullptr;
    this->length = 0;
}

cola::cola(nodeArbol* data)
{
    nodoCola* aux = new nodoCola(data);
    this->frente = aux;
    this->fondo = aux;
    this->length = 1;
}

int cola::size()
{
    return this->length;
}

void cola::add(nodeArbol* data)
{
    nodoCola* aux = new nodoCola(data);

    if (this->frente == nullptr){
        this->frente = aux;
        this->fondo = aux;
        this->length++;
    } else {
        fondo->next = aux;
        this->fondo = aux;
        this->length++;
    }
}

void add(nodeArbol* data, int altura){
    nodoCola* aux = new nodoCola(data,altura);

    if (this->frente == nullptr){
        this->frente = aux;
        this->fondo = aux;
        this->length++;
    } else {
        fondo->next = aux;
        this->fondo = aux;
        this->length++;
    }
}

nodeArbol* cola::get()
{
    if (frente == nullptr)
        return nullptr;
    nodoCola* aux = frente;

    nodeArbol* dato = aux->data;
    frente = frente->next;

    if (aux == fondo)
        fondo = frente;

    delete aux;
    this->length--;
    return dato;
}

nodeArbol* cola::get(int &altura){
    if (frente == nullptr)
        return nullptr;
    nodoCola* aux = frente;

    nodeArbol* dato = aux->data;
    altura = aux->altura;
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


nodoCola::nodoCola(nodeArbol* data)
{
    this->data = data;
    this->next = nullptr;
}

nodoCola::nodoCola(nodeArbol* data, int altura)
{
    this->data = data;
    this->altura = altura;
    this->next = nullptr;
}