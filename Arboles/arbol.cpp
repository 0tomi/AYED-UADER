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

// Inserta nodos y es capaz de reacomodar el arbol en caso de organizarlo mal (no me gusta como quedo)
void BTinsert_V2(nodeArbol* &arbol, int nuevoDato){     
    nodeArbol* newnode = new nodeArbol;
    newnode->dato = nuevoDato;
    if (arbol == nullptr)
        arbol = newnode;
    else if (arbol->izq != nullptr && (arbol->izq->dato < nuevoDato && arbol->dato > nuevoDato)){
            nodeArbol* aux = arbol;
            arbol = newnode;
            arbol->izq = aux->izq;
            arbol->der = aux;
            aux->izq = nullptr;
    }
    else  if (nuevoDato < arbol->dato)
        BTinsert_V2(arbol->izq, nuevoDato);
    else if (nuevoDato > arbol->dato)
        BTinsert_V2(arbol->der, nuevoDato);
}

// Inserta nodos en el arbol
void BTinsert(nodeArbol* &arbol, int data){
    nodeArbol* node = new nodeArbol;
    node->dato = data;
    if (arbol == nullptr)
        arbol = node;
        
    else if (data < arbol->dato)
        BTinsert(arbol->izq, data);
    else if (data > arbol->dato)
        BTinsert(arbol->der, data);
}

// Busca un dato en el arbol binario y avisa si lo encontro, ademas de devolver el nodo
bool BTlook(nodeArbol* arbol, int data, nodeArbol* &node){
    if (arbol == nullptr)
        return false;
    else {
        if (data == arbol->dato){
            node = arbol;
            return true;
        }    
        if (data < arbol->dato)
            BTlook(arbol->izq, data, node);
        else 
            BTlook(arbol->der, data, node);
    }
}

// Lo mismo que la anterior pero sin recursividad, y ademas devuelve el nodo y su padre
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

// Hace un barrido RID y muestra las cosas, pero donde dice procesamiento se pueden implementar mas cosas
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

void BarridoRID_Rec(nodeArbol* arbol){  // Barrido Preorden Recursivo
    if (arbol != nullptr){
        cout << arbol->dato << " ";
        BarridoRID_Rec(arbol->izq);
        BarridoRID_Rec(arbol->der);
    }
}

void BarridoIRD_Rec(nodeArbol* arbol){  // Barrido InOrden Recursivo
    if (arbol != nullptr){
        BarridoIRD_Rec(arbol->izq);
        cout << arbol->dato << " ";
        BarridoIRD_Rec(arbol->der);
    }
}

void BarridoIDR_Rec(nodeArbol* arbol){  // Barrido PostOrden Recursivo
    if (arbol != nullptr){
        BarridoIDR_Rec(arbol->izq);
        BarridoIDR_Rec(arbol->der);
        cout << arbol->dato << " ";
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
    BTinsert_V2(arbol, 2);
    nodeArbol* auxiliar; 

    BarridoRID(arbol);
    cout << endl;
    BarridoIDR_Rec(arbol);

    if (BTlook(arbol, 1, auxiliar))
        cout << endl << auxiliar->der->dato;
    return 0;
}