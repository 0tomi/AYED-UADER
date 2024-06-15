#include <iostream>

/*
    Cola creada usando struct
*/

using namespace std;

struct nodoCola{
    nodoCola* next;
    int dato;
};

// Agrega nodos a la cola
void add(nodoCola* &frente, nodoCola* &fondo, int nuevoDato){
    nodoCola* nuevoNodo = new nodoCola;
    nuevoNodo->dato = nuevoDato;
    if (frente == NULL)
        frente = fondo = nuevoNodo;
    else{
        fondo->next = nuevoNodo;
        fondo = nuevoNodo;
    }
    
}

// Obtiene un nodo de la cola
int get(nodoCola* &frente, nodoCola* &fondo){
    nodoCola* aux = frente;
    frente = frente->next;
    int dato = aux->dato;
    
    if (aux == fondo)
        fondo = NULL;\
    
    delete aux;
    return dato;
}



int main(int argc, char const *argv[])
{
    nodoCola* frente = NULL;
    nodoCola* fondo = NULL;
    for (int i = 0; i < 5; i++)
        add(frente,fondo,i*2);
    
    cout << get(frente,fondo) << " ";
    cout << get(frente,fondo) << " ";
    cout << get(frente,fondo) << " ";

    return 0;
}
