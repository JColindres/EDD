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
void recorrerASTCola(int,struct nodo *&);
nodo *inicio = NULL;
nodo *fin= NULL;
int contadorGC =0;
FILE *agC;
char cadenaC[1000];
char ubicacionC[255] = "C:/Users/pablo/Documents/1er-Sem-2018/Estructura de Datos/Practica1/cola.dot";

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

    if(colaVacia(inicio)){
        inicio = nuevo_nodo;
    }
    else{
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout<<"\n   Id: "<<nuevo_nodo->id<<"   Valor: "<<nuevo_nodo->valor<<endl;
}

bool colaVacia(nodo *inicio)
{
    return (inicio == NULL)? true : false;
}

void eliminarCola()
{
    nodo *aux = inicio;
    if(aux == NULL){
        cout<<"\n   La cola esta vacia"<<endl;
        return;
    }
    if(inicio == fin){
        inicio = NULL;
        fin = NULL;
    }
    else{
        inicio = inicio->siguiente;
    }
    cout<<"\n   Elemento eliminado: "<<aux->id<<","<<aux->valor<<endl;
    delete(aux);
}

void verCola()
{
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    aux = inicio;
    int id_ingresado, ok = 0;

    cout<<"\n   Elementos en la cola: "<<contarCola()<<endl;
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
        cout<<"\n   La cola esta vacia"<<endl;
    }

}

int contarCola()
{
    nodo *aux = inicio;
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

    nodo *aux = inicio;
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

void generarDotCola()
{
    struct nodo* aux = inicio;
    char buffer[1000] = "";
    char buuff[1000] = "";
    if(aux){
        strcpy(cadenaC,"digraph G {\r\nrankdir=LR;\r\n0[shape=square,label=");
        sprintf(buffer, "%d", aux->id);
        sprintf(buuff, "%c", aux->valor);
        strcat(cadenaC, "\"id: ");
        strcat(cadenaC, buffer);
        strcat(cadenaC, " Valor: ");
        strcat(cadenaC, buuff);
        strcat(cadenaC, "\"];\n");
        contadorGC = 1;
        recorrerASTCola(0,aux);
        strcat(cadenaC,"}");
    }
    else{
        cout<<"\n   La cola esta vacia."<<endl;
    }
}

void recorrerASTCola(int padre, struct nodo *&aux)
{
    char buffer[1000] = "";
    char buuff[1000] = "";
    char actual[1000] = "";
    char padree[1000] = "";
	while(aux){
		if(aux->siguiente){
            sprintf(actual, "%d", contadorGC);
            strcat(cadenaC, actual);
            strcat(cadenaC,"[shape=circle,label=");
            sprintf(buffer, "%d", aux->siguiente->id);
            sprintf(buuff, "%c", aux->siguiente->valor);
			strcat(cadenaC, "\"id: ");
			strcat(cadenaC, buffer);
			strcat(cadenaC, " Valor: ");
			strcat(cadenaC, buuff);
            strcat(cadenaC, "\"];\n");
            sprintf(padree, "%d", padre);
            strcat(cadenaC, padree);
            strcat(cadenaC, "->");
			strcat(cadenaC, actual);
            strcat(cadenaC, ";\n");
            padre = contadorGC;
			contadorGC++;
		}else{
            sprintf(actual, "%d", contadorGC);
            strcat(cadenaC, actual);
            strcat(cadenaC,"[shape=doublecircle,label=\"Fin de la Cola\"];\n");
            sprintf(padree, "%d", padre);
            strcat(cadenaC, padree);
            strcat(cadenaC, "->");
			strcat(cadenaC, actual);
            strcat(cadenaC, ";\n");
            //padre = contadorGrafo;
		}
		aux = aux->siguiente;
	}
}

void graficarC()
{
	agC = fopen(ubicacionC,"w+");
	if(agC){
		fprintf(agC,"%s",cadenaC);
		fclose(agC);
		system("dot -Tjpg cola.dot -o cola.jpg");
		system("start cola.jpg");
	}else{
		printf("%s\n","Error abriendo el archivo :(");
	}
}

void graficarCOLA()
{
    generarDotCola();
    puts(cadenaC);
    graficarC();
}


