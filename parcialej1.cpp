#include <iostream>
using namespace std;

struct pendejos{
    string nombre_pendejo;
    string nombre_progenitor;
    int edad;
    float distancia;
    int telefono;
    string salita;
};

struct nodoLDE{
    pendejos* dato;
    nodoLDE* siguiente;
    nodoLDE* anterior;
};

struct nodoPila{
    pendejos* dato;
    nodoPila* link;
};

void pilaAgregar(nodoPila* pila, pendejos* dato){

}

void EliminarNodo(nodoLDE* &lista){
    nodoLDE* aux = lista;
    if (lista->anterior == NULL){
        lista = lista->siguiente;
        delete aux;
    } else {
        if (aux->siguiente != NULL)
            aux->siguiente->anterior = aux->anterior;
            
        aux->anterior->siguiente = aux->siguiente;
        delete aux;
    }       
}
void funcionej1(nodoLDE* &lista){
    nodoPila* salitaVerde = NULL;
    nodoPila* salitaNegra = NULL;
    nodoLDE* aux = lista; nodoLDE* aux2;
    while (aux != NULL){
        aux2 = aux->siguiente;
        if (aux->dato->edad < 4 && aux->dato->edad > 2 && aux->dato->distancia < 2){
            pilaAgregar(salitaVerde, aux->dato);
            if (aux == lista){
                EliminarNodo(lista);
            } else EliminarNodo(aux);

        } else if (aux->dato->edad < 6 && aux->dato->edad >= 4 && aux->dato->distancia > 2){
            pilaAgregar(salitaNegra, aux->dato);
            if (aux == lista){
                EliminarNodo(lista);
            } else EliminarNodo(aux);
        }
        aux = aux2;
    }
}