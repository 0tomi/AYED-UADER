#include <iostream>
#include <stdlib.h>

using namespace std;

/* 
    # Lista Doblemente Enlazada #
    nodeDE = Nodo de la lista Doblemente Enlazada
*/

struct nodeDE{
    // data
    int data;

    // pointers to move around
    nodeDE* next = NULL;
    nodeDE* back = NULL;
};

void MostrarLista(nodeDE* lista){
    while(lista != NULL){
        cout << lista->data << " ";
        lista = lista->next;
    }
}

// Insertar sin orden
void insert(nodeDE* &lista, int nuevoDato){
    nodeDE* newNode = new nodeDE;
    newNode->data = nuevoDato;
    if (lista == NULL)
        lista = newNode;
    else{
        newNode->next = lista;
        lista->back = newNode;
        lista = newNode;
    }
}

// Insertar con orden
void sorted_insert(nodeDE* &lista, int nuevoDato){
    nodeDE* newNode = new nodeDE;
    newNode->data = nuevoDato;
    if (lista == NULL || nuevoDato < lista->data){
        newNode->next = lista;
        if (lista != NULL)
          lista->back = newNode;
        lista = newNode;
    } else {
        nodeDE* aux = lista;
        while(aux->next != NULL && nuevoDato > aux->next->data)
            aux = aux->next;
        newNode->next = aux->next;
        newNode->back = aux;
        if (aux->next != NULL)
            aux->next->back = newNode;
        aux->next = newNode;
    }
}

// Buscar un dato
bool lookfor(int data, nodeDE* lista, nodeDE* &node){
    while(lista->next != NULL){
        if (lista->data == data){
            node = lista;
            return true;
        }
        lista = lista->next;
    }
    
    return false;
}

// Eliminar un nodo
bool delete_node(int data, nodeDE* &lista){
    nodeDE* node2delete;
    if (lookfor(data, lista, node2delete)){
        // Si es el primer nodo
        if (node2delete == lista)
            lista = lista->next;
        // Si es un nodo que esta de por medio
        else if (node2delete->back != NULL && node2delete->next != NULL){
            node2delete->back->next = node2delete->next;
            node2delete->next->back = node2delete->back;
        // Si es un nodo que esta al final
        } else if (node2delete->back != NULL)
            node2delete->back->next = node2delete->next;

        delete node2delete;
        return true;
    }
    return false;
}

// Eliminar la lista
void deleteList(nodeDE* &lista){
    nodeDE* aux;
    while (lista != NULL){
        aux = lista;
        lista = lista->next;
        delete aux;
    }
}

// Ordenar lista
void sortList(nodeDE* &lista){
    nodeDE* aux = lista;
    nodeDE* newlist = NULL;
    while(aux != NULL){
        sorted_insert(newlist, aux->data);
        aux = aux->next;
    }
    deleteList(lista);
    lista = newlist;
}

int main(int argc, char const *argv[])
{
    nodeDE* lista = NULL;
    srand(1);
    for (int i = 0; i < 10; i++)
        insert(lista,rand()%100);

    cout << "Lista desordenada: ";
    MostrarLista(lista);

    sortList(lista);
    cout << "\nLista ordenada: ";
    MostrarLista(lista);

    return 0;
}
