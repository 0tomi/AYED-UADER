#include "nodos.cpp"
#include "cola.cpp"
#include "pila.cpp"

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

        void BarridoRID_Rec();
        void BarridoIRD_Rec();
        void BarridoIDR_Rec();

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

Arbol::

Arbol::

Arbol::

Arbol::
