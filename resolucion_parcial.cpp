#include <iostream>
using namespace std;

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

void funcionEj1(nodoLDE* &lista, nodoPila* &SalitaVerde, nodoPila* &SalitaNegra){
    nodoLDE* aux = lista; nodoLDE* aux2;
    while (aux != NULL){
        aux2 = aux->sig;
        if ((aux->info->edad < 4) && (aux->info->edad > 2) && (aux->info->distancia > 2)){
            pilaInsertar(SalitaVerde, aux->info);
            if (lista == aux)
                removerNodo(lista);
            else removerNodo(aux);
        } else if ((aux->info->edad < 6) && (aux->info->edad >= 4) && (aux->info->distancia > 2)){
            pilaInsertar(SalitaNegra, aux->info);
            if (lista == aux)
                removerNodo(lista);
            else removerNodo(aux);
        }
        aux = aux2;
    }
}


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