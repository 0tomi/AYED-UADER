#include <iostream>

using namespace std;

struct ListaSimple{
    int dato;
    ListaSimple* link = NULL;
};

typedef ListaSimple LS;

void agregarItem(LS* &inicio, int data){
    LS* aux = inicio;
    LS* nuevo_nodo  = new LS;
    nuevo_nodo->dato = data;
    if (aux == NULL)
        inicio = nuevo_nodo;
    else{
        while (aux->link != NULL)
            aux = aux->link;
         aux->link = nuevo_nodo;
    }
}

int main(int argc, const char** argv) {
    LS* lista = NULL;
    

    return 0;
}