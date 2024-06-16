#include <iostream>
#include "colaypilaparaArbol.cpp"

/*
    Funciones para manejar un arbol, el nodo del arbol 
    esta definido en el cpp "cola y pila para arbol".
*/

using namespace std;

// ####### Codigo de arboles ########

// ## FUNCIONES PARA INSERTAR NODOS ##
// Inserta nodos y es capaz de reacomodar el arbol en caso de organizarlo mal (no me gusta como quedo)
void BTinsert_V2(nodeArbol* &arbol, int nuevoDato){     
    nodeArbol* newnode = new nodeArbol;
    newnode->dato = nuevoDato;
    if (arbol == nullptr)
        arbol = newnode;
    else if (arbol->izq != nullptr && (arbol->izq->dato < nuevoDato && arbol->dato > nuevoDato)){
            nodeArbol* aux = arbol;
            arbol = newnode;
            arbol->izq = aux->izq;
            arbol->der = aux;
            aux->izq = nullptr;
    }
    else  if (nuevoDato < arbol->dato)
        BTinsert_V2(arbol->izq, nuevoDato);
    else if (nuevoDato > arbol->dato)
        BTinsert_V2(arbol->der, nuevoDato);
}

// Inserta nodos en el arbol
void BTinsert(nodeArbol* &arbol, int data){
    if (arbol == nullptr){
        nodeArbol* node = new nodeArbol;
        node->dato = data;
        arbol = node;
    } else if (data < arbol->dato)
        BTinsert(arbol->izq, data);
    else if (data > arbol->dato)
        BTinsert(arbol->der, data);
}

// ## FUNCIONES DE BUSQUEDA ##
// Busca un dato en el arbol binario y avisa si lo encontro, ademas de devolver el nodo
bool BTlook(nodeArbol* arbol, int data, nodeArbol* &node){
    if (arbol == nullptr)
        return false;
    else {
        if (data == arbol->dato){
            node = arbol;
            return true;
        }    
        if (data < arbol->dato)
            BTlook(arbol->izq, data, node);
        else 
            BTlook(arbol->der, data, node);
    }
}

// Lo mismo que la anterior pero sin recursividad, y ademas devuelve el nodo y su padre
bool BTlook(nodeArbol* arbol, int data, nodeArbol* &node, nodeArbol* &father){
    node = father = nullptr;
    if (arbol != nullptr){    
        node = arbol;
        while (node != nullptr){
            if (node->dato == data)
                return true;
            father = node;
            if (data < node->dato)
                node = node->izq;
            else node = node->der;
        }
    }
    return false;
}

//  ### BARRIDOS ITERATIVOS ###
// Hace un barrido RID y muestra las cosas, pero donde dice procesamiento se pueden implementar mas cosas
void BarridoRID(nodeArbol* arbol){
    if (arbol == nullptr)
        cout << "Arbol vacio";
    else{
        nodoPila* pila = nullptr; nodeArbol* aux;
        push(pila,arbol);
        while (!(isEmpty(pila))){
            aux = pop(pila);

            // Procesamiento
            cout << aux->dato << " ";
            
            if (aux->der != nullptr)
                push(pila,aux->der);
            if (aux->izq != nullptr)
                push(pila,aux->izq);
        }
    }
}

void BarridoPorNiveles(nodeArbol* arbol){
    if (arbol == nullptr)
        cout << "Arbol vacio";
    else{
        nodoCola* frente = nullptr; nodoCola* fondo = nullptr;
        nodeArbol* aux;
        insert(frente,fondo,arbol);
        while (!ColaVacia(frente)){
            aux = get(frente,fondo);

            // Procesamiento
            cout << aux->dato << " ";
            // Entre estas 2 lineas deberia ir cualquier cosa que quieran procesar

            if (aux->izq != nullptr)
                insert(frente,fondo,aux->izq);
            if (aux->der != nullptr)
                insert(frente,fondo,aux->der);
        }
    }
}

void BPNv2(nodeArbol* arbol){   // Barrido por niveles, pero indicando el nivel.
    if (arbol == nullptr)
        cout << "Arbol vacio";
    else{
        int nivel = 0, nivelActual;
        nodoCola* frente = nullptr; nodoCola* fondo = nullptr;
        nodeArbol* aux;
        insert(frente,fondo,arbol,nivel);
        cout << "Nodo rey: ";
        while (!ColaVacia(frente)){
            aux = get(frente,fondo, nivelActual);

            // Procesamiento
            if (nivel != nivelActual)
                cout << "\nNivel " << nivel+1 << ": ";
            cout << aux->dato << " ";

            // Obtener altura actual
            if (nivel < nivelActual)
                nivel = nivelActual;
            
            if (aux->izq != nullptr)
                insert(frente,fondo,aux->izq,nivel+1);
            if (aux->der != nullptr)
                insert(frente,fondo,aux->der,nivel+1);
        }
    }
}

void BarridoPorAlturas(nodeArbol* arbol){   // Barrido por ALTURAS.
    if (arbol == nullptr)
        cout << "Arbol vacio";
    else{
        int altura = 0, alturaActual;
        // Cola para organizar los nodos por niveles
        nodoCola* frente = nullptr; nodoCola* fondo = nullptr;

        // Pila donde guardaremos los nodos
        nodoPila* pila = nullptr;

        insert(frente,fondo,arbol,altura);
        while (!ColaVacia(frente)){
            arbol = get(frente,fondo, alturaActual);

            // Guardamos por niveles los datos en la pila
            push(pila,arbol,alturaActual);

            // Obtener altura actual
            if (altura < alturaActual)
                altura = alturaActual;
            
            if (arbol->der != nullptr)
                insert(frente,fondo,arbol->der,altura+1);
            if (arbol->izq != nullptr)
                insert(frente,fondo,arbol->izq,altura+1);
        }

        // Con la pila cargada, con los nodos ordenados, procedemos a mostrar los nodos por altura.
        int ValorCentinela = 1;
        arbol = pop(pila,altura);
        cout << "\nAltura 0: ";
        cout << arbol->dato << " ";
        while(!isEmpty(pila)){
            arbol = pop(pila,alturaActual);
            if (alturaActual != altura){
                altura = alturaActual;
                cout << "\nAltura " << ValorCentinela++ << ": "; 
            }
            cout << arbol->dato << " ";
        }
    }
}

//   ## BARRIDOS RECURSIVOS ##
void BarridoRID_Rec(nodeArbol* arbol){  // Barrido Preorden Recursivo
    if (arbol != nullptr){
        cout << arbol->dato << " ";
        BarridoRID_Rec(arbol->izq);
        BarridoRID_Rec(arbol->der);
    }
}

void BarridoIRD_Rec(nodeArbol* arbol){  // Barrido InOrden Recursivo
    if (arbol != nullptr){
        BarridoIRD_Rec(arbol->izq);
        cout << arbol->dato << " ";
        BarridoIRD_Rec(arbol->der);
    }
}

void BarridoIDR_Rec(nodeArbol* arbol){  // Barrido PostOrden Recursivo
    if (arbol != nullptr){
        BarridoIDR_Rec(arbol->izq);
        BarridoIDR_Rec(arbol->der);
        cout << arbol->dato << " ";
    }
}

int main(int argc, const char** argv) {
    nodeArbol* arbol = nullptr;
    BTinsert(arbol, 7);
    
    BTinsert(arbol, 5);
    BTinsert(arbol, 9);
    BTinsert(arbol, 18);
    BTinsert(arbol, 8);
    BTinsert(arbol, 1);
    BTinsert_V2(arbol, 2);
    nodeArbol* auxiliar; 

    cout << "\n## Barrido RID  ## " << endl;
    BarridoRID(arbol);
    cout << "\n## Barrido IDR  ## " << endl;
    BarridoIDR_Rec(arbol);
    cout << "\n\n## Barrido por niveles  ## " << endl;
    BPNv2(arbol);
    cout << "\n\n## Barrido por alturas ##  ";
    BarridoPorAlturas(arbol);

    if (BTlook(arbol, 1, auxiliar))
        cout << endl << auxiliar->der->dato;
    return 0;
}