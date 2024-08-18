// fun fact, ALT+O para switchear entre el header y el cpp en vscode

#ifndef __ARBOLAVL_H__
#define __ARBOLAVL_H__
#include <iostream>
class ArbolAVL{
public:
    ArbolAVL(): root(nullptr){};
    ArbolAVL(int dato);
    void insert(int dato);
    int look(int dato);
    friend std::ostream& operator<<(std::ostream& os, ArbolAVL& arbol);
private:
    struct nodo{
        int dato;
        int altura;
        nodo * padre = nullptr;
        nodo * izq = nullptr;
        nodo * der = nullptr;
    };
    nodo * root;
    int alturaNodo(nodo * subArbol);
    int factorEquilibrio(nodo * subArbol);
    void balancear(nodo * &subArbol);
};


#endif // __ARBOLAVL_H__