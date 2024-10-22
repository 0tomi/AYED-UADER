// Voy a meter todo en el CPP porque es mas comodo al no estar usando QT
template <class T>
struct par {
    bool finded; 
    T data;
};

template <class Data>
class ListaDE{
private:
    struct Node {
        Data dato;
        Node * next;
        Node * back;
    };
    Node * first;
    Node * last;
    int size;
    void del(Node * &nodo, Node * &nodo2mover);
    par<Node*> look(Data);
public:
    ListaDE(Data element) {first = last = nullptr; size = 0; addAtFirst(element);}
    ListaDE() {first = last = nullptr; size = 0;}
    void addAtFirst(Data);
    void addAtFinal(Data);
    bool kill(Data);
    Data& operator[](unsigned int n);
    par<Data> lookFor(Data);
};

template<class Data>
par<Node*> ListaDE::look (Data dato){
    Node* aux = nodo
}

template<class Data>
void ListaDE<Data>::del(Node * &nodo, Node * &nodo2mover)
{
    Node * aux = nodo;
    nodo = nodo2mover;
    delete aux;
}

template<class Data>
void ListaDE<Data>::addAtFirst(Data data)
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
void ListaDE<Data>::addAtFinal(Data data)
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
    par<Data> dato = this->lookFor(dat);
    if (!dato.finded)
        return false;
    
    this->size--;
    Node * aux;
    if (first == last){
        delete first; 
        first = last = nullptr;
        return true;
    }

    if (first->dato == dato.data){
        this->del(first, first->next);
        return true;
    }
        
    if (last->dato == dato.data){
        this->del(last, last->back);
        return true;
    }

    del()
}

template<class Data>
par<Data> ListaDE<Data>::lookFor(Data dato)
{
    
}

template<class Data>
Data& ListaDE<Data>::operator[](unsigned int n)
{
    
}
