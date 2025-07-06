struct nodoLDE{
    int data;
    nodoLDE * sig;
    nodoLDE * ant;
};

class LDE{
    public:
        int size() { return this->Size;}
        bool eliminar(int pos);

    private:
        nodoLDE * lista = nullptr;
        int Size = 0;
};

void eliminar2(LDE& lista){
    if (lista.size() % 2 == 0){
        lista.eliminar(lista.size()/2 -1);
        lista.eliminar(lista.size()/2);
    } else lista.eliminar(lista.size()/2);
}

void eliminarNodo(nodoLDE *& lista){
    lista->ant->sig = lista->sig;
    lista->sig->ant = lista->ant;
    delete lista;
}

void eliminarNodosMedio(nodoLDE * &lista){
    if (!lista) return;
    
    nodoLDE * aux = lista;
    int cont = 1;

    while (aux){
        aux = aux->sig;
        cont++;
    }
    aux = lista;
    int cont2 = 0;
    while (cont2 < cont/2){
        aux = aux->sig;
        cont2++;
    }

    if (cont%2 == 0){
        eliminarNodo(aux->ant);
        eliminarNodo(aux);
    } else
        eliminarNodo(aux);
}