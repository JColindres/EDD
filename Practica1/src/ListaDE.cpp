#include "ListaDE.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

ListaDE::ListaDE()
{
    //ctor
}

ListaDE::~ListaDE()
{
    //dtor
}

typedef struct nodo {
   int id;
   char valor;
   struct nodo *siguiente;
   struct nodo *anterior;
} nodo;

nodo *primero = NULL;
nodo *ultimo = NULL;

void insertarLDE();
void verListaDE();

void insertarLDE()
{
    nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    cout<<"\n   Ingrese un id:"<<endl;
    cin>>nuevo_nodo->id;
    cout<<"\n   Ingrese un valor:"<<endl;
    cin>>nuevo_nodo->valor;



    if(primero == NULL){
        primero = nuevo_nodo;
        primero->siguiente = NULL;
        primero->anterior = NULL;
        ultimo = primero;
    }
    else{
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        aux = primero;

        while (aux != NULL){
            aux = aux ->siguiente;
        }
        if(aux == NULL || aux->id > nuevo_nodo->id){
            ultimo->siguiente = nuevo_nodo;
            nuevo_nodo->siguiente = NULL;
            nuevo_nodo->anterior = ultimo;
            ultimo = nuevo_nodo;
        }
        else{
            while(aux->siguiente != NULL && aux->siguiente->id <= nuevo_nodo->id){
                aux = aux->siguiente;
            }
            nuevo_nodo->siguiente = aux->siguiente;
            aux->siguiente = nuevo_nodo;
            nuevo_nodo->anterior = aux;
        }

    }
}

void verListaDE()
{
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    aux = primero;
    int id_ingresado, ok = 0;

    //cout<<"\n   Elementos en la lista: "<<contarCola()<<endl;
    if(aux != NULL){
        cout<<"\n   Ingrese un id: "<<endl;
        cin>>id_ingresado;
        while(aux != NULL){
                if(aux->id == id_ingresado){
                    cout<<"\n   Id:               "<<aux->id<<endl;
                    cout<<"   Valor:               "<<aux->valor<<endl;
                    if(aux->siguiente != NULL){
                        cout<<"\n   Siguiente *:      "<<aux->siguiente<<endl;
                        cout<<"   Siguiente id:      "<<aux->siguiente->id<<endl;
                        if(aux->anterior != NULL){
                            cout<<"\n   Anterior *:      "<<aux->anterior<<endl;
                            cout<<"   Anterior id:      "<<aux->anterior->id<<endl;
                        }
                        else{
                            cout<<"\n   Anterior *:      NULL"<<endl;
                            cout<<"   Anterior id:      NULL"<<endl;
                        }
                    }
                    else{
                        cout<<"\n   Siguiente *:      NULL"<<endl;
                        cout<<"   Siguiente id:      NULL"<<endl;
                        if(aux->anterior != NULL){
                            cout<<"\n   Anterior *:      "<<aux->anterior<<endl;
                            cout<<"   Anterior id:      "<<aux->anterior->id<<endl;
                        }
                        else{
                            cout<<"\n   Anterior *:      NULL"<<endl;
                            cout<<"   Anterior id:      NULL"<<endl;
                        }
                    }
                    ok = 1;
                    aux = aux->siguiente;
                }
                else{
                    aux = aux->siguiente;
                }
        }
        if(!ok){
            cout<<"\n No se encontro"<<endl;
        }

    }
    else{
        cout<<"\n   La cola esta vacia"<<endl;
    }

}
















