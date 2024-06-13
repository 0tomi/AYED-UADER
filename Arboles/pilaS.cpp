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