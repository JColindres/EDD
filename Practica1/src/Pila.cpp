#include "Pila.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

Pila::Pila()
{
    //ctor
}

Pila::~Pila()
{
    //dtor
}

typedef struct nodo
{
    int id;
    char valor;
    struct nodo *siguiente;
}tipoNodo,nodo;

typedef tipoNodo *pNodo;

void push(nodo *&,int, char);
void pop(nodo *&);
int contar();
nodo *pila = NULL;
nodo *repetidos = NULL;

void insertarPila()
{
    int id_ingresado;
    char valor_ingresado;

    cout<<"\n   Ingrese un id: "<<endl;
    cin>>id_ingresado;
    cout<<"\n   Ingrese un valor: "<<endl;
    cin>>valor_ingresado;

    push(pila, id_ingresado, valor_ingresado);
}

void push(nodo *&pila, int i, char v)
{
    pNodo nuevo_nodo;
    nuevo_nodo = (pNodo)malloc(sizeof(tipoNodo));
    nuevo_nodo->id = i;
    nuevo_nodo->valor = v;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout<<"\n   Id: "<<i<<"\n   Valor: "<<v<<endl;
}

void sacarPila()
{
    pop(pila);
}

void pop(nodo *&pila)
{
    if(pila == NULL){
        cout<<"\n   La pila esta vacia"<<endl;
        return;
    }
    nodo *aux = pila;
    cout<<"\n   Elemento eliminado: "<<aux->id<<","<<aux->valor<<endl;
    pila = aux->siguiente;
    delete(aux);
}

void agregarRepetidos(nodo *&repetidos, int i, char v)
{
    pNodo nuevo_nodo;
    nuevo_nodo = (pNodo)malloc(sizeof(tipoNodo));
    nuevo_nodo->id = i;
    nuevo_nodo->valor = v;
    nuevo_nodo->siguiente = repetidos;
    repetidos = nuevo_nodo;
}

void ver()
{
    nodo *aux = pila;
    int id_ingresado, encontrado = 0, contador = 0;
    repetidos = NULL;

    cout<<"\n   Elementos en la pila: "<<contar()<<endl;
    if(aux != NULL){
        cout<<"\n   Ingrese un id: "<<endl;
        cin>>id_ingresado;
        while(aux != NULL){
            if(aux->id == id_ingresado){
                agregarRepetidos(repetidos,aux->id,aux->valor);
                encontrado = 1;
                contador++;
                aux = aux->siguiente;
            }
            else{
                aux = aux->siguiente;
            }
        }
        if(encontrado == 1 && contador > 1){
            while(repetidos != NULL){
                if(repetidos->id == id_ingresado){
                    nodo* puntero = new nodo();
                    puntero = *&repetidos;
                    nodo* sig = &(*puntero);

                    cout<<"\n   Id:               "<<repetidos->id<<endl;
                    cout<<"\n   Valor:            "<<repetidos->valor<<endl;
                    cout<<"\n\n   Siguiente *:      "<<&(*sig)<<endl;
                    cout<<"\n   Siguiente id:     "<<(*sig).id<<endl;
                    cout<<"\n   ---------------------"<<endl;
                    repetidos = repetidos->siguiente;
                }
            }
        }
        else if(encontrado == 1){
            nodo* puntero = new nodo();
            puntero = *&repetidos;
            nodo* sig = &(*puntero);

            cout<<"\n   Id:               "<<repetidos->id<<endl;
            cout<<"\n   Valor:            "<<repetidos->valor<<endl;
            cout<<"\n\n   Siguiente *:      "<<&(*sig)<<endl;
            cout<<"\n   Siguiente id:     "<<(*sig).id<<endl;
        }

        else{
            cout<<"\n   No se encontro"<<endl;
        }

    }
    else{
        cout<<"\n   La pila esta vacia"<<endl;
    }

}

int contar()
{
    nodo *aux = pila;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}
