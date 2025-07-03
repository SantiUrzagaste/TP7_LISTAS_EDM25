
#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato;
    pnodo sig;
    pnodo ant;
}

typedef struct tlista{
    nodo inicio;
    nodo fin;
}

void IniciarLista(tlista &lista){
    lista.inicio = NULL;
    lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
        nuevo->dato = valor;
        nuevo->sig = NULL;
        nuevo->ant = NULL;
    }
}

void AgregarInicio(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void DecimalABinario(tlista &lista, int numero){
     nuevo;
    while(numero > 0){
        CrearNodo(nuevo, numero % 2);
        AgregarInicio(lista, nuevo);
        numero = numero / 2;
    }
}

void MostrarLista(tlista lista){
    pnodo aux = lista.inicio;
    while(aux != NULL){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

int main(){
    tlista binario;
    int numero;

    IniciarLista(binario);
    cout << "Ingrese un numero: ";
    cin >> numero;

    DecimalABinario(binario, numero);

    cout << "Numero en binario: ";
    MostrarLista(binario);

    return 0;
}
