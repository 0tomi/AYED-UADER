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
   if (arbol != nullptr){  
        node = arbol;  
        while (node != nullptr){
            if (node->dato == data)
                return true;

            if (data < node->dato)
                node = node->izq;
            else node = node->der;
        }
    }
    return false;
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

// ## ELIMINAR UN NODO ##
void insertarRecursivo(nodeArbol* &arbol, nodeArbol* nodo){
    if (arbol == nullptr){
        arbol = nodo;
    } else if (nodo->dato < arbol->dato)
        insertarRecursivo(arbol->izq, nodo);
    else if (nodo->dato > arbol->dato)
        insertarRecursivo(arbol->der, nodo);
}

void BarridoDeNodos(nodeArbol* arbol, nodoCola* &frente, nodoCola* &fondo){
    nodoPila* pila = nullptr;
    push(pila, arbol);
    while(!isEmpty(pila)){
        arbol = pop(pila);

        // Insertamos los nodos que traiga en la cola.
        insert(frente,fondo,arbol); 

        if (arbol->der != nullptr)
            push(pila, arbol->der);
        if (arbol->izq != nullptr)
            push(pila, arbol->izq);

        // Eliminamos los punteros, porque estos nodos cambiaran de posicion.
        arbol->izq = arbol->der = nullptr;
    }       
}

bool eliminarNodo(nodeArbol* &arbol,int dato){
    // Tenemos 4 casos, graficados aca: https://prnt.sc/RhbabCLpXbCY
    nodeArbol* padre; nodeArbol* nodo2delete;
    if (BTlook(arbol, dato, nodo2delete, padre)){
        // Caso 0: Eliminar el nodo raiz o rey
        // Caso 1: Eliminar nodo hoja
        if (nodo2delete->izq == nullptr && nodo2delete->der == nullptr){
            if (padre != nullptr){
                if (padre->izq == nodo2delete)
                    padre->izq = nullptr;
                else padre->der = nullptr;
            } 
            else arbol = nullptr;
            delete nodo2delete;
            return true;
        }
        // Caso 2: Eliminar nodo intermedio sin hijo derecho
        if (nodo2delete->der == nullptr){
            if (padre == nullptr){
                arbol = nodo2delete->izq;
                delete nodo2delete;
            } else 
                padre->izq = nodo2delete->izq; 
        } else {
            // Caso 3: Eliminar nodo intermedio con hijo derecho 
            nodoCola* frente = nullptr; nodoCola* fondo = nullptr;
            BarridoDeNodos(nodo2delete->der, frente, fondo);

            nodeArbol* aux = get(frente,fondo);
            aux->izq = aux->der = nullptr;
            if (padre == nullptr){
                //Caso 3b o 4: Reemplazar raiz
                aux->izq = arbol->izq;
                delete arbol; 
                arbol = aux;
                while(!ColaVacia(frente))
                    insertarRecursivo(aux, get(frente,fondo));
            } else {
                if (padre->izq == nodo2delete)
                    padre->izq = aux;
                else padre->der = aux; 
                aux->izq = nodo2delete->izq;
                delete nodo2delete;
                while(!ColaVacia(frente))
                    insertarRecursivo(aux, get(frente,fondo));
            }
        }
        return true;
    }
    return false;
}

// ## CONTAR NODOS HOJA ##
int contarNodosHoja(nodeArbol* arbol){
    int hojas = 0;
    if (arbol != nullptr){
        nodoPila* pila = nullptr;
        push(pila,arbol);
        while(!isEmpty(pila)){
            arbol = pop(pila);
            if (arbol->izq == nullptr && arbol->der == nullptr)
                hojas++;
            
            if (arbol->izq != nullptr)
                push(pila,arbol->izq);
            if (arbol->der != nullptr)
                push(pila,arbol->der);
        }
    }
    return hojas;
}

void mostrarNodosHoja(nodeArbol* arbol){
    if (arbol != nullptr){
        nodoPila* pila = nullptr;
        push(pila,arbol);
        while(!isEmpty(pila)){
            arbol = pop(pila);
            if (arbol->izq == nullptr && arbol->der == nullptr)
                cout << arbol->dato << " ";
            
            if (arbol->der != nullptr)
                push(pila,arbol->der);
            if (arbol->izq != nullptr)
                push(pila,arbol->izq);
        }
    }
}

int contarHojasRecursivo(nodeArbol* arbol){
    if (arbol == nullptr)
        return 0;
    if (arbol->izq == nullptr && arbol->der == nullptr)
        return 1;

    return contarNodosHoja(arbol->izq) + contarNodosHoja(arbol->der);
}

void mostrarNodosHojaRecursivo(nodeArbol* arbol){
    if (arbol != nullptr){
        if (arbol->izq == nullptr && arbol->der == nullptr)
            cout << arbol->dato << " ";
        mostrarNodosHojaRecursivo(arbol->izq);
        mostrarNodosHojaRecursivo(arbol->der);
    }
}

// ## FUNCIONES PARA TESTEAR ##

void test(){
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
}

void test2(){
    nodeArbol* arbol = nullptr;
    BTinsert(arbol, 10);
    BTinsert(arbol, 15);
    BTinsert(arbol,5);
    BTinsert(arbol,7);
    BTinsert(arbol,6);
    BTinsert(arbol,8);
    BTinsert(arbol, 3);
    BTinsert(arbol, 2);
    BTinsert(arbol, 4);
    BTinsert(arbol, 13);
    BTinsert(arbol, 18);

    // Arbol normal
    BPNv2(arbol);

    cout << endl << endl;
    eliminarNodo(arbol, 5);
    BPNv2(arbol);
}

void test3(){
    nodeArbol* arbol = nullptr;
    BTinsert(arbol, 10);
    BTinsert(arbol, 15);
    BTinsert(arbol,5);
    BTinsert(arbol, 3);
    BTinsert(arbol, 2);
    BTinsert(arbol, 4);
    BTinsert(arbol, 13);
    BTinsert(arbol, 18);

    // Arbol normal
    BPNv2(arbol);

    cout << endl << "\nArbol despues de eliminar el numero 5:\n";
    eliminarNodo(arbol, 5);
    BPNv2(arbol);

    cout << endl << "\nNodos hoja: ";
    mostrarNodosHoja(arbol);
    cout << "\nNodos hoja recursivo: ";
    mostrarNodosHojaRecursivo(arbol);

    cout << "\nCantidad de nodos hoja: "<< contarNodosHoja(arbol);
}

int main(int argc, const char** argv) {
    test3();
    return 0;
}