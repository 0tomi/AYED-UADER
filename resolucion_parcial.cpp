#include <iostream>
using namespace std;

// ## EJ1

struct nene{
    string nombre, nombre_tutor;
    int edad;
    float distancia;
    string salita;
};

struct nodoLDE{
    nodoLDE* sig =  NULL;
    nodoLDE* ant = NULL;
    nene* info;
};

struct nodoPila{
    nodoLDE* link =  NULL;
    nene* info;    
};

void pilaInsertar(nodoPila* &pila, nene* nuevoDato);

void removerNodo(nodoLDE* &lista){
    nodoLDE* aux = lista;
    if (lista->ant == NULL){
        lista = lista->sig;
        delete aux;
    } else {
        aux->ant->sig = aux->sig;
        if (aux->sig != NULL)
            aux->sig->ant = aux->ant;
        delete aux;
    }
}

void decidirCualNodoEliminar(nodoLDE* &lista, nodoLDE* nodo){
    if (lista == nodo)
        removerNodo(lista);
    else removerNodo(nodo);
}

void InsertarNeneEnSala(nodoLDE* &lista, nodoLDE* nodo, nodoPila* &Sala){
    pilaInsertar(Sala, nodo->info);
    decidirCualNodoEliminar(lista,nodo);
}

bool puedeSalitaVerde (nene* Info){
    return (Info->edad < 4) && (Info->edad > 2) && (Info->distancia > 2);
}

bool puedeSalitaNegra (nene* Info){
    return (Info->edad < 6) && (Info->edad >= 4) && (Info->distancia > 2);
}

void funcionEj1(nodoLDE* &lista, nodoPila* &SalitaVerde, nodoPila* &SalitaNegra){
    nodoLDE* aux = lista; nodoLDE* aux2;
    while (aux != NULL){
        aux2 = aux->sig;
        if (puedeSalitaVerde(aux->info))
            InsertarNeneEnSala(lista,aux,SalitaVerde);
        else if (puedeSalitaNegra(aux->info))
            InsertarNeneEnSala(lista,aux,SalitaNegra);
        
        aux = aux2;
    }
}

// ## EJ5

struct nodoArbolTERNARIO{
    int dato;

    nodoArbolTERNARIO* izq;
    nodoArbolTERNARIO* der;
    nodoArbolTERNARIO* medio;
};

void BarridoRID(nodoArbolTERNARIO* arbol){
    if (arbol == nullptr)
        cout << "Arbol vacio";
    else{
        nodoPila* pila = nullptr; nodoArbolTERNARIO* aux;
        pilaInsertar(pila,arbol);
        while (!isEmpty(pila)){
            aux = pop(pila);

            // Procesamiento
            cout << aux->dato << " ";
            
            if (aux->der != nullptr)
                push(pila,aux->der);
            if (aux->medio != nullptr)
                push(pila,aux->medio);
            if (aux->izq != nullptr)
                push(pila,aux->izq);
        }
    }
}

void BARRIDORID(nodoArbolTERNARIO* arbol){
    if (arbol != NULL){
        cout << arbol->dato << " ";
        BARRIDORID(arbol->izq);
        BARRIDORID(arbol->medio);
        BARRIDORID(arbol->der);
    }
}