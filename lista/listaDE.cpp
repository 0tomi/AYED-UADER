#include <iostream>

using namespace std;

/* 
    # Lista Doblemente Enlazada #
*/

struct nodeDE{
    // data
    int data;

    // pointers to move around
    nodeDE* next = NULL;
    nodeDE* back = NULL;
};

/* test
void sort2(nodeDE* &list, int data){
        // version 2 usando 2 punteros
        if (list == NULL){
            list = new nodeDE;
            list->data = data;
        } else {
            nodeDE* aux = list;
            nodeDE* auxanterior = list;
            nodeDE* newNode = new nodeDE;
            while((aux != NULL) || (aux->data < data)){
                if (auxanterior->next == NULL)
                    aux = auxanterior->next; 
                auxanterior = aux->next;
            }
            newNode->data = data;
            newNode->next = aux;
            newNode->back = auxanterior->back;
            if (newNode->back == NULL){
                list = newNode;
                auxanterior->back = list;
            } else {
                auxanterior->back->next = newNode;
                auxanterior->back = newNode;
            }
        }
    }
*/

void insert2(nodeDE* &list, int data){
    // 2da version, encadena punteros, y se posiciona siempre en el elemento anterior (n-1)
    nodeDE* nuevo_nodo = new nodeDE;
    nuevo_nodo->data = data;
    if ((list == NULL) || (data < list->data))
    { // inserta el elemento al principio
        nuevo_nodo->next = list;
        if (list != NULL)
            list->back = nuevo_nodo;
        list = nuevo_nodo;
    } else { // el elemento se puede colocar dsps del inicio
        nodeDE* aux = list;
        //           n-1 -> n -> n+1
        // el puntero siempre se colocará sobre n-1
        while((aux->next != NULL) && (aux->next->data < data))
            aux = aux->next;
        nuevo_nodo->next = aux->next;
        nuevo_nodo->back = aux;
        // en caso de que el elemento siguiente exista, lo encadenamos con el nuevo nodo
        if (aux->next != NULL)
            aux->next->back = nuevo_nodo;
        aux->next = nuevo_nodo;
    }
}

void sorted_insert(nodeDE* &list, int data){
    if (list == NULL){
        list = new nodeDE;
        list->data = data;
    } else {
        nodeDE* aux = list;
        nodeDE* newNode = new nodeDE;
        while ((aux->data < data) && (aux->next != NULL))
            aux = aux->next;
        // setting new node
        newNode->data = data;
        // if the node has to be placed between others:
        if ((aux->data > data) || (aux->next != NULL)){
            newNode->next = aux;
            newNode->back = aux->back;
            // linking new node between the old ones
            if (aux->back == NULL)
                list = newNode; //placing the node at the first place
            else
                aux->back->next = newNode;
            aux->back = newNode;
        } else {
            // if the node has to be at the end of the list:
            newNode->back = aux;
            aux->next = newNode;
        }
    }
}

void getNodes(nodeDE* list){
    while(list != NULL){
        cout << list->data << endl;
        list = list->next;
    }
}

int main(int argc, const char** argv) {
    nodeDE* list = NULL;
    for (int i = 1; i < 5; i++)
        insert2(list,i*2);
    getNodes(list);
    return 0;
}