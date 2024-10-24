// Voy a meter todo en el CPP porque es mas comodo al no estar usando QT
#ifndef LISTADE_CPP
#define LISTADE_CPP
template <class T>
struct par {
    bool finded; 
    T data;
};

template <class Data>
class ListaDE{
private:
    struct Node{
        Data dato;
        Node * next;
        Node * back;
    };
    Node * first;
    Node * last;
    int size;
    Node* look(Data dato) {
        Node* aux = first;
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
        first = last = new Node{data, nullptr, nullptr};
        return;
    }

    first->back = new Node{data, first, nullptr};
    first = first->back;    
}

template<class Data>
void ListaDE<Data>::push_back(Data data)
{
    size++; 
    if (first == nullptr){
        first = last = new Node{data, nullptr, nullptr};
        return;
    }

    last->next = new Node{data, nullptr, last};
    last = last->next;   
}

template<class Data>
bool ListaDE<Data>::kill(Data dat)
{
    Node* dato = this->look(dat);
    if (!dato)
        return false;
    
    this->size--;
    Node * aux;
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
}

template<class Data>
par<Data> ListaDE<Data>::lookFor(Data dato)
{
    Node* nodo = look(dato);
    if (nodo)
        return {true, nodo->dato};
    else return {false};
}

template<class Data>
Data& ListaDE<Data>::operator[](unsigned int n)
{
    Node* aux = first;
    while (n) {
        if (aux->next)
            aux = aux->next;
        n--;
    }

    return aux->dato;
}

template <class Data>
void ListaDE<Data>::clear(){
    Node* aux = first;
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