#include <iostream>
using namespace std;

// Ejercicio de Dec2Bin en su forma recursiva

string Dec2Bin(int number){
    if (number > 1)
        return Dec2Bin(number/2) + char('0' + number%2);
    return (number == 0) ? "0": "1";
}

int main(int argc, char const *argv[])
{
    cout << Dec2Bin(5); 
    return 0;
}
