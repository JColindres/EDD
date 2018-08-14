#include "ListaCSE.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

ListaCSE::ListaCSE()
{
    //ctor
}

ListaCSE::~ListaCSE()
{
    //dtor
}

typedef struct nodo {
   int id;
   char valor;
   struct nodo *siguiente;
} nodo;

nodo *p = NULL;
nodo *u = NULL;

void insertarLCSE();
void verLCSE();
void editarLCSE();
void recorrerASTLCSE(int, struct nodo*&);

int contadorLCSE =0;
FILE *agLCSE;
char cadenaLCSE[1000];
char ubicacionLCSE[255] = "C:/Users/pablo/Documents/1er-Sem-2018/Estructura de Datos/Practica1/ListaCircular.dot";

int contarLCSE()
{
    nodo *aux = p;
    int cont = 0;
    do{
        cont++;
        aux = aux->siguiente;
    }while(aux != p);
    return cont;
}

void insertarLCSE()
{
    nodo *nuevo_nodo = (nodo*)malloc(sizeof(nodo));
    cout<<"\n   Ingrese un id:"<<endl;
    cin>>nuevo_nodo->id;
    cout<<"\n   Ingrese un valor:"<<endl;
    cin>>nuevo_nodo->valor;

    if(p == NULL){
        p = nuevo_nodo;
        p->siguiente = p;
        u = nuevo_nodo;
    }
    else if(p->siguiente == p){
        if(nuevo_nodo->id < p->id){
            nuevo_nodo->siguiente = u;
            p = nuevo_nodo;
        }
        else if(nuevo_nodo->id >= p->id){
            p->siguiente = nuevo_nodo;
            nuevo_nodo->siguiente = p;
            u = nuevo_nodo;
        }
    }
    else{
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        aux = p;

        do{
            if(nuevo_nodo->id >= aux->id && aux->siguiente == p){
                u->siguiente = nuevo_nodo;
                nuevo_nodo->siguiente = p;
                u = nuevo_nodo;
                break;
            }
            else if(nuevo_nodo->id >= aux->id && nuevo_nodo->id <= aux->siguiente->id){
                nuevo_nodo->siguiente = aux->siguiente;
                aux->siguiente = nuevo_nodo;
                break;
            }
            else{
                aux = aux->siguiente;
            }
        }while(aux != p);
    }
    cout<<"\n   Id: "<<nuevo_nodo->id<<"   Valor: "<<nuevo_nodo->valor<<endl;
}

void verLCSE()
{
    nodo *aux = (nodo*)malloc(sizeof(nodo));
    aux = p;
    int id_ingresado, ok = 0;

    cout<<"\n   Elementos en la lista: "<<contarLCSE()<<endl;
    if(aux != NULL){
        cout<<"\n   Ingrese un id: "<<endl;
        cin>>id_ingresado;
        do{
                if(aux->id == id_ingresado){
                    cout<<"\n   Id:               "<<aux->id<<endl;
                    cout<<"   Valor:            "<<aux->valor<<endl;
                    if(aux->siguiente != NULL){
                        cout<<"\n   Siguiente *:      "<<aux->siguiente<<endl;
                        cout<<"   Siguiente id:     "<<aux->siguiente->id<<endl;
                        cout<<"\n   -------------------------"<<endl;
                    }
                    else{
                        cout<<"\n   Siguiente *:      NULL"<<endl;
                        cout<<"   Siguiente id:     NULL"<<endl;
                        cout<<"\n   -------------------------"<<endl;
                    }
                    ok = 1;
                    aux = aux->siguiente;
                }
                else{
                    aux = aux->siguiente;
                }
        }while(aux != p);
        if(!ok){
            cout<<"\n No se encontro"<<endl;
        }

    }
    else{
        cout<<"\n   La lista esta vacia"<<endl;
    }

}

void editarLCSE()
{
    int id_ingresado;
    char valor_ingresado;
    int ok = 0;

    cout<<"\n   Ingrese el Id que desee modificar valor: "<<endl;
    cin>>id_ingresado;

    nodo *aux = p;
    do{
            if(aux->id == id_ingresado){
                ok = 1;
                break;
            }
            else{
                aux = aux->siguiente;
            }
    }while(aux != p && ok != 1);
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

void eliminarLCSE()
{
    if(p == NULL){
        cout<<"\n   La lista esta vacia"<<endl;
        return;
    }

    int id_ingresado;

    cout<<"\n   Ingrese el Id que desee eliminar de la lista: "<<endl;
    cin>>id_ingresado;

    if(id_ingresado == p->id && p->siguiente == p){
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        aux = p;
        cout<<"\n   Elemento eliminado: "<<aux->id<<","<<aux->valor<<endl;
        p = NULL;
        u = NULL;
        delete(aux);
    }
    else if(id_ingresado == p->id && p->siguiente == u){
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        aux = p;
        cout<<"\n   Elemento eliminado: "<<aux->id<<","<<aux->valor<<endl;
        p = u;
        delete(aux);
    }
    else{
        nodo *aux = (nodo*)malloc(sizeof(nodo));
        nodo *anterior = (nodo*)malloc(sizeof(nodo));
        aux = p;
        aux = aux->siguiente;
        while(aux != p){
            if(id_ingresado == aux->id && aux->siguiente == p){
                u = anterior;
                u->siguiente = p;
                delete(aux);
                break;
            }
            else if(id_ingresado == aux->id){
                anterior->siguiente = aux->siguiente;
                delete(aux);
                break;
            }
            anterior = aux;
            aux = aux->siguiente;
        }
    }
}


void generarDotLCSE()
{
    struct nodo* aux = p;
    char buffer[3] = "";
    char buuff[3] = "";
    if(aux){
        strcpy(cadenaLCSE,"digraph G {\r\nrankdir=LR;\r\n0[shape=doublecircle,label=");
        sprintf(buffer, "%d", aux->id);
        sprintf(buuff, "%c", aux->valor);
        strcat(cadenaLCSE, "\"id: ");
        strcat(cadenaLCSE, buffer);
        strcat(cadenaLCSE, " Valor: ");
        strcat(cadenaLCSE, buuff);
        strcat(cadenaLCSE, "\"];\n");
        contadorLCSE = 1;
        recorrerASTLCSE(0,aux);
        strcat(cadenaLCSE,"}");
    }
    else{
        cout<<"\n   La lista esta vacia."<<endl;
    }
}

void recorrerASTLCSE(int padre, struct nodo *&aux)
{
    char buffer[1000] = "";
    char buuff[1000] = "";
    char actual[1000] = "";
    char padree[1000] = "";
    aux = aux->siguiente;
    if(aux != p){
	while(aux != p){
		if(aux != u){
            sprintf(actual, "%d", contadorLCSE);
            strcat(cadenaLCSE, actual);
            strcat(cadenaLCSE,"[shape=circle,label=");
            sprintf(buffer, "%d", aux->id);
            sprintf(buuff, "%c", aux->valor);
			strcat(cadenaLCSE, "\"id: ");
			strcat(cadenaLCSE, buffer);
			strcat(cadenaLCSE, " Valor: ");
			strcat(cadenaLCSE, buuff);
            strcat(cadenaLCSE, "\"];\n");
            sprintf(padree, "%d", padre);
            strcat(cadenaLCSE, padree);
            strcat(cadenaLCSE, "->");
			strcat(cadenaLCSE, actual);
            strcat(cadenaLCSE, ";\n");
            padre = contadorLCSE;
			contadorLCSE++;
		}else{
            sprintf(actual, "%d", contadorLCSE);
            strcat(cadenaLCSE, actual);
            strcat(cadenaLCSE,"[shape=doublecircle,label=");
            sprintf(buffer, "%d", aux->id);
            sprintf(buuff, "%c", aux->valor);
			strcat(cadenaLCSE, "\"id: ");
			strcat(cadenaLCSE, buffer);
			strcat(cadenaLCSE, " Valor: ");
			strcat(cadenaLCSE, buuff);
            strcat(cadenaLCSE, "\"];\n");
            sprintf(padree, "%d", padre);
            strcat(cadenaLCSE, padree);
            strcat(cadenaLCSE, "->");
			strcat(cadenaLCSE, actual);
            strcat(cadenaLCSE, ";\n");
            strcat(cadenaLCSE, actual);
            strcat(cadenaLCSE, "->");
			strcat(cadenaLCSE, "0");
            strcat(cadenaLCSE, ";\n");
            //padre = contadorGrafo;
		}
		aux = aux->siguiente;
	}
    }
}

void graficarListaC()
{
	agLCSE = fopen(ubicacionLCSE,"w+");
	if(agLCSE){
		fprintf(agLCSE,"%s",cadenaLCSE);
		fclose(agLCSE);
		system("dot -Tjpg ListaCircular.dot -o ListaCircular.jpg");
		system("start ListaCircular.jpg");
	}else{
		printf("%s\n","Error abriendo el archivo :(");
	}
}

void graficarLCSE()
{
    generarDotLCSE();
    puts(cadenaLCSE);
    graficarListaC();
}
