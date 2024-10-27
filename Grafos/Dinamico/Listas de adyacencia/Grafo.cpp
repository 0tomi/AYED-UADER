#include <iostream>
using namespace std;

struct Arco;
struct Nodo;

struct Nodo{
    int id_nodo;
    Nodo * next = nullptr;
    Arco * arcos = nullptr;
    // datos del nodo
};

struct Arco{
    int id_arco;
    Nodo * nodoDestino = nullptr;
    Arco* next = nullptr;
    // funciones del arco + datos
};

void addNodo(int id_nodo,  Nodo* &first){
    auto aux = first;
    while(aux) {
        if (aux->id_nodo == id_nodo)
            return;
        aux = aux->next;
    }
    
    aux = new Nodo{id_nodo, first};
    first = aux;
}

Nodo* busqueda (Nodo * nodos, int id_buscada){
    while (nodos && nodos->id_nodo != id_buscada)
        nodos = nodos->next;

    return nodos;
}

void addArco(Nodo* &first, int id_origen, int id_destino, int id_arco){
    auto origen = busqueda(first, id_origen);
    auto destino = busqueda(first, id_destino);
    if (!origen || !destino)
        return;

    auto aux = origen->arcos;
    while (aux) {
        if (aux->id_arco == id_arco)
            return;
        aux = aux->next;
    }

    aux = new Arco{id_arco, destino, origen->arcos};
    origen->arcos = aux;
}

int main(int argc, char const *argv[])
{
    Nodo * primerNodo = nullptr;
    return 0;
}
