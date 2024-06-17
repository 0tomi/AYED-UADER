#include <iostream>
using namespace std;

struct nodoPila{
	char dato;
	nodoPila* link = NULL;
};

bool pilaVacia(nodoPila* pila){
	return (pila == NULL);
}

void pilaInsertar(nodoPila* &pila, char dato){
	nodoPila* nuevoDato = new nodoPila;
	nuevoDato->dato = dato;
	if (pilaVacia(pila)){
		pila = nuevoDato;
	} else {
		nuevoDato->link = pila;
		pila = nuevoDato;
	}
}

char pilaPop(nodoPila* &pila){
	if (!pilaVacia(pila)){
		char dato = pila->dato;
		nodoPila* aux2 = pila;
		pila = pila->link;
		delete aux2;
		return dato;
		}
	return ' ';
}


string invertirPalabras(string palabra){
	nodoPila* pila = NULL;
	string retorno = "";
	for (size_t i = 0; i < palabra.length(); i++)
		pilaInsertar(pila, palabra[i]);
	while (!pilaVacia(pila))
		retorno += pilaPop(pila) ;
	
	return retorno;
}
	
int main(int argc, char *argv[]) {
	string palabra;
	cout << "ingrese la palabra: ";
	getline(cin,palabra);
	palabra = invertirPalabras(palabra);

	
	cout << "\nPalabra al reves: " << palabra;
	
	return 0;
}

