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

void verPila()
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
        aux = pila;
        if(encontrado == 1 && contador > 1){
            while(repetidos != NULL){
                if(repetidos->id == id_ingresado){
                    cout<<"\n   Id:               "<<repetidos->id<<endl;
                    cout<<"   Valor:            "<<repetidos->valor<<endl;
                    while(aux != NULL){
                        if(aux->id == repetidos->id && aux->valor == repetidos->valor){
                            cout<<"\n   Siguiente *:      "<<aux->siguiente<<endl;
                            cout<<"   Siguiente id:     "<<aux->siguiente->id<<endl;
                        }
                        else{
                            aux = aux->siguiente;
                        }
                    }
                    cout<<"   ---------------------"<<endl;
                    repetidos = repetidos->siguiente;
                }
            }
        }
        else if(encontrado == 1){
            int ok = 0;
            cout<<"\n   Id:               "<<repetidos->id<<endl;
            cout<<"   Valor:            "<<repetidos->valor<<endl;
            while(aux != NULL){
                if(aux->id == repetidos->id && aux->valor == repetidos->valor){
                    //nodo* puntero = new nodo();
                    //puntero = *&aux;
                    cout<<"\n   Siguiente *:      "<<aux->siguiente<<endl;
                    cout<<"   Siguiente id:     "<<aux->siguiente->id<<endl;
                    ok = 1;
                }
                else{
                    aux = aux->siguiente;
                }
            }
            if(aux == NULL && ok == 0){
                cout<<"\n   Siguiente *:      "<<"NULL"<<endl;
                cout<<"   Siguiente id:     "<<"NULL"<<endl;
            }
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

void editarPila()
{
    int id_ingresado;
    char valor_ingresado;
    int ok = 0;

    cout<<"\n   Ingrese el Id que desee modificar valor: "<<endl;
    cin>>id_ingresado;

    nodo *aux = pila;
    while(aux != NULL && ok != 1){
            if(aux->id == id_ingresado){
                ok = 1;
            }
            else{
                aux = aux->siguiente;
            }
    }
    if(ok == 1){
        cout<<"\n   Se encontro el Id."<<endl;
        cout<<"\n   Ingrese el nuevo valor del Id:"<<endl;
        cin>>valor_ingresado;

        aux->valor = valor_ingresado;
        cout<<"\n   Se encontro actualizo el id."<<endl;
        cout<<"\n   Id: "<<aux->id<<" Valor: "<<aux->valor<<endl;
    }
    else{
        cout<<"\n   No se encontro el Id."<<endl;
    }
}
