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
        sorted_insert(list, i*2);

    sorted_insert(list,1);
    sorted_insert(list,7);
    sorted_insert(list,5);
    sorted_insert(list,3);
    getNodes(list);
    return 0;
}