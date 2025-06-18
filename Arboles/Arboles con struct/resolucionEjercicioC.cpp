struct nodoArbol{
    int codigo;
    nodoArbol* izq;
    nodoArbol* der; 
};

nodoArbol* ubicarNodo(nodoArbol* arbol, int codigo){
    if (!arbol)
        nullptr;
    if (arbol->codigo)
        return arbol;
    if (codigo < arbol->codigo)
        return ubicarNodo(arbol->izq, codigo);
    else return ubicarNodo(arbol->der, codigo);
}

int getDescendientesNodo(nodoArbol* &nodo){
    if (!nodo)
        return 0;
    int cantidadHijos = 1;
    cantidadHijos += getDescendientesNodo(nodo->izq) + getDescendientesNodo(nodo->der);
    return cantidadHijos;
}

int getNotosDescendientes (nodoArbol* arbol, int codigo){
    auto nodo = ubicarNodo(arbol, codigo);
    int cantidadDescendientes = 0;
    if (nodo) {
        cantidadDescendientes = getDescendientesNodo(nodo)-1;
    }
    return cantidadDescendientes;
}