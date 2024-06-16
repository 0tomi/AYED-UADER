#include <iostream>
#include "cola.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    cola test;
    test.add(6);
    test.add(10);

    cout<< test.get();
    cout << test.get();
   
    return 0;
}
