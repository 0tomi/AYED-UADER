#include <iostream>

using namespace std;

struct nodeArbol{
    int dato;
    nodeArbol* izq = nullptr;
    nodeArbol* der = nullptr;
};

// Codigo de pilas

struct nodoPila{
    nodeArbol* dato;
    nodoPila* link = nullptr;
};

bool isEmpty(nodoPila* pila){
    if (pila == nullptr)
        return true;
    return false;
}

void insert(nodoPila* &pila, nodeArbol* dato){
    nodoPila* nuevoNodo = new nodoPila;
    nuevoNodo->dato = dato;
    if (pila == nullptr)
        pila = nuevoNodo;
    else{
        nuevoNodo->link = pila;
        pila = nuevoNodo;
    }
}

nodeArbol* pop(nodoPila* &pila){
    if (isEmpty(pila))
        return 0;

    nodeArbol* dato = pila->dato;
    nodoPila* nodoAremover = pila;
    pila = pila->link;

    delete nodoAremover;
    return dato;
}

// Codigo de arboles

void BTinsert(nodeArbol* &arbol, int data){
    nodeArbol* node = new nodeArbol;
    node->dato = data;
    if (arbol == nullptr)
        arbol = node;
    else{
        if (data < arbol->dato)
            BTinsert(arbol->izq, data);
        else if (data > arbol->dato)
            BTinsert(arbol->der, data);
    }
}

bool BTlook(nodeArbol* arbol, int data, nodeArbol* &node){
    if (arbol != nullptr){
        if (arbol->dato == data){
            node = arbol;
            return true;
        }    
        if (data < arbol->dato)
            BTlook(arbol->izq, data, node);
        else 
            BTlook(arbol->der, data, node);
    }
    
    return false;
}

bool BTlook(nodeArbol* arbol, int data, nodeArbol* &node, nodeArbol* &father){
    node = father = nullptr;
    if (arbol != nullptr){    
        node = arbol;
        while (node != nullptr){
            if (node->dato == data)
                return true;
            father = node;
            if (data < node->dato)
                node = node->izq;
            else node = node->der;
        }
    }
    return false;
}

void BarridoRID(nodeArbol* arbol){
    if (arbol == nullptr)
        cout << "Arbol vacio";
    else{
        nodoPila* pila = nullptr; nodeArbol* aux;
        insert(pila,arbol);
        while (!(isEmpty(pila))){
            aux = pop(pila);
            // Procesamiento
            cout << aux->dato << " ";
            
            if (aux->der != nullptr)
                insert(pila,aux->der);
            if (aux->izq != nullptr)
                insert(pila,aux->izq);
        }
    }
}

int main(int argc, const char** argv) {
    nodeArbol* arbol = nullptr;
    BTinsert(arbol, 7);
    
    BTinsert(arbol, 5);
    BTinsert(arbol, 9);
    BTinsert(arbol, 18);
    BTinsert(arbol, 8);
    BTinsert(arbol, 1);
    BTinsert(arbol, 2);
    nodeArbol* auxiliar; 
    if (BTlook(arbol, 18, auxiliar));
        BarridoRID(arbol);
    return 0;
}