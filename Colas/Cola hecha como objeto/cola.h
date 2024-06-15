#ifndef COLA_H
#define COLA_H

class nodeC{
public:
    int getData();
    nodeC(int data);
    nodeC* next;
private:
    int data;
};

class cola
{
public:
    cola();
    cola(int data);
    int size();
    bool add(int data);
    int get();
    ~cola();
private:
    nodeC* frente;
    nodeC* fondo;
    int length;
};

#endif // COLA_H
