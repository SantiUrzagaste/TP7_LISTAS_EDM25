
#include <iostream>
using namespace std;

class Nodo {
private:
    int dato;
    Nodo* sig;
public:
    Nodo(int dato) {
        this->dato = dato;
        this->sig = nullptr;
    }
    int getDato() { return dato; }
    Nodo* getSiguiente() { return sig; }
    void setSiguiente(Nodo* nuevo) { sig = nuevo; }
};

class Lista {
private:
    Nodo* inicio;
    Nodo* fin;
    int cant;
public:
    Lista() {
        inicio = nullptr;
        fin = nullptr;
        cant = 0;
    }

    void AgregarFinal(Nodo* nuevo) {
        if (inicio == nullptr) {
            inicio = fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
        cant++;
    }

    Nodo* EliminarInicio() {
        Nodo* borrado = nullptr;
        if (inicio != nullptr) {
            borrado = inicio;
            inicio = inicio->getSiguiente();
            if (inicio == nullptr) fin = nullptr;
            cant--;
        }
        return borrado;
    }

    int getCantidad() {
        return cant;
    }
};

int main() {
    Lista lista;
    lista.AgregarFinal(new Nodo(1));
    lista.AgregarFinal(new Nodo(2));
    lista.AgregarFinal(new Nodo(3));

    cout << "Cantidad: " << lista.getCantidad() << endl;
    lista.EliminarInicio();
    cout << "Cantidad tras eliminar: " << lista.getCantidad() << endl;

    return 0;
}
