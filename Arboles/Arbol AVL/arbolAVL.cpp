#ifndef __ARBOLAVL_CPP__
#define __ARBOLAVL_CPP__
#include "arbolAVL.h"
/// Aclaraciones:
/// - Un puntero negado (ejemplo: !root), es equivalente a hacer: root == nullptr
///   Debido a que C++ interpreta el nullptr como un 0, podemos utilizar esto para 
///   escribir codigo de una forma mas agil.

ArbolAVL::ArbolAVL(int dato): root(nullptr)
{
    this->insert(dato);
}

void ArbolAVL::insert(int dato)
{
    int altura = 0;
    if (!root){
        // Si la raiz esta vacia, creamos un nuevo nodo y lo insertamos ahi.
        root = new nodo{dato, altura};
        return;
    }
    bool insertado = false;
    nodo * subArbol = root;
    nodo * padre;
    while (subArbol){
        altura++;
        padre = subArbol;
        if (dato < subArbol->dato)
            subArbol = subArbol->izq;
        else if (dato > subArbol->dato)
            subArbol = subArbol->der;
    }
    subArbol = new nodo{dato, altura, padre};

    //this->insertRecursivo(root, dato, 1, insertado);
    

    
}

int ArbolAVL::alturaNodo(nodo * subArbol)
{
    if (!subArbol){
        int aIzq = alturaNodo(subArbol->izq);
        int aDer = alturaNodo(subArbol->der);
        if (aIzq>aDer)
            return 1 + aIzq;
        else 
            return 1 + aDer; 
    } else 
    return 0;
}



#endif // __ARBOLAVL_CPP__
