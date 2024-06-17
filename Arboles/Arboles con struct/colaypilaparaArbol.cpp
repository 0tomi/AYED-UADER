// Nodo del arbol
struct nodeArbol{
    int dato;
    nodeArbol* izq = nullptr;
    nodeArbol* der = nullptr;
};

// ## Codigo de pilas ##
struct nodoPila{
    nodeArbol* dato;
    int altura;
    nodoPila* link = nullptr;
};

bool isEmpty(nodoPila* pila){
    return (pila == nullptr);
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

// Sobrecarga de las mismas funciones anteriores, pero aca pueden contener alturas tambien.
void push(nodoPila* &pila, nodeArbol* dato, int altura){
    nodoPila* nuevoNodo = new nodoPila;
    nuevoNodo->dato = dato;
    nuevoNodo->altura = altura;
    if (pila == nullptr)
        pila = nuevoNodo;
    else{
        nuevoNodo->link = pila;
        pila = nuevoNodo;
    }
}

nodeArbol* pop(nodoPila* &pila, int &altura){
    if (isEmpty(pila))
        return 0;

    nodeArbol* dato = pila->dato;
    altura = pila->altura;

    nodoPila* nodoAremover = pila;
    pila = pila->link;

    delete nodoAremover;
    return dato;
}

// ## Codigo para COLAS ## 
struct nodoCola{
    nodeArbol* nodo;    // Informacion de la pila
    int altura;         // Altura del nodo que guarda, lo uso para un ejercicio
    nodoCola* link = nullptr;
};

bool ColaVacia(nodoCola* frente){
    return (frente == nullptr);
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

// Sobrecarga de las mismas funciones anteriores, pero aca pueden contener alturas tambien.
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

