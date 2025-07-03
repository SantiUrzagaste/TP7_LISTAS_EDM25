
#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
    int dato;
    pnodo sig;
    pnodo ant;
};

typedef struct tlista{
    pnodo inicio;
    pnodo fin;
};

void IniciarLista(tlista &lista){
    lista.inicio 
    lista.fin 
}

void CrearNodo(pnodo &nuevo, int valor){
    nuevo = new tnodo;
    if(nuevo != NULL){
        nuevo->dato = valor;
        nuevo->sig  
        nuevo->ant 
    }
}

void AgregarFinal(tlista &lista, pnodo nuevo){
    if(lista.inicio == NULL){
        lista.inicio = nuevo;
        lista.fin = nuevo;
    }
    else{
        lista.fin->sig = nuevo;
        nuevo->ant = lista.fin;
        lista.fin = nuevo;
    }
}

void MostrarMayorYMenor(tlista lista){
    if(lista.inicio == NULL){
        cout << "La lista esta vacia." << endl;
        
    }

    int mayor = lista.inicio->dato;
    int menor = lista.inicio->dato;
    pnodo aux = lista.inicio->sig;

    while(aux != NULL){
        if(aux->dato > mayor) mayor = aux->dato;
        if(aux->dato < menor) menor = aux->dato;
        aux = aux->sig;
    }

    cout << "Mayor: " << mayor << endl;
    cout << "Menor: " << menor << endl;
}

int main(){
     lista;
    pnodo nuevo;

    IniciarLista(lista);

    int valores[] = {45, 12, 87, 3, 59};
    for(int i = 0; i < 5; i++){
        CrearNodo(nuevo, valores[i]);
        AgregarFinal(lista, nuevo);
    }

    MostrarMayorYMenor(lista);

    return 0;
}
