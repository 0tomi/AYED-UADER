#include <iostream>
#include "pilaS.cpp"

using namespace std;

struct nodeArbol{
    int dato;
    nodeArbol* izq = nullptr;
    nodeArbol* der = nullptr;
};

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
    return 0;
}