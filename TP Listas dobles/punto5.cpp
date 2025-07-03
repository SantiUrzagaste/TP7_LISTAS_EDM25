
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

void EliminarMultiplosDe3(tlista &lista){
    pnodo aux = lista.inicio;
    while(aux != NULL){
        pnodo siguiente = aux->sig;
        if(aux->dato % 3 == 0){
            if(aux == lista.inicio && aux == lista.fin){
                lista.inicio = NULL;
                lista.fin = NULL;
            }
            else if(aux == lista.inicio){
                lista.inicio = aux->sig;
                lista.inicio->ant = NULL;
            }
            else if(aux == lista.fin){
                lista.fin = aux->ant;
                lista.fin->sig = NULL;
            }
            else{
                aux->ant->sig = aux->sig;
                aux->sig->ant = aux->ant;
            }
            delete aux;
        }
        aux = siguiente ;
    }
}

void MostrarLista(tlista lista){
    pnodo aux = lista.inicio;
    while(aux != NULL){
        cout << aux->dato << " ";
        aux = aux->sig;
    }
   cout << endl ; 
}

int main(){
    tlista lista;
    pnodo nuevo;

    IniciarLista(lista);

    int valores[] = {3, 4, 6, 7, 9, 11, 12};
    for(int i = 0; i < 7; i++){
        CrearNodo(nuevo, valores[i]);
        AgregarFinal(lista, nuevo);
    }

    cout << "Lista original: ";
    MostrarLista(lista);

    EliminarMultiplosDe3(lista);

    cout << "Lista sin multiplos de 3: ";
    MostrarLista(lista);

    return 0;
}
