#include <iostream>
using namespace std;

struct nodoPila{
    int dato;
    nodoPila* link = nullptr;
};

bool isEmpty(nodoPila* pila){
    if (pila == nullptr)
        return true;
    return false;
}

void insert(nodoPila* &pila, int dato){
    nodoPila* nuevoNodo = new nodoPila;
    nuevoNodo->dato = dato;
    if (pila == nullptr)
        pila = nuevoNodo;
    else{
        nuevoNodo->link = pila;
        pila = nuevoNodo;
    }
}

int pop(nodoPila* &pila){
    if (isEmpty(pila))
        return 0;

    int dato = pila->dato;
    nodoPila* nodoAremover = pila;
    pila = pila->link;

    delete nodoAremover;
    return dato;
}

int pow(int num, int exp){
    int resultado = 1;
    while (exp){
        resultado *= num;
        exp--;
    }
    return resultado;
}

int Dec2Bin(int numero);

int main(int argc, const char** argv) {
    
    cout << Dec2Bin(75);
    return 0;
}

int Dec2Bin(int numero){
    int binario = 0, peso = 0;
    nodoPila* pila = nullptr;

    while (numero > 0){
        insert(pila, numero%2);
        numero /= 2;
        peso++;
    }

    while(peso){
        binario += pop(pila) * pow(10,peso);
        peso--;
    }
    return binario;
}