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
}nodo;

void push(nodo *&,int, char);
void pop(nodo *&);
void recorrerAST(int, nodo *&);
int contar();
int contadorGrafo =0;
nodo *pila = NULL;
nodo *repetidos = NULL;
FILE *archivografico;
char cadena[1000];
char ubicacion[255] = "C:/Users/pablo/Documents/1er-Sem-2018/Estructura de Datos/Practica1/pila.dot";

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
    nodo *nuevo_nodo;
    nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    nuevo_nodo->id = i;
    nuevo_nodo->valor = v;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout<<"\n   Id: "<<i<<"   Valor: "<<v<<endl;
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
    nodo *nuevo_nodo;
    nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    nuevo_nodo->id = i;
    nuevo_nodo->valor = v;
    nuevo_nodo->siguiente = repetidos;
    repetidos = nuevo_nodo;
}

void verPila()
{
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    aux = pila;
    int id_ingresado, ok = 0;

    cout<<"\n   Elementos en la pila: "<<contar()<<endl;
    if(aux != NULL){
        cout<<"\n   Ingrese un id: "<<endl;
        cin>>id_ingresado;
        while(aux != NULL){
                if(aux->id == id_ingresado){
                    cout<<"\n   Id:               "<<aux->id<<endl;
                    cout<<"   Valor:            "<<aux->valor<<endl;
                    if(aux->siguiente != NULL){
                        cout<<"\n   Siguiente *:      "<<aux->siguiente<<endl;
                        cout<<"   Siguiente id:     "<<aux->siguiente->id<<endl;
                    }
                    else{
                        cout<<"\n   Siguiente *:      NULL"<<endl;
                        cout<<"   Siguiente id:     NULL"<<endl;
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

void generarContenidoDot()
{
    struct nodo* aux = pila;
    char buffer[1000] = "";
    char buuff[1000] = "";
    if(aux){
        strcpy(cadena,"digraph G {\r\n0[shape=square,label=");
        sprintf(buffer, "%d", aux->id);
        sprintf(buuff, "%c", aux->valor);
        strcat(cadena, "\"id: ");
        strcat(cadena, buffer);
        strcat(cadena, " Valor: ");
        strcat(cadena, buuff);
        strcat(cadena, "\"];\n");
        contadorGrafo = 1;
        recorrerAST(0,aux);
        strcat(cadena,"}");
    }
    else{
        strcpy(cadena,"digraph G {0[shape=doublecircle,label=\"Esta vacio\"]}");
    }
}

void recorrerAST(int padre, struct nodo *&aux)
{
    char buffer[1000] = "";
    char buuff[1000] = "";
    char actual[1000] = "";
    char padree[1000] = "";
	while(aux){
		if(aux->siguiente){
            sprintf(actual, "%d", contadorGrafo);
            strcat(cadena, actual);
            strcat(cadena,"[shape=circle,label=");
            sprintf(buffer, "%d", aux->siguiente->id);
            sprintf(buuff, "%c", aux->siguiente->valor);
			strcat(cadena, "\"id: ");
			strcat(cadena, buffer);
			strcat(cadena, " Valor: ");
			strcat(cadena, buuff);
            strcat(cadena, "\"];\n");
            sprintf(padree, "%d", padre);
            strcat(cadena, padree);
            strcat(cadena, "->");
			strcat(cadena, actual);
            strcat(cadena, ";\n");
            padre = contadorGrafo;
			contadorGrafo++;
		}else{
            sprintf(actual, "%d", contadorGrafo);
            strcat(cadena, actual);
            strcat(cadena,"[shape=doublecircle,label=\"Fondo\"];\n");
            sprintf(padree, "%d", padre);
            strcat(cadena, padree);
            strcat(cadena, "->");
			strcat(cadena, actual);
            strcat(cadena, ";\n");
            //padre = contadorGrafo;
		}
		aux = aux->siguiente;
	}
}

void graficar()
{
	archivografico = fopen(ubicacion,"w+");
	if(archivografico){
		fprintf(archivografico,"%s",cadena);
		fclose(archivografico);
		system("dot -Tjpg pila.dot -o pila.jpg");
		system("start pila.jpg");
	}else{
		printf("%s\n","Error abriendo el archivo :(");
	}
}

void graficarPILA()
{
    generarContenidoDot();
    puts(cadena);
    graficar();
}
