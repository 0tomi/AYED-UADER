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
    int getId() { return id_arco; }
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
    void addArco(Arco arc);
    int getCantidadArcos();
    int checkIfRelacionadoCon(Nodo*);   // 0: No tiene relaciones, mayor a 0, cantidad de relaciones.
    bool checkID_ArcoUsada(int id);
    ~Nodo();
};

Nodo::Nodo(int id_): id_nodo(id_)
{}

void Nodo::addArco(Arco arc)
{
    if (arc.getNodoDestino()->id_nodo == this->id_nodo)
        this->arcos.push_front(arc);
    else this->arcos.push_back(arc);
}

int Nodo::getCantidadArcos()
{
    
}

int Nodo::checkIfRelacionadoCon(Nodo*)
{
    
}

bool Nodo::check

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
    ~Grafo();
};

Grafo::Grafo(/* args */)
{
}

Grafo::~Grafo()
{
}

#endif // !GRAFO_CPP