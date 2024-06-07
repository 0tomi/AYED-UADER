#ifndef PILA_H
#define PILA_H

class nodeStack{
private:
    int dato;
public:
    nodeStack* previous;

    nodeStack(int dato);
    int getDato();
};

class Pila
{
public:
    Pila();
    Pila(int data);
    int getSize();
    int pop();
    bool insert(int data);
    ~Pila();
private:
    nodeStack* last;
    int size;
};

#endif // PILA_H
