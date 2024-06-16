class nodeArbol{
    public:
        nodeArbol* izq;
        nodeArbol* der;
        int dato;
        nodeArbol(int dato);
};

class nodoPila{
public:
    nodoPila(nodeArbol* dato);
    nodoPila(nodeArbol* dato, int altura);
    nodoPila* link;

    nodeArbol* dato;
    int altura;
};

class nodoCola{
public:
    nodoCola(nodeArbol* dato);
    nodoCola(nodeArbol* dato, int altura);
    nodoCola* next;

    nodeArbol* data;
    int altura;
};