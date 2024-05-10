#include <iostream>

using namespace std;

struct nodo{
    int data;
    
    nodo* next = nullptr;
    nodo* back = nullptr;
};

template <typename dataType>
void insertFirst(dataType* &inicio, dataType datos){
    dataType* aux = new dataType;
    *aux = datos;
    if (inicio != nullptr)
        inicio->back = aux;
    aux->next = inicio;
    inicio = aux;
}

template <typename structType>
void deleteNode(structType* &inicio, structType* seek){
    structType* aux = inicio;
    while ((aux->next != nullptr) && (aux != seek))
        aux = aux->next;

    if (aux == seek){
        if (aux->back != nullptr && aux->next != nullptr){
            aux->back->next = aux->next;
            aux->next->back = aux->back;
        } else if (aux->back != nullptr) {
            aux->back->next = nullptr;
            } else if (aux->next != nullptr) {
                aux->next->back = nullptr;
            }
        
        if (inicio == aux)
            inicio = inicio->next;

        delete aux;
    }
        
}

int main(){
    nodo* listaInicio = nullptr;
    nodo aux;

    aux.data = 5;
    insertFirst<nodo>(listaInicio,aux);
    aux.data = 3;
    insertFirst<nodo>(listaInicio,aux);

    deleteNode<nodo>(listaInicio, listaInicio);
    

    return 0;
}