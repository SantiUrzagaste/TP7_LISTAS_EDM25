#include <iostream>
using namespace std;


template <typename T>
class Nodo {
private:
	T dato;
	Nodo<T>* sig;
public:
	Nodo(T d) : dato(d), sig(nullptr) {}
	
	T getDato() { return dato; }
	Nodo<T>* getSiguiente() { return sig; }
	void setSiguiente(Nodo<T>* s) { sig = s; }
};

//lista generica 

template <typename  T>
class Lista {
private:
	Nodo<T>* cabeza;
public:
	Lista() : cabeza(nullptr) {}
	
	void insertar(T valor) {
		Nodo<T>* nuevo = new Nodo<T>(valor);
		if (cabeza == nullptr) {
			cabeza = nuevo;
		} else {
			Nodo<T>* aux = cabeza;
			while (aux->getSiguiente() != nullptr)
				aux = aux->getSiguiente();
			aux->setSiguiente(nuevo);
		}
	}
	
	void mostrar() {
		Nodo<T>* aux = cabeza;
		while (aux != nullptr) {
			cout << aux->getDato() << " ";
			aux = aux->getSiguiente();
		}
		cout << endl;
	}
	
	Nodo<T>* getCabeza() { return cabeza; }
};

// f auxiliar o opcional 
bool esPrimo(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// p6 a 
void contarPrimos(Lista<int>& lista) {
	Nodo<int>* aux = lista.getCabeza();
	int contador = 0  ;
	
	while (aux != nullptr) {
		if (esPrimo(aux->getDato()))
			contador++;
		aux = aux->getSiguiente();
	}
	
	cout << "Cantidad de numeros primos: " << contador << endl;
}

// p6 b 
void contarMayusMinus(Lista<char>& lista) {
	Nodo<char>* aux = lista.getCabeza();
	int mayus = 0  , minus = 0  ;
	
	while (aux != nullptr) {
		char c = aux->getDato();
		if (c >= 'A' && c <= 'Z')
			mayus++;
		else if (c >= 'a' && c <= 'z')
			minus++;
		aux = aux->getSiguiente();
	}
	
	cout << "Mayusculas: " << mayus << endl;
	cout << "Minusculas: " << minus << endl;
}

// ---------- MAIN ----------
int main() {
	// p6 a 
	Lista<int> listaEnteros;
	listaEnteros.insertar(3);
	listaEnteros.insertar(4);
	listaEnteros.insertar(5);
	listaEnteros.insertar(9);
	listaEnteros.insertar(11);
	
	cout << "Lista de enteros: ";
	listaEnteros.mostrar();
	
	contarPrimos(listaEnteros);
	
	// p6 b 
	Lista<char> listaCaracteres;
	listaCaracteres.insertar('H');
	listaCaracteres.insertar('o');
	listaCaracteres.insertar('L');
	listaCaracteres.insertar('a');
	
	cout << "\nLista de caracteres: ";
	listaCaracteres.mostrar();
	
	contarMayusMinus(listaCaracteres);
	
	return 0;
}
