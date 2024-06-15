#include <iostream>
#include "cola.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    cola test(5);
    test.add(6);
    cout << test.size();
    return 0;
}
