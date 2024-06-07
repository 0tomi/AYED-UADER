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
    int getSize();
    bool push(int data);
    int pop();
    ~cola();
private:
    nodeC* first;
    int size;
};

#endif // COLA_H
