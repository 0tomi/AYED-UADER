#include <iostream>
#include "Pila codigo.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    nodoPila* pila = NULL;
    insert(pila, 5);
    insert(pila, 6);
    cout << pop(pila);
    return 0;
}
