
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
// pila 

class Pila {
private:
    Nodo* tope;
public:
    Pila() {
        tope = nullptr;
    }

    void apilar(Nodo* nuevo) {
        nuevo->setSiguiente(tope);
        tope = nuevo;
    }

    Nodo* desapilar() {
        Nodo* borrado = nullptr;
        if (tope != nullptr) {
            borrado = tope;
            tope = tope->getSiguiente();
            borrado->setSiguiente(nullptr);
        }
        return borrado;
    }

    Nodo* verTope() {
        return tope;
    }
};

// cola 
class Cola {
private:
    Nodo* frente;
    Nodo* fin;
    int cant;
public:
    Cola() {
        frente = nullptr;
        fin = nullptr;
        cant = 0;
    }

    void encolar(Nodo* nuevo) {
        if (frente == nullptr) {
            frente = fin = nuevo;
        } else {
            fin->setSiguiente(nuevo);
            fin = nuevo;
        }
        cant++;
    }

    Nodo* desencolar() {
        Nodo* borrado = nullptr;
        if (frente != nullptr) {
            borrado = frente;
            frente = frente->getSiguiente();
            borrado->setSiguiente(nullptr);
            if (frente == nullptr) fin = nullptr;
            cantidad = cantidad-1;
        }
        return borrado;
    }

    int getCantidad() {
        return cant;
    }
};

int main() {
    Pila pila;
    pila.apilar(new Nodo(1));
    pila.apilar(new Nodo(2));
    cout << "Tope de la pila: " << pila.verTope()->getDato() ;

    Cola cola;
    cola.encolar(new Nodo(5));
    cola.encolar(new Nodo(6));
    cout << "Cantidad en cola: " << cola.getCantidad() ;

    return 0;
}
