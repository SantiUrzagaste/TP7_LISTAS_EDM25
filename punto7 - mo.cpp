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
};

// funcion enigma 
// Proposito : muestra  la lista en orden inverso (de atras hacia adelante)
void enigma(Nodo* nodo) {
	if(nodo != nullptr) {
		if(nodo->getSiguiente() == nullptr)
			cout << nodo->getDato() << " ";
		else {
			enigma(nodo->getSiguiente());
			cout << nodo->getDato() << " ";
		}
	}
}

// funcion misterio 
// Proposito : Cuenta los  nodos que  hay en la lista
int misterio(Nodo* nodo) {
	if(nodo == nullptr)
		return 0;
	else
		return misterio(nodo->getSiguiente()) + 1;
}

// funcion desconocido 
// Proposito : Devuelve el ultimo  nodo de la lista
Nodo* desconocido(Nodo* nodo) {
	if(nodo == nullptr || nodo->getSiguiente() == nullptr)
		return nodo;
	else
		return desconocido(nodo->getSiguiente());
}

int main() {
	
	Nodo* n1 = new Nodo(6);
	Nodo* n2 = new Nodo(4);
	Nodo* n3 = new Nodo(9);
	Nodo* n4 = new Nodo(5);
	Nodo* n5 = new Nodo(8);
	
	n1->setSiguiente(n2);
	n2->setSiguiente(n3);
	n3->setSiguiente(n4);
	n4->setSiguiente(n5);
	
	Nodo* inicio = n1;
	
	cout << "Lista original: ";
	Nodo* aux = inicio;
	while (aux != nullptr) {
		cout << aux->getDato() << " ";
		aux = aux->getSiguiente();
	}
	cout << endl;
	// Prueba  enigma
	cout << "enigma (lista en orden inverso): ";
	enigma(inicio);
	
	cout << endl ; 
	// Prueba  misterio
	int cantidad = misterio(inicio);
	cout << "misterio (cantidad de nodos): " << cantidad << endl;
	
	// Prueba  desconocido
	Nodo* ultimo = desconocido(inicio);
	cout << "desconocido (ultimo nodo): " << ultimo->getDato() << endl;
	
	return 0;
}
