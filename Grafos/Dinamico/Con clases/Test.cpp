#include "ListaDE.cpp"
#include <iostream>
using namespace std;

// Prueba para ver si la lista funciona correctamente
class hola{
    public: hola() {};
    void hablar() { cout << "hola"; }
};

int main(int argc, char const *argv[])
{
    ListaDE test(1);
    for (int i = 0; i < 5; i++)
        test.push_back(i*2);
    test.kill(6);    
    cout << "Ultimo elemento: " << test.back() << endl;
    cout << "Test tomiterador: \n";
    for (auto it = test.begin(); !it.end(); it++)
        cout << *it << endl;

    ListaDE<hola> test2;
    test2.push_back({});

    for (auto prueb: test2){
        prueb.hablar();
    }

    return 0;
}
