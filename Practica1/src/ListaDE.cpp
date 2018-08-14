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
void editarLDE();
void recorrerASTLDE(int, struct nodo*&);

int contadorLDE =0;
FILE *agLDE;
char cadenaLDE[1000];
char ubicacionLDE[255] = "C:/Users/pablo/Documents/1er-Sem-2018/Estructura de Datos/Practica1/ListaDoble.dot";

int contarLDE()
{
    nodo *aux = primero;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

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
    else if(primero->siguiente == NULL){
        if(nuevo_nodo->id < primero->id){
            nuevo_nodo->siguiente = primero;
            nuevo_nodo->anterior = NULL;
            primero->anterior = nuevo_nodo;
            primero = nuevo_nodo;
        }
        else if(nuevo_nodo->id >= primero->id){
            ultimo->siguiente = nuevo_nodo;
            nuevo_nodo->siguiente = NULL;
            nuevo_nodo->anterior = ultimo;
            ultimo = nuevo_nodo;
        }
    }
    else{
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        aux = primero;

        while(aux != NULL){
            if(nuevo_nodo->id >= aux->id && aux->siguiente == NULL){
                ultimo->siguiente = nuevo_nodo;
                nuevo_nodo->siguiente = NULL;
                nuevo_nodo->anterior = ultimo;
                ultimo = nuevo_nodo;
                break;
            }
            else if(nuevo_nodo->id >= aux->id && nuevo_nodo->id <= aux->siguiente->id){
                nuevo_nodo->siguiente = aux->siguiente;
                nuevo_nodo->anterior = aux;
                aux->siguiente = nuevo_nodo;
                break;
            }
            else{
                aux = aux->siguiente;
            }
        }
    }
    cout<<"\n   Id: "<<nuevo_nodo->id<<"   Valor: "<<nuevo_nodo->valor<<endl;
}

void verListaDE()
{
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    aux = primero;
    int id_ingresado, ok = 0;

    cout<<"\n   Elementos en la lista: "<<contarLDE()<<endl;
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
                        if(aux->anterior != NULL){
                            cout<<"\n   Anterior *:      "<<aux->anterior<<endl;
                            cout<<"   Anterior id:     "<<aux->anterior->id<<endl;
                        }
                        else{
                            cout<<"\n   Anterior *:       NULL"<<endl;
                            cout<<"   Anterior id:      NULL"<<endl;
                        }
                        cout<<"\n   -------------------------"<<endl;
                    }
                    else{
                        cout<<"\n   Siguiente *:      NULL"<<endl;
                        cout<<"   Siguiente id:     NULL"<<endl;
                        if(aux->anterior != NULL){
                            cout<<"\n   Anterior *:      "<<aux->anterior<<endl;
                            cout<<"   Anterior id:     "<<aux->anterior->id<<endl;
                        }
                        else{
                            cout<<"\n   Anterior *:       NULL"<<endl;
                            cout<<"   Anterior id:      NULL"<<endl;
                        }
                        cout<<"\n   -------------------------"<<endl;
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
        cout<<"\n   La lista esta vacia"<<endl;
    }

}

void editarLDE()
{
    int id_ingresado;
    char valor_ingresado;
    int ok = 0;

    cout<<"\n   Ingrese el Id que desee modificar valor: "<<endl;
    cin>>id_ingresado;

    nodo *aux = primero;
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

void eliminarLDE()
{
    if(primero == NULL){
        cout<<"\n   La lista esta vacia"<<endl;
        return;
    }

    int id_ingresado;

    cout<<"\n   Ingrese el Id que desee eliminar de la lista: "<<endl;
    cin>>id_ingresado;

    if(id_ingresado == primero->id && primero->siguiente == NULL){
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        aux = primero;
        cout<<"\n   Elemento eliminado: "<<aux->id<<","<<aux->valor<<endl;
        primero = NULL;
        ultimo = NULL;
        delete(aux);
    }
    else if(id_ingresado == primero->id){
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        aux = primero;
        cout<<"\n   Elemento eliminado: "<<aux->id<<","<<aux->valor<<endl;
        primero = aux->siguiente;
        primero->anterior = NULL;
        delete(aux);
    }
    else{
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        aux = primero;

        while(aux != NULL){
            if(id_ingresado == aux->id && aux->siguiente == NULL){
                ultimo = aux->anterior;
                ultimo->siguiente = NULL;
                delete(aux);
                break;
            }
            else if(id_ingresado == aux->id){
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;
                delete(aux);
                break;
            }
            aux = aux->siguiente;
        }
    }
}


void generarDotLDE()
{
    struct nodo* aux = primero;
    char buffer[3] = "";
    char buuff[3] = "";
    if(aux){
        strcpy(cadenaLDE,"digraph G {\r\nrankdir=LR;\r\n0[shape=doublecircle,label=");
        sprintf(buffer, "%d", aux->id);
        sprintf(buuff, "%c", aux->valor);
        strcat(cadenaLDE, "\"id: ");
        strcat(cadenaLDE, buffer);
        strcat(cadenaLDE, " Valor: ");
        strcat(cadenaLDE, buuff);
        strcat(cadenaLDE, "\"];\n");
        contadorLDE = 1;
        recorrerASTLDE(0,aux);
        strcat(cadenaLDE,"}");
    }
    else{
        cout<<"\n   La lista esta vacia."<<endl;
    }
}

void recorrerASTLDE(int padre, struct nodo *&aux)
{
    char buffer[1000] = "";
    char buuff[1000] = "";
    char actual[1000] = "";
    char padree[1000] = "";
	while(aux->siguiente){
		if(aux->siguiente && aux->siguiente->siguiente != NULL){
            sprintf(actual, "%d", contadorLDE);
            strcat(cadenaLDE, actual);
            strcat(cadenaLDE,"[shape=circle,label=");
            sprintf(buffer, "%d", aux->siguiente->id);
            sprintf(buuff, "%c", aux->siguiente->valor);
			strcat(cadenaLDE, "\"id: ");
			strcat(cadenaLDE, buffer);
			strcat(cadenaLDE, " Valor: ");
			strcat(cadenaLDE, buuff);
            strcat(cadenaLDE, "\"];\n");
            sprintf(padree, "%d", padre);
            strcat(cadenaLDE, padree);
            strcat(cadenaLDE, "->");
			strcat(cadenaLDE, actual);
            strcat(cadenaLDE, ";\n");
            strcat(cadenaLDE, actual);
            strcat(cadenaLDE, "->");
			strcat(cadenaLDE, padree);
            strcat(cadenaLDE, ";\n");
            padre = contadorLDE;
			contadorLDE++;
		}else{
            sprintf(actual, "%d", contadorLDE);
            strcat(cadenaLDE, actual);
            strcat(cadenaLDE,"[shape=doublecircle,label=");
            sprintf(buffer, "%d", aux->siguiente->id);
            sprintf(buuff, "%c", aux->siguiente->valor);
			strcat(cadenaLDE, "\"id: ");
			strcat(cadenaLDE, buffer);
			strcat(cadenaLDE, " Valor: ");
			strcat(cadenaLDE, buuff);
            strcat(cadenaLDE, "\"];\n");
            sprintf(padree, "%d", padre);
            strcat(cadenaLDE, padree);
            strcat(cadenaLDE, "->");
			strcat(cadenaLDE, actual);
            strcat(cadenaLDE, ";\n");
            strcat(cadenaLDE, actual);
            strcat(cadenaLDE, "->");
			strcat(cadenaLDE, padree);
            strcat(cadenaLDE, ";\n");
            //padre = contadorGrafo;
		}
		aux = aux->siguiente;
	}
}

void graficarListaD()
{
	agLDE = fopen(ubicacionLDE,"w+");
	if(agLDE){
		fprintf(agLDE,"%s",cadenaLDE);
		fclose(agLDE);
		system("dot -Tjpg ListaDoble.dot -o ListaDoble.jpg");
		system("start ListaDoble.jpg");
	}else{
		printf("%s\n","Error abriendo el archivo :(");
	}
}

void graficarLDE()
{
    generarDotLDE();
    puts(cadenaLDE);
    graficarListaD();
}













