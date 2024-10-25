#ifndef GRAFO_CPP
#define GRAFO_CPP
#include "ListaDE.cpp"
class Arco;
class Nodo;

class Arco
{
private:
    int id_arco;
    Nodo * nodoDestino;
    Nodo * nodoOrigen;
public:
    Arco(int id, Nodo* origen, Nodo* destino);
    int id() { return id_arco; }
    Nodo* getNodoOrigen() { return nodoOrigen; }
    Nodo* getNodoDestino() { return nodoDestino; }
    ~Arco();
    // Aca irian las demas funciones del arco
};

Arco::Arco(int id, Nodo* origen, Nodo* destino)
{
    this->id_arco = id; 
    this->nodoOrigen = origen;
    this->nodoDestino = destino;
}

Arco::~Arco()
{
}


class Nodo
{
private:
    int id_nodo;
    // otros datos, que podrian ser template
    ListaDE <Arco> arcos;
public:
    Nodo(int id_nodo);
    int id() { return this->id_nodo; }
    void addArco(Arco arc);
    int getCantidadArcos();
    // 0: No tiene relaciones, mayor a 0, cantidad de relaciones.
    int checkIfRelacionadoCon(int id_Nodo);   
    bool checkID_ArcoUsada(int id);
    // Devuelve el ID de cada nodo que tiene en su right; 0: No tiene right.
    ListaDE<int> getRight();
    ~Nodo();
};

Nodo::Nodo(int id_): id_nodo(id_)
{}

void Nodo::addArco(Arco arc)
{
    if (arc.getNodoDestino()->id() == this->id_nodo)
        this->arcos.push_front(arc);
    else this->arcos.push_back(arc);
}

int Nodo::getCantidadArcos()
{
    return this->arcos.getSize();
}

int Nodo::checkIfRelacionadoCon(int id_Nodo)
{
    auto tamanio = this->arcos.getSize();
    int founded = 0;
    for (auto arco: arcos)
        if (arco.getNodoDestino()->id() == id_Nodo)
            founded++;

    return founded;
}

bool Nodo::checkID_ArcoUsada(int id)
{
    for (auto arco: arcos)
        if (arco.id() == id)
            return true;
    return false;
}

ListaDE<int> Nodo::getRight(){
    ListaDE<int> NodosRight;
    for (auto arco: arcos)
        NodosRight.push_back(arco.id());
    return NodosRight;
}

Nodo::~Nodo()
{
    arcos.clear();
}


class Grafo
{
private:
    ListaDE <Nodo> nodos;
public:
    Grafo(/* args */);
    int getCantidadRelaciones();
    int getCantidadGrafos() { return nodos.getSize(); }
    Nodo& getNodo(int id_Nodo);
    bool find(int id_Nodo);
    bool addNodo(int id_Nodo); // aca se podria pasar por parametro T el dato que guardara el nodo
    void addArco(int id_Arco, int id_NodoOrigen, int id_NodoDestino);
    bool killNodo(int id_Nodo);
    bool killArco(int id_Arco);
    ~Grafo();
};

Grafo::Grafo(/* args */)
{
}

int Grafo::getCantidadRelaciones(){
    int cantidad = 0;
    for (auto it = nodos.begin(); !it.end(); it++)
        cantidad += it->getCantidadArcos();
    return cantidad;
}

bool Grafo::find(int id){
    for (auto it = nodos.begin(); !it.end(); it++)
        if (it->id() == id)
            return true;
    return false;
}

// Si no encuentra el nodo, lo crea.
// Por eso seria ideal usar find antes de llamar a get
Nodo& Grafo::getNodo(int id){
    for (auto nodo: nodos)
        if (nodo.id() == id)
            return nodo;

    Nodo nuevoNodo(id);
    nodos.push_back(nuevoNodo);
    return nodos.back();
}

bool Grafo::addNodo(int id){
    if (this->find(id))
        return false;
    nodos.push_back({id});
    return true;
}



Grafo::~Grafo()
{
}

#endif // !GRAFO_CPP