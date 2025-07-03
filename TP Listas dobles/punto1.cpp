
#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato ;
    pnodo sig;
    pnodo ant;
};

typedef struct tlista{
    pnodo inicio;
    pnodo fin;
};

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
    } else {
        nuevo->sig = lista.inicio;
        lista.inicio->ant = nuevo;
        lista.inicio = nuevo;
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    } else {
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

void QuitarInicio(tlista &lista){
    pnodo aux;
    if(lista.inicio != NULL){
        aux = lista.inicio;
        if(lista.inicio == lista.fin){
            lista.inicio = NULL;
            lista.fin = NULL;
        } else {
            lista.inicio = lista.inicio->sig;
            lista.inicio->ant = NULL;
        }
        delete aux;
    }
}

void QuitarFinal(tlista &lista){
    pnodo aux;
    if(lista.fin != NULL){
        aux = lista.fin;
        if(lista.inicio == lista.fin){
            lista.inicio = NULL;
            lista.fin = NULL;
        } else {
            lista.fin = lista.fin->ant;
            lista.fin->sig = NULL;
        }
     delete aux ; 
    }
}

bool BuscarValor(tlista lista, int valor){
    pnodo aux = lista.inicio;
    while(aux != NULL){
        if(aux->dato == valor) return true;
        aux = aux->sig;
    }
    return false;
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
    tlista lista;
    pnodo nuevo;

    IniciarLista(lista);

    CrearNodo(nuevo, 10);
    AgregarInicio(lista, nuevo);
    CrearNodo(nuevo, 20);
    AgregarFinal(lista, nuevo);
    CrearNodo(nuevo, 5);
    AgregarInicio(lista, nuevo);
    CrearNodo(nuevo, 30);
    AgregarFinal(lista, nuevo);

    cout << "Lista actual: ";
    MostrarLista(lista);

    QuitarInicio(lista);
    cout << "Luego de quitar inicio: ";
    MostrarLista(lista);

    QuitarFinal(lista);
    cout << "Luego de quitar final: ";
    MostrarLista(lista);

    int valorBuscado = 20 ; 
    if(BuscarValor(lista, valorBuscado))
        cout << "El valor " << valorBuscado << " se encuentra en la lista." << endl;
    else
        cout << "El valor " << valorBuscado << " no se encuentra en la lista." << endl;

    return 0;
}
