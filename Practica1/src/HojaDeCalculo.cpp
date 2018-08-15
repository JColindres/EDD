#include "HojaDeCalculo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

using namespace std;

HojaDeCalculo::HojaDeCalculo()
{
    //ctor
}

HojaDeCalculo::~HojaDeCalculo()
{
    //dtor
}

typedef struct x {
    int indicex;
    struct x *siguiente;
    struct y *abajo;
} x;

typedef struct y {
    int indicey;
    int valor;
    struct y *siguiente;
} y;

x *xinicial = NULL;
x *xfinal = NULL;
y *yinicial = NULL;
y *yfinal = NULL;
FILE *agHC;
char cadenaHC[1000];
char ubicacionHC[255] = "C:/Users/pablo/Documents/1er-Sem-2018/Estructura de Datos/Practica1/HojaCalculo.dot";


void crearhoja()
{
    xinicial = NULL;
    xfinal = NULL;
    yinicial = NULL;
    yfinal = NULL;

    int filas;
    int columnas;
    int contadorcolumnas = 0;

    cout<<"\n   Ingrese el numero de columnas: ";
    cin>>columnas;
    cout<<"\n   Ingrese el numero de filas: ";
    cin>>filas;

    while(contadorcolumnas < columnas){
        x *nuevo_nodo = (x*)malloc(sizeof(x));
        if(xinicial == NULL){
            nuevo_nodo->abajo = NULL;
            nuevo_nodo->indicex = contadorcolumnas;
            xinicial = nuevo_nodo;
            xfinal = nuevo_nodo;
            xinicial->siguiente = xfinal;
            xfinal->siguiente = NULL;
            contadorcolumnas++;
        }
        else{
            nuevo_nodo->abajo = NULL;
            nuevo_nodo->indicex = contadorcolumnas;
            nuevo_nodo->siguiente = NULL;
            xfinal->siguiente = nuevo_nodo;
            xfinal = nuevo_nodo;
            contadorcolumnas++;
        }
    }
    cout<<"\n   Se crearon las columnas: "<<contadorcolumnas;
    x *aux = (x*)malloc(sizeof(x));
    aux = xinicial;
    while(aux){
        int contadorfilas = 0;
        while(contadorfilas < filas){
            y *nuevo_nodo = (y*)malloc(sizeof(y));
            if(yinicial == NULL){
                nuevo_nodo->indicey = contadorfilas;
                nuevo_nodo->valor = 0;
                yinicial = nuevo_nodo;
                yfinal = nuevo_nodo;
                yinicial->siguiente = yfinal;
                yfinal->siguiente = NULL;
                contadorfilas++;
            }
            else{
                nuevo_nodo->indicey = contadorfilas;
                nuevo_nodo->valor = 0;
                nuevo_nodo->siguiente = NULL;
                yfinal->siguiente = nuevo_nodo;
                yfinal = nuevo_nodo;
                contadorfilas++;
            }
        }
        aux->abajo = yinicial;
        yinicial=NULL;
        aux = aux->siguiente;
    }
}

void generarDotHC()
{
    struct x *aux = xinicial;
    int contadorC = 0;
    int contadorF = 0;
    char contC[1000] = "";
    if(aux && aux->abajo){
        strcpy(cadenaHC,"digraph G {\r\n");
        while(aux){
                if(aux->siguiente){
                    strcat(cadenaHC,"subgraph ");
                    sprintf(contC, "%d", contadorC);
                    strcat(cadenaHC,contC);
                    strcat(cadenaHC,"{\n");
                    struct y *auy = aux->abajo;
                    char contF[1000] = "";
                    char val[1000] = "";
                    char auxval[1000] = "";
                    if(auy){
                        while(auy){
                            sprintf(contF, "%d", contadorF);
                            strcat(cadenaHC,contF);
                            strcat(cadenaHC,"[shape=square;label=\"");
                            if(auy->valor != 0){
                                sprintf(val, "%d", auy->valor);
                                strcat(cadenaHC,val);
                                strcat(cadenaHC,"\"];\n");
                                if(auy != aux->abajo){
                                    strcat(cadenaHC, auxval);
                                    strcat(cadenaHC, "->");
                                    strcat(cadenaHC, contF);
                                    strcat(cadenaHC, ";\n");
                                }
                            }
                            else{
                                strcat(cadenaHC,"-");
                                strcat(cadenaHC,"\"];\n");
                                if(auy != aux->abajo){
                                    strcat(cadenaHC, auxval);
                                    strcat(cadenaHC, "->");
                                    strcat(cadenaHC, contF);
                                    strcat(cadenaHC, ";\n");
                                }
                            }
                            sprintf(auxval, "%d", contadorF);
                            auy = auy->siguiente;
                            contadorF++;
                        }
                    }
                    strcat(cadenaHC,"}");
                }
                else{
                    strcat(cadenaHC,"subgraph ");
                    sprintf(contC, "%d", contadorC);
                    strcat(cadenaHC,contC);
                    strcat(cadenaHC,"{\n");
                    struct y *auy = aux->abajo;
                    char contF[1000] = "";
                    char val[1000] = "";
                    char auxval[1000] = "";
                    if(auy){
                        while(auy){
                            sprintf(contF, "%d", contadorF);
                            strcat(cadenaHC,contF);
                            strcat(cadenaHC,"[shape=square;label=\"");
                            if(auy->valor != 0){
                                sprintf(val, "%d", auy->valor);
                                strcat(cadenaHC,val);
                                strcat(cadenaHC,"\"];\n");
                                if(auy != aux->abajo){
                                    strcat(cadenaHC, auxval);
                                    strcat(cadenaHC, "->");
                                    strcat(cadenaHC, contF);
                                    strcat(cadenaHC, ";\n");
                                }
                            }
                            else{
                                strcat(cadenaHC,"-");
                                strcat(cadenaHC,"\"];\n");
                                if(auy != aux->abajo){
                                    strcat(cadenaHC, auxval);
                                    strcat(cadenaHC, "->");
                                    strcat(cadenaHC, contF);
                                    strcat(cadenaHC, ";\n");
                                }
                            }
                            sprintf(auxval, "%d", contadorF);
                            auy = auy->siguiente;
                            contadorF++;
                        }
                    }
                    strcat(cadenaHC,"}");
                }
                contadorC++;
                aux = aux->siguiente;
        }
        strcat(cadenaHC,"}");
    }
    else{
        cout<<"\n   La hoja no se creo."<<endl;
    }
}

void graficarh()
{
	agHC = fopen(ubicacionHC,"w+");
	if(agHC){
		fprintf(agHC,"%s",cadenaHC);
		fclose(agHC);
		system("dot -Tjpg HojaCalculo.dot -o HojaCalculo.jpg");
		system("start HojaCalculo.jpg");
	}else{
		printf("%s\n","Error abriendo el archivo :(");
	}
}

void graficarHC()
{
    generarDotHC();
    puts(cadenaHC);
    graficarh();
}


