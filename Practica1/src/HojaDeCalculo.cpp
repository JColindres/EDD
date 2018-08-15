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

void insertarCelda()
{
    int columnas;
    int filas;
    int valor_ingresado;

    cout<<"\n   Ingrese el numero de columna donde desee guardar: ";
    cin>>columnas;
    cout<<"\n   Ingrese el numero de filas donde desee guardar: ";
    cin>>filas;
    cout<<"\n   Ingrese el valor: ";
    cin>>valor_ingresado;

    struct x *aux = xinicial;
    int contadorC = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == columnas){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == filas){
                                auy->valor = valor_ingresado;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }
}

void suma()
{
    int columnaD;
    int filaD;
    int valor1 = 0;
    int cv1;
    int fv1;
    int valor2 = 0;
    int cv2;
    int fv2;
    int sumar;

    cout<<"\n   Ingrese el numero de columna donde desee guardar: ";
    cin>>columnaD;
    cout<<"\n   Ingrese el numero de filas donde desee guardar: ";
    cin>>filaD;
    cout<<"\n   Ingrese el columna del primer valor: ";
    cin>>cv1;
    cout<<"\n   Ingrese el fila del primer valor: ";
    cin>>fv1;
    cout<<"\n   Ingrese el columna del segundo valor: ";
    cin>>cv2;
    cout<<"\n   Ingrese el fila del segundo valor: ";
    cin>>fv2;

    struct x *aux = xinicial;
    int contadorC = 0;
    valor1++;
    valor2++;
    valor1 = 0;
    valor2 = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == cv1){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == fv1){
                                valor1 = auy->valor;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }

    aux = xinicial;
    contadorC = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == cv2){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == fv2){
                                valor2 = auy->valor;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }
    sumar = valor1 + valor2;
    cout<<"\n   el valor de la suma es "<<valor1<<"+"<<valor2<<" = "<<sumar<<endl;
    aux = xinicial;
    contadorC = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == columnaD){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == filaD){
                                auy->valor = sumar;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }
}

void resta()
{
    int columnaD;
    int filaD;
    int valor1 = 0;
    int cv1;
    int fv1;
    int valor2 = 0;
    int cv2;
    int fv2;
    int restar;

    cout<<"\n   Ingrese el numero de columna donde desee guardar: ";
    cin>>columnaD;
    cout<<"\n   Ingrese el numero de filas donde desee guardar: ";
    cin>>filaD;
    cout<<"\n   Ingrese el columna del primer valor: ";
    cin>>cv1;
    cout<<"\n   Ingrese el fila del primer valor: ";
    cin>>fv1;
    cout<<"\n   Ingrese el columna del segundo valor: ";
    cin>>cv2;
    cout<<"\n   Ingrese el fila del segundo valor: ";
    cin>>fv2;

    struct x *aux = xinicial;
    int contadorC = 0;
    valor1++;
    valor2++;
    valor1 = 0;
    valor2 = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == cv1){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == fv1){
                                valor1 = auy->valor;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }

    aux = xinicial;
    contadorC = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == cv2){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == fv2){
                                valor2 = auy->valor;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }
    restar = valor1 - valor2;
    cout<<"\n   el valor de la suma es "<<valor1<<"+"<<valor2<<" = "<<restar<<endl;
    aux = xinicial;
    contadorC = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == columnaD){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == filaD){
                                auy->valor = restar;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }
}

void multiplicar()
{
    int columnaD;
    int filaD;
    int valor1 = 0;
    int cv1;
    int fv1;
    int valor2 = 0;
    int cv2;
    int fv2;
    int multi;

    cout<<"\n   Ingrese el numero de columna donde desee guardar: ";
    cin>>columnaD;
    cout<<"\n   Ingrese el numero de filas donde desee guardar: ";
    cin>>filaD;
    cout<<"\n   Ingrese el columna del primer valor: ";
    cin>>cv1;
    cout<<"\n   Ingrese el fila del primer valor: ";
    cin>>fv1;
    cout<<"\n   Ingrese el columna del segundo valor: ";
    cin>>cv2;
    cout<<"\n   Ingrese el fila del segundo valor: ";
    cin>>fv2;

    struct x *aux = xinicial;
    int contadorC = 0;
    valor1++;
    valor2++;
    valor1 = 0;
    valor2 = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == cv1){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == fv1){
                                valor1 = auy->valor;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }

    aux = xinicial;
    contadorC = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == cv2){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == fv2){
                                valor2 = auy->valor;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }
    multi = valor1 * valor2;
    cout<<"\n   el valor de la suma es "<<valor1<<"*"<<valor2<<" = "<<multi<<endl;
    aux = xinicial;
    contadorC = 0;
    if(aux && aux->abajo){
        while(aux){
                if(contadorC == columnaD){
                    struct y *auy = aux->abajo;
                    int contadorF = 0;
                    if(auy){
                        while(auy){
                            if(contadorF == filaD){
                                auy->valor = multi;
                                break;
                            }
                            auy = auy->siguiente;
                            contadorF++;
                        }
                        break;
                    }
                }
                contadorC++;
                aux = aux->siguiente;
        }
    }
    else{
        cout<<"\n   No hay hoja existente."<<endl;
    }
}

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
        strcpy(cadenaHC,"digraph G {0[shape=doublecircle,label=\"Esta vacio\"]}");
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


