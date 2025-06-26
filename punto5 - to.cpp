#include <iostream>
using namespace std;

class Nodo {
private:
	int dato;
	Nodo* sig;
public:
	Nodo(int d) : dato(d), sig(nullptr) {}
	
	int getDato() { return dato; }
	Nodo* getSiguiente() { return sig; }
	void setSiguiente(Nodo* s) { sig = s; }
	void setDato(int d) { dato = d; }
}

class Lista {
private:
	Nodo* cabeza;
public:
	Lista() : cabeza(nullptr) 
	
	// p5 - a 
	void insertar(int valor) {
		Nodo* nuevo = new Nodo(valor);
		if (cabeza == nullptr) {
			cabeza = nuevo;
		} else {
			Nodo* aux = cabeza;
			while (aux->getSiguiente() != nullptr)
				aux = aux->getSiguiente();
			aux->setSiguiente(nuevo);
		}
	}
	
	void mostrar() {
		Nodo* aux = cabeza;
		while (aux != nullptr) {
			cout << aux->getDato() << " ";
			aux = aux->getSiguiente();
		}
		cout << endl;
	}
	
	// p5 - b 
	void ordenarSeleccion() {
		Nodo* i = cabeza;
		while (i != nullptr) {
			Nodo* min = i;
			Nodo* j = i->getSiguiente();
			while (j != nullptr) {
				if (j->getDato() < min->getDato()) {
					min = j;
				}
				j = j->getSiguiente();
			}
			// Intercambio de datos
			int temp = i->getDato();
			i->setDato(min->getDato());
			min->setDato(temp);
			
			i = i->getSiguiente();
		}
	}
	
	Nodo* getCabeza() { return cabeza; }
};

// p5 - c 
Lista combinarListas(Lista& l1, Lista& l2) {
	Lista resultado;
	Nodo* a = l1.setCabeza();
	Nodo* b = l2.setCabeza();
	
	while (a != nullptr && b != nullptr) {
		if (a->getDato() < b->getDato()) {
			resultado.insertar(a->getDato());
			a = a->getSiguiente();
		} else {
			resultado.insertar(b->getDato());
			b = b->getSiguiente();
		}
	}
	
	// Agregar lo que quede en l1 o l2
	while (a != nullptr) {
		resultado.insertar(a->getDato());
		a = a->getSiguiente();
	}
	while (b != nullptr) {
		resultado.insertar(b->getDato());
		b = b->getSiguiente();
	}
	
	return resultado;
}

int main() {
	// P5-a: crear y mostrar lista
	Lista lista;
	lista.insertar(10)
	lista.insertar(3)
	lista.insertar(7)
	lista.insertar(1)
	
	cout << "Lista original: ";
	mostrar();
	
	// P5-b: ordenar lista por seleccion
	lista.ordenarSeleccion();
	cout << "Lista ordenada: ";
	mostrar();
	
	// P5-c: Combinar dos listas ordenadas
	Lista otraLista;
	otraLista.insertar(2)
	otraLista.insertar(4)
	otraLista.insertar(8)
	
	Lista combinada = combinarListas(lista, otraLista);
	cout << "Lista combinada: ";
	mostrar();
	
	return 0;
}
