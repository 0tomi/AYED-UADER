#include <iostream>
using namespace std;
// ejercicio C

struct router;
struct conexion;

struct router {
    int codigo;
    string pais;
    int cantidadConexiones;
    string marca;
    string fechaCompra;

    conexion * conexiones = nullptr;
    router * next = nullptr;
};

struct conexion {
    string codigo;
    string tipo;
    int velocidad;
    string state;

    router * destino;
    conexion * next = nullptr;
};

int contarEstadosArco(conexion * inicio, string state){
    int cantidadEstados = 0;
    while (inicio){
        if (inicio->state == state){
            cantidadEstados++;
            cout << "El enlace " << inicio->codigo 
            << " que llega a " << inicio->destino->codigo 
            << " esta caido.";
        }
        inicio = inicio->next;
    }
    return cantidadEstados;
}

int contarEstados (router * inicio, string state = "Down"){
    int cantidadEstados = 0;
    
    while (inicio){
        cantidadEstados += contarEstadosArco(inicio->conexiones, state);
        inicio = inicio->next;
    }
    
    return cantidadEstados;
}