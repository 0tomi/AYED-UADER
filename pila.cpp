#include <iostream>

using namespace std;

struct pila{
        int dato;
        pila *link = NULL;

        bool agregar(int dato, pila* &prox) { 
            pila* aux = new pila;
            if (aux == NULL)
                return false;
            aux->dato = dato;
            aux->link = prox;
            prox = aux;
            return true;
        }
        int obtener(pila* &ant){
            int dato = ant->dato;
            pila* aux = ant;
            ant = ant->link;
            delete aux;
            return dato;
        };
};

int main(int argc, char const *argv[])
{
    pila* piloide = NULL;
    piloide->agregar(5,piloide);
    cout << piloide->obtener(piloide);
    return 0;
}
