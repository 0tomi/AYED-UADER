#include "ListaDE.cpp"
#include <iostream>
using namespace std;

// Prueba para ver si la lista funciona correctamente

int main(int argc, char const *argv[])
{
    ListaDE test(1);
    for (int i = 0; i < 5; i++)
        test.push_back(i*2);
    test.kill(6);    
    cout << test[4];
    return 0;
}
