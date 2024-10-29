#include <iostream>
using namespace std;

/*
    CPP con la resolucion de ejercicios de la guia 9.
    https://fcytvirtual.uader.edu.ar/pluginfile.php/53386/mod_resource/content/3/guia_9_grafosListaAdy.pdf
*/

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

template <class T>
struct vector{
    T * data = nullptr;
    int size = 0;
    int capacity = 0;
    void resize(int cantidad) {
        T * aux = new T[cantidad];
        for (int i = 0; i < this->size; i++)
            aux[i] = data[i];

        if (this->data)
            delete[] this->data;

        this->data = aux;
        this->capacity = cantidad;
    }

    void push_back(T dato) {
        if (this->size == this->capacity)
            resize(this->size * 2);
        
        this->data[this->size] = dato;
        this->size++;
    }

    void clear() {
        if (this->data)
            delete[] this->data;
        this->size = 0;
        this->capacity = 0;
    }
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

Arco* busqueda(Arco* arco, int id_buscada){
    while (arco && arco->id_arco != id_buscada)
        arco = arco->next;

    return arco;
}

void addArco(Nodo* &first, int id_origen, int id_destino, int id_arco){
    auto origen = busqueda(first, id_origen);
    auto destino = busqueda(first, id_destino);
    if (!origen || !destino)
        return;

    auto aux = busqueda(origen->arcos, id_arco);
    if (aux) return;
    
    aux = new Arco{id_arco, destino, origen->arcos};
    origen->arcos = aux;
}

void MostrarNodos(Nodo* lista){
    Arco* aux;
    while (lista){
        cout << "\nNodo: " << lista->id_nodo; 
        aux = lista->arcos;
        while (aux){
            cout << "\nArco: " << aux->id_arco << " -> Nodo Destino: " << aux->nodoDestino->id_nodo;
            aux = aux->next;
        }
        lista = lista->next;
    }
}

// actividad 2
// funcion recursiva para eliminar un arco
bool killArco(Arco * &arco, int &id_arco){
    if (!arco)
        return false;

    if (arco->id_arco == id_arco) {
        delete arco; arco = nullptr;
        return true;
    } 

    return killArco(arco->next, id_arco);
}

bool killArco(Nodo* lista, int id_arco, int id_origen, int id_destino){
    auto origen = busqueda(lista, id_origen);
    auto destino = busqueda(lista, id_destino);
    if (!origen || !destino)
        return false;

    return killArco(origen->arcos, id_arco);
}

// acitvidad 3
void mostrarNodo(Nodo * nodo){
    if (!nodo) return;

    cout << "\nNodo " << nodo->id_nodo;
    auto arco = nodo->arcos;
    while (arco) {
        cout << "\n   Arco " << arco->id_arco << " -> Nodo " << arco->nodoDestino->id_nodo;
        arco = arco->next;
    }
}

void MostrarNodos2(Nodo * lista){
    while (lista){
        mostrarNodo(lista);
        lista = lista->next;
    }
}

// consigna 6
int getCantidadArcos(Arco * arco){
    int cantidad = 0;
    while (arco) {
        cantidad++;
        arco = arco->next;
    }
    return cantidad;
}

// consigna 8
bool repetido(vector<int> data, int buscar){
    for (int i = 0; i < data.size; i++)
        if (buscar == data.data[i])
            return true;
    return false;
}

vector<int> getRight(Nodo * nodo){
    vector<int> right;
    int cantidadArcos = getCantidadArcos(nodo->arcos);
    if (!cantidadArcos)
        return right;

    auto aux = nodo->arcos;
    while (aux) {
        if (!repetido(right, aux->nodoDestino->id_nodo))
            right.push_back(aux->nodoDestino->id_nodo);
        aux = aux->next;
    }

    return right;
}

// consigna 9
bool isRight(Nodo * nodoOrigen, Nodo * nodoBuscado){
    auto arco = nodoOrigen->arcos;
    while (arco)
        if (arco->nodoDestino == nodoBuscado)
            return true;
        else arco = arco->next;

    return false;
}

vector<int> getLeft(Nodo * listaNodos, Nodo * nodo){
    vector<int> left;
    while (listaNodos) {
        if (isRight(listaNodos, nodo))
            left.push_back(listaNodos->id_nodo);
        listaNodos = listaNodos->next;
    }
    return left;
}

// consigna 10
vector<Nodo*> getLeftNodos(Nodo * listaNodos, Nodo * nodo){
    vector<Nodo*> left;
    while (listaNodos) {
        if (isRight(listaNodos, nodo))
            left.push_back(listaNodos);
        listaNodos = listaNodos->next;
    }
    return left;
}

vector<int> getLeftIdeal(Nodo * listaNodos, Nodo * nodo){
    vector<int> leftIdeal;
    auto left = getLeftNodos(listaNodos, nodo);

}


int main(int argc, char const *argv[])
{
    Nodo * primerNodo = nullptr;
    addNodo(1, primerNodo);
    addNodo(2, primerNodo);
    addArco(primerNodo, 1, 2, 1);
    //killArco(primerNodo, 1, 1, 2);
    MostrarNodos2(primerNodo);

    return 0;
}
