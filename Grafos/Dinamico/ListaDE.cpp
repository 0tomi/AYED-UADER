// Voy a meter todo en el CPP porque es mas comodo al no estar usando QT
#ifndef LISTADE_CPP
#define LISTADE_CPP
template <class T>
struct par {
    bool finded; 
    T data;
};

template <class T>
struct Node{
    T dato;
    Node * next;
    Node * back;
};

/// ################# Locura iterador ##############
template <class Dato>
class Iterador
{
    Node<Dato> * nodo;
public:
    Iterador(Node<Dato> * nodo);
    Iterador(const Iterador<Dato>& otro): nodo(otro.nodo) {}
    bool end() { return this->nodo? false: true; }
    Iterador<Dato>& operator++();
    Iterador<Dato> operator++(int);
    bool operator==(const Iterador<Dato>& otroIterador) { return nodo == otroIterador.nodo; }
    bool operator!=(const Iterador<Dato>& otroIterador) { return nodo != otroIterador.nodo; }
    Dato& operator*() { return nodo->dato; }
    Dato* operator->() { return &(nodo->dato); }
    ~Iterador();
};

template <class Dato>
Iterador<Dato>::Iterador(Node<Dato> * nodo_)
{
    this->nodo = nodo_;
}

template<class Dato>
Iterador<Dato> Iterador<Dato>::operator++(int)
{
    Iterador<Dato> temporal(*this);
    operator++();
    return temporal;
}

template<class Dato>
Iterador<Dato>& Iterador<Dato>::operator++()
{
    if (this->end())
        return *this;
    this->nodo = this->nodo->next;
    return *this;
}

template <class Dato>
Iterador<Dato>::~Iterador()
{
}

template <class Data>
class ListaDE{
private:
    Node<Data> * first;
    Node<Data> * last;
    int size;
    Node<Data>* look(Data dato) {
        Node<Data>* aux = first;
        while (aux != nullptr){
            if (aux->dato == dato)
                return aux;
            aux = aux->next;
        }
        return nullptr;
    }
public:
    ListaDE(Data element) {first = last = nullptr; size = 0; push_front(element);}
    ListaDE() {first = last = nullptr; size = 0;}
    ~ListaDE();
    Iterador<Data> begin() { return Iterador<Data>(first); }
    Iterador<Data> end() { return { nullptr }; }
    Data& front() { return first->dato; }
    Data& back() { return last->dato; }
    void clear();
    void push_back(Data);
    void push_front(Data);
    int getSize() { return size; }
    bool kill(Data);
    Data& operator[](unsigned int n);
    par<Data> lookFor(Data);
};

template<class Data>
void ListaDE<Data>::push_front(Data data)
{
    size++; 
    if (first == nullptr){
        first = last = new Node<Data>{data, nullptr, nullptr};
        return;
    }

    first->back = new Node<Data>{data, first, nullptr};
    first = first->back;    
}

template<class Data>
void ListaDE<Data>::push_back(Data data)
{
    size++; 
    if (first == nullptr){
        first = last = new Node<Data>{data, nullptr, nullptr};
        return;
    }

    last->next = new Node<Data>{data, nullptr, last};
    last = last->next;   
}

template<class Data>
bool ListaDE<Data>::kill(Data dat)
{
    Node<Data>* dato = this->look(dat);
    if (!dato)
        return false;
    
    this->size--;

    if (first == last){
        delete first; 
        first = last = nullptr;
        return true;
    }

    if (first != dato)
        dato->back->next = dato->next;
    else first = dato->next;

    if (last != dato)
        dato->next->back = dato->back;
    else last = dato->back;

    delete dato;
    return true;
}

template<class Data>
par<Data> ListaDE<Data>::lookFor(Data dato)
{
    Node<Data>* nodo = look(dato);
    if (nodo)
        return {true, nodo->dato};
    else return {false};
}

template<class Data>
Data& ListaDE<Data>::operator[](unsigned int n)
{
    Node<Data>* aux = first;
    while (n) {
        if (aux->next)
            aux = aux->next;
        n--;
    }

    return aux->dato;
}

template <class Data>
void ListaDE<Data>::clear(){
    Node<Data>* aux = first;
    while(aux){
        first = first->next;
        delete aux;
        aux = first;
    }
    this->size = 0;
    first = last = nullptr;
}

template <class Data>
ListaDE<Data>::~ListaDE(){
    this->clear();
}

#endif // !LISTADE_CPP