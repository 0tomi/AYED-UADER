#include "cola.cpp"
#include "pila.cpp"
#include <iostream>
using namespace std;

class Arbol{
    public:
        Arbol();

        bool isEmpty();
        bool insert(int dato);

        bool look(int data);
        bool look(int data, nodeArbol* &node);
        bool look(int data, nodeArbol* &node, nodeArbol* &father);
       
        void BarridoRID();
        void BarridoPorNiveles();
        void BPNv2();
        void BarridoPorAlturas();

        bool remove(int data);
        bool remove(nodeArbol* data);

       // ~Arbol();
    private:
        nodeArbol* root;
        void add(int dato, nodeArbol* &arbol);
};

nodeArbol::nodeArbol(int dato){
    this->dato = dato;
    this->izq = nullptr;
    this->der = nullptr;
}

bool Arbol::isEmpty(){
    if (root == nullptr)
        return true;
    return false;
}

Arbol::Arbol(){
    this->root = nullptr;
}

bool Arbol::insert(int dato){
    nodeArbol* nuevoNodo = new nodeArbol(dato);
    nodeArbol* padre; nodeArbol* hijo;
    if (isEmpty())
        this->root = nuevoNodo;
    else{
        hijo = this->root;
        while (hijo != nullptr){
            // En caso de ser un dato repetido terminamos aca
            if (hijo->dato == dato){
                delete nuevoNodo;
                return false;
            }

            padre = hijo;
            if (dato < hijo->dato)
                hijo = hijo->izq;
            else hijo = hijo->der;
        }
        if (dato < padre->dato)
            padre->izq = nuevoNodo;
        else padre->der = nuevoNodo;
    }
    return true;
}

// No uso este metodo
void Arbol::add(int dato, nodeArbol* &arbol){
    if (arbol == nullptr){
        nodeArbol* nuevoNodo = new nodeArbol(dato);
        arbol = nuevoNodo;
    } else if (dato < arbol->dato)
        this->add(dato, arbol->izq);
    else if (dato > arbol->dato)
        this->add(dato, arbol->der);
}

bool Arbol::look(int data){
    nodeArbol* aux = this->root;
    while (aux != nullptr){
        if (aux->dato == data) 
            return true;

        if (data < aux->dato)
            aux = aux->izq;
        else aux = aux->der;
    }
    return false;
}

bool Arbol::look(int data, nodeArbol* &nodo){
    nodeArbol* aux = this->root;
    while (aux != nullptr){
        if (aux->dato == data){
            nodo = aux;
            return true;
        } 

        if (data < aux->dato)
            aux = aux->izq;
        else aux = aux->der;
    }
    return false;
}

bool Arbol::look(int data, nodeArbol* &nodo, nodeArbol* &padre){
    nodeArbol* arbol = root;
    nodo = padre = nullptr;
    if (arbol != nullptr){    
        nodo = arbol;
        while (nodo != nullptr){
            if (nodo->dato == data)
                return true;
            padre = nodo;
            if (data < nodo->dato)
                nodo = nodo->izq;
            else nodo = nodo->der;
        }
    }
    return false;
}

void Arbol::BarridoRID(){
    nodeArbol* arbol = this->root;
    if (arbol == nullptr)
        cout << "Arbol vacio";
    else{
        Pila pila; nodeArbol* aux;
        pila.insert(arbol);
        while (!pila.isEmpty()){
            aux = pila.pop();

            // Procesamiento
            cout << aux->dato << " ";
            
            if (aux->der != nullptr)
                pila.insert(aux->der);
            if (aux->izq != nullptr)
                pila.insert(aux->izq);
        }
    }
}


void Arbol::BarridoPorNiveles(){
    nodeArbol* arbol = root;
    if (arbol == nullptr)
        cout << "Arbol vacio";
    else{
        cola Cola; nodeArbol* aux;
        Cola.add(arbol);
        while (!Cola.isEmpty()){
            aux = Cola.get();

            // Procesamiento
            cout << aux->dato << " ";
            // Entre estas 2 lineas deberia ir cualquier cosa que quieran procesar

            if (aux->izq != nullptr)
                Cola.add(aux->izq);
            if (aux->der != nullptr)
                Cola.add(aux->der);
        }
    }
} 

void Arbol::BPNv2()

void Arbol::BarridoPorAlturas()
