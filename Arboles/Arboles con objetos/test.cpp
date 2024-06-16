#include <iostream>
#include "arbol.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Arbol test;
    test.insert(10);
    test.insert(5);
    test.insert(12);
    test.BarridoRID();
    return 0;
}
