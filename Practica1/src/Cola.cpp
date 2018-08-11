#include "Cola.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

Cola::Cola()
{
    //ctor
}

Cola::~Cola()
{
    //dtor
}

typedef struct nodo
{
    int id;
    char valor;
    struct nodo *siguiente;
}nodo;

void insertarCola();
bool colaVacia(nodo *);
void eliminarCola();
int contarCola();
nodo *frente = NULL;
nodo *fin = NULL;

void insertarCola()
{
    int id_ingresado;
    char valor_ingresado;

    cout<<"\n   Ingrese un Id:"<<endl;
    cin>>id_ingresado;
    cout<<"\n   Ingrese un Valor:"<<endl;
    cin>>valor_ingresado;

    nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    nuevo_nodo->id = id_ingresado;
    nuevo_nodo->valor = valor_ingresado;
    nuevo_nodo->siguiente = NULL;

    if(colaVacia(frente)){
        frente = nuevo_nodo;
    }
    else{
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout<<"\n   Id: "<<nuevo_nodo->id<<"   Valor: "<<nuevo_nodo->valor<<endl;
}

bool colaVacia(nodo *frente)
{
    return (frente == NULL)? true : false;
}

void eliminarCola()
{
    nodo *aux = frente;
    if(aux == NULL){
        cout<<"\n   La cola esta vacia"<<endl;
        return;
    }
    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }
    else{
        frente = frente->siguiente;
    }
    cout<<"\n   Elemento eliminado: "<<aux->id<<","<<aux->valor<<endl;
    delete(aux);
}

void verCola()
{
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    aux = frente;
    int id_ingresado, ok = 0;

    cout<<"\n   Elementos en la cola: "<<contarCola()<<endl;
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
                    }
                    else{
                        cout<<"\n   Siguiente *:      NULL"<<endl;
                        cout<<"   Siguiente id:      NULL"<<endl;
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

int contarCola()
{
    nodo *aux = frente;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

void editarCola()
{
    int id_ingresado;
    char valor_ingresado;
    int ok = 0;

    cout<<"\n   Ingrese el Id que desee modificar valor: "<<endl;
    cin>>id_ingresado;

    nodo *aux = frente;
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


