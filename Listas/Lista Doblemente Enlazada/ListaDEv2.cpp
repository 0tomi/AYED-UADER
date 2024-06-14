#include <iostream>

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

    }
}

// Buscar un dato
bool lookfor(int data, nodeDE* lista, nodeDE* &node){
    while(lista->next != NULL)
        if (lista->data == data){
            node = lista;
            return true;
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
bool deleteList(nodeDE* &lista){

}

// Ordenar lista
void sortList(nodeDE* lista){

}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
