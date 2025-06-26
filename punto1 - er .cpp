#include <iostream>
using namespace std;

class Nodo {
private:
    int dato;
    Nodo* sig;
public:
    Nodo(int dato) {
        this->dato = dato;
        this->sig = null;
    }
    int getDato() { return dato; }
    void setDato(int valor) { dato = valor; }
    Nodo* getSiguiente() { return sig; }
    void setSiguiente(Nodo* nuevo) { sig = nuevo; }
};

class Lista {
private:
    Nodo* inicio
public:
    Lista() {
        inicio = nullptr;
    }

    bool estaVacia() {
        return inicio == nullptr;
    }

    void AgregarFinal(Nodo* nuevo) {
        if (estaVacia()) {
            inicio = nuevo;
        } else {
            Nodo* i = inicio;
            while (i->getSiguiente() != nullptr) {
                i = i->getSiguiente();
            }
            i->setSiguiente(nuevo);
        }
    }

    int minimo() {
        if (estaVacia()) return -1;
        Nodo* i = inicio;
        int menor = i->getDato();
        while (i != nullptr) {
            if (i->getDato() < menor) {
                menor = i->getDato();
            }
            i = i->getSiguiente();
        }
        return menor;
    }

    void MostrarLista() {
        Nodo* i = inicio;
        while (i != nullptr) {
            cout << i->getDato() << " ";
            i = i->getSiguiente();
        }
        cout << endl;
    }
};

int main() {
    Lista lista;
    lista.AgregarFinal(new Nodo(6))
    lista.AgregarFinal(new Nodo(4))
    lista.AgregarFinal(new Nodo(9))
    lista.AgregarFinal(new Nodo(5))
    lista.AgregarFinal(new Nodo(8))

    lista.MostrarLista();
    cout << "Minimo: " << lista.minimo() << endl;
    return 0;
}
