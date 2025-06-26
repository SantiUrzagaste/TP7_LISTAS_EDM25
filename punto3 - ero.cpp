
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

    int buscar_indice(int valor) {
        Nodo* i = inicio;
        int pos = 0;
        while (i != nullptr) {
            if (i->getDato() == valor) {
                return pos;
            }
            i = i->getSiguiente();
            pos++;
        }
        return -1;
    }

    Nodo* buscar_por_indice(int pos) {
        if (pos < 0 || pos >= cant) return nullptr;
        Nodo* i = inicio;
        int cont = 0;
        while (i != nullptr) {
            if (cont == pos) return i;
            i = i->getSiguiente();
            cont++;
        }
        return nullptr;
    }

    int getCantidad() {
        return cant;
    }
};

int main() {
    Lista lista;
    lista.AgregarFinal(new Nodo(10));
    lista.AgregarFinal(new Nodo(20));
    lista.AgregarFinal(new Nodo(30));

    cout << "Indice de 20: " << lista.buscar_indice(20) << endl;
    Nodo* nodo = lista.buscar_por_indice(2);
    if (nodo != nullptr)
        cout << "Elemento en I­ndice 2: " << nodo->getDato() << endl;
    else
        cout << "No encontrado" << endl;

    return 0;
}
