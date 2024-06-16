// Nodo del arbol
struct nodeArbol{
    int dato;
    nodeArbol* izq = nullptr;
    nodeArbol* der = nullptr;
};

// Codigo de pilas
struct nodoPila{
    nodeArbol* dato;
    nodoPila* link = nullptr;
};

bool isEmpty(nodoPila* pila){
    if (pila == nullptr)
        return true;
    return false;
}

void push(nodoPila* &pila, nodeArbol* dato){
    nodoPila* nuevoNodo = new nodoPila;
    nuevoNodo->dato = dato;
    if (pila == nullptr)
        pila = nuevoNodo;
    else{
        nuevoNodo->link = pila;
        pila = nuevoNodo;
    }
}

nodeArbol* pop(nodoPila* &pila){
    if (isEmpty(pila))
        return 0;

    nodeArbol* dato = pila->dato;
    nodoPila* nodoAremover = pila;
    pila = pila->link;

    delete nodoAremover;
    return dato;
}

// Codigo para COLAS
struct nodoCola{
    nodeArbol* nodo;    // Informacion de la pila
    int altura;         // Altura del nodo que guarda, lo uso para un ejercicio
    nodoCola* link = nullptr;
};

bool ColaVacia(nodoCola* frente){
    if (frente == nullptr)
        return true;
    return false;
}

void insert(nodoCola* &frente, nodoCola* &fondo, nodeArbol* nodo){
    nodoCola* nuevo_nodo = new nodoCola;
    nuevo_nodo->nodo = nodo;
    if (ColaVacia(frente))
        frente = fondo = nuevo_nodo;
    else {
        fondo->link = nuevo_nodo;
        fondo = nuevo_nodo;
    }
}

// Inserta tambien la altura
void insert(nodoCola* &frente, nodoCola* &fondo, nodeArbol* nodo, int altura){
    nodoCola* nuevo_nodo = new nodoCola;
    nuevo_nodo->nodo = nodo;
    nuevo_nodo->altura = altura;
    if (ColaVacia(frente))
        frente = fondo = nuevo_nodo;
    else {
        fondo->link = nuevo_nodo;
        fondo = nuevo_nodo;
    }
}

nodeArbol* get(nodoCola* &frente, nodoCola* &fondo){
    if (!ColaVacia(frente)){
        nodeArbol* nodo = frente->nodo;
        nodoCola* aux = frente;

        if (frente == fondo)
            fondo = nullptr;

        frente = frente->link;
        delete aux;
        return nodo;
    }
    return nullptr;
}

// Obtiene tambien la altura
nodeArbol* get(nodoCola* &frente, nodoCola* &fondo, int &altura){
    if (!ColaVacia(frente)){
        nodeArbol* nodo = frente->nodo;
        altura = frente->altura;
        nodoCola* aux = frente;

        if (frente == fondo)
            fondo = nullptr;

        frente = frente->link;
        delete aux;
        return nodo;
    }
    return nullptr;
}

