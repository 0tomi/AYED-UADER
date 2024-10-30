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

    bool exist(T data) {
        for (int i = 0; i < this->size; i++)
            if (this->data[i] == data)
                return true;
        return false;                
    }
};

template <class T>
struct stack{
    struct nodoP{
        T dato;
        nodoP* link = nullptr;
    };
    nodoP * first;
    int size = 0;

    void push(T dato) {
        size++;
        if (!first){
            first = new nodoP{dato};
            return;
        }

        nodoP * aux = new nodoP{dato};
        aux->link = first;
        first = aux;
    }

    T pop() {
        nodoP* aux = first;
        T dato = first->dato;
        first = first->link;
        delete aux; this->size--;
        return dato;
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

vector<int> getRight(int id_nodo, Nodo * lista){
    vector<int> right;
    auto nodo = busqueda(lista, id_nodo);
    if (!nodo) return right;

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
    while (arco) {
        if (arco->nodoDestino == nodoBuscado)
            return true;
        arco = arco->next;
    }

    return false;
}

vector<int> getLeft(int id_Nodo, Nodo * lista){
    vector<int> left;
    auto nodo = busqueda(lista, id_Nodo);
    if (!nodo) return left;

    while (lista) {
        if (isRight(lista, nodo))
            left.push_back(lista->id_nodo);
        lista = lista->next;
    }
    return left;
}

// consigna 10
// esta funcion se podria readaptar para que 
// devuelva el camino hacia un nodo.
bool isConnectedTo(Nodo* destino, Nodo* origen){
    vector<int> nodos;
    stack<Nodo*> Stack;
    Stack.push(origen);
    while(Stack.size) {
        origen = Stack.pop();
        if (destino->id_nodo == origen->id_nodo){
            nodos.clear();
            return true;
        }

        if (nodos.exist(origen->id_nodo)) continue;
        nodos.push_back(origen->id_nodo);

        auto arcos = origen->arcos;
        while(arcos) {
            if (!nodos.exist(arcos->nodoDestino->id_nodo))
                Stack.push(arcos->nodoDestino);
            arcos = arcos->next;
        }
    }

    nodos.clear();
    return false;
} 

vector<int> getLeftIdeal (int id_Nodo, Nodo* lista){
    vector<int> leftIdeal;
    auto nodo = busqueda(lista, id_Nodo);
    if (!nodo) return leftIdeal;

    while (lista) {
        if (isConnectedTo(nodo, lista) && nodo != lista)
            leftIdeal.push_back(lista->id_nodo);
        lista = lista->next;
    }

    return leftIdeal;
}

// consigna inventada por mi
// es literalmente la misma funcion isConnectedTo, pero te devuelve el vector con los nodos que puede alcanzar.
void cargarNodosDestino(stack<Nodo*> &pila, vector<int> &lista, Arco* arcos){
    while(arcos) {
        if (!lista.exist(arcos->nodoDestino->id_nodo))
            pila.push(arcos->nodoDestino);
        arcos = arcos->next;
    }
}

vector<int> getRightIdeal(int id_Nodo, Nodo* lista){
    vector<int> rightIdeal;
    auto nodo = busqueda(lista, id_Nodo);
    if (!nodo) return rightIdeal;
    
    stack<Nodo*> pila;
    // Cargamos en la pila los nodos con los que se conecta el nodo
    // esto es para evitar cargarlo a si mismo en la primer iteracion 
    // del bucle dentro del right ideal, pero si llegase a estar relacionado
    // consigo mismo, este si se cargaria porque estaria dentro de sus arcos.
    cargarNodosDestino(pila, rightIdeal, nodo->arcos);

    while (pila.size) {
        lista = pila.pop();
        // evitamos iteraciones extras al pasar por un nodo que ya esta en la lista.
        if (rightIdeal.exist(lista->id_nodo)) continue;
        rightIdeal.push_back(lista->id_nodo);

        cargarNodosDestino(pila, rightIdeal, lista->arcos);
    }
    
    return rightIdeal;
}

int main(int argc, char const *argv[])
{
    Nodo * primerNodo = nullptr;
    addNodo(1, primerNodo);
    addNodo(2, primerNodo);
    addNodo(3, primerNodo);
    addNodo(4, primerNodo);
    addArco(primerNodo, 1, 2, 1);
    addArco(primerNodo, 2, 3, 1);
    addArco(primerNodo, 1, 4, 2);
    addArco(primerNodo, 4, 3, 1);
    addArco(primerNodo, 2, 4, 2);

    /*  Representacion:
            1 -> 2
            |  / |
            v .  v   
            4 -> 3
    */

    //killArco(primerNodo, 1, 1, 2);
    MostrarNodos2(primerNodo);

    auto left = getLeft(3, primerNodo);
    cout << "\n\nLeft de 3: \n";
    for (int i = 0; i < left.size; i++)
        cout << left.data[i] << " | ";
    left.clear();

    left = getLeftIdeal(3, primerNodo);
    cout << "\nLeft ideal de 3: \n";
    for (int i = 0; i < left.size; i++)
        cout << left.data[i] << " | ";
    left.clear();

    cout << "\n\nRight ideal de 1: \n";
    auto right = getRightIdeal(1, primerNodo);
    for (int i = 0; i < right.size; i++)
        cout << right.data[i] << " | ";
    right.clear();

    return 0;
}
