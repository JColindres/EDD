#include <iostream>
#include <stdio.h>
#include "Pila.h"
#include "Cola.h"
#include "ListaDE.h"
#include "ListaCSE.h"
#include "HojaDeCalculo.h"

using namespace std;

int main()
{
    int opcion;

    do
    {
        FirstMenu:
        system("cls");
        printf( "\n   ------------------------------------------");
        printf( "\n          [EDD-B] Practica 1 - 201602713");
        printf( "\n\n   Introduzca opcion (1-3): ");
        printf( "\n\n   1. Estructuras de Datos");
        printf( "\n   2. Hoja de Calculo");
        printf( "\n   3. Salir.\n\n" );
        printf( "\n\n   Su eleccion: ");

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
                SecondMenu:
                system("cls");
                printf( "\n   ------------------------------------------");
                printf( "\n          1. Estructuras de Datos");
                printf( "\n\n   Introduzca opcion (1-5): ");
                printf( "\n\n   1.1. Pila.");
                printf( "\n   1.2. Cola.");
                printf( "\n   1.3. Lista Doblemente Enlazada.");
                printf( "\n   1.4. Lista Circular Simplemente Enlazada.");
                printf( "\n   1.5. Regresar.\n\n" );
                printf( "\n\n   Su eleccion: ");

                scanf( "%d", &opcion );

                /* Inicio del anidamiento */

                switch ( opcion )
                {
                    case 1:
                        ThirdMenu:
                        system("cls");
                        printf( "\n   ------------------------------------------");
                        printf( "\n          1.1. Pila");
                        printf( "\n\n   Introduzca opcion (1-6): ");
                        printf( "\n\n   1.1. Insertar.");
                        printf( "\n   1.2. Ver.");
                        printf( "\n   1.3. Editar");
                        printf( "\n   1.4. Eliminar");
                        printf( "\n   1.5. Graficar");
                        printf( "\n   1.6. Regresar.\n\n" );
                        printf( "\n\n   Su eleccion: ");

                        scanf( "%d", &opcion );

                        /* Inicio del anidamiento */

                        switch ( opcion )
                        {
                            case 1:
                                insertarPila();
                                system("pause");
                                goto ThirdMenu;
                                break;

                            case 2:
                                verPila();
                                system("pause");
                                goto ThirdMenu;
                                break;

                            case 3:
                                editarPila();
                                system("pause");
                                goto ThirdMenu;
                                break;

                            case 4:
                                sacarPila();
                                system("pause");
                                goto ThirdMenu;
                                break;

                            case 5:
                                graficarPILA();
                                system("pause");
                                goto ThirdMenu;
                                break;

                            case 6:
                                goto SecondMenu;
                                break;

                            default:
                                printf("\n   Seleccione un valor valido!");
                                goto ThirdMenu;
                                break;
                        }
                        break;

                    case 2:
                        FourthMenu:
                        system("cls");
                        printf( "\n   ------------------------------------------");
                        printf( "\n          1.2. Cola");
                        printf( "\n\n   Introduzca opcion (1-6): ");
                        printf( "\n\n   1.1. Insertar.");
                        printf( "\n   1.2. Ver.");
                        printf( "\n   1.3. Editar");
                        printf( "\n   1.4. Eliminar");
                        printf( "\n   1.5. Graficar");
                        printf( "\n   1.6. Regresar.\n\n" );
                        printf( "\n\n   Su eleccion: ");

                        scanf( "%d", &opcion );

                        /* Inicio del anidamiento */

                        switch ( opcion )
                        {
                            case 1:
                                insertarCola();
                                system("pause");
                                goto FourthMenu;
                                break;

                            case 2:
                                verCola();
                                system("pause");
                                goto FourthMenu;
                                break;

                            case 3:
                                editarCola();
                                system("pause");
                                goto FourthMenu;
                                break;

                            case 4:
                                eliminarCola();
                                system("pause");
                                goto FourthMenu;
                                break;

                            case 5:
                                graficarCOLA();
                                system("pause");
                                goto FourthMenu;
                                break;

                            case 6:
                                goto SecondMenu;
                                break;

                            default:
                                printf("\n   Seleccione un valor valido!");
                                goto FourthMenu;
                                break;
                        }
                        break;

                    case 3:
                        FifthMenu:
                        system("cls");
                        printf( "\n   ------------------------------------------");
                        printf( "\n          1.3. Lista Doblemente Enlazada");
                        printf( "\n\n   Introduzca opcion (1-6): ");
                        printf( "\n\n   1.1. Insertar.");
                        printf( "\n   1.2. Ver.");
                        printf( "\n   1.3. Editar");
                        printf( "\n   1.4. Eliminar");
                        printf( "\n   1.5. Graficar");
                        printf( "\n   1.6. Regresar.\n\n" );
                        printf( "\n\n   Su eleccion: ");

                        scanf( "%d", &opcion );

                        /* Inicio del anidamiento */

                        switch ( opcion )
                        {
                            case 1:
                                insertarLDE();
                                system("pause");
                                goto FifthMenu;
                                break;

                            case 2:
                                verListaDE();
                                system("pause");
                                goto FifthMenu;
                                break;

                            case 3:
                                editarLDE();
                                system("pause");
                                goto FifthMenu;
                                break;

                            case 4:
                                eliminarLDE();
                                system("pause");
                                goto FifthMenu;
                                break;

                            case 5:
                                graficarLDE();
                                system("pause");
                                goto FifthMenu;
                                break;

                            case 6:
                                goto SecondMenu;
                                break;

                            default:
                                printf("\n   Seleccione un valor valido!");
                                break;
                        }
                        break;

                    case 4:
                        SixthMenu:
                        system("cls");
                        printf( "\n   ------------------------------------------");
                        printf( "\n          1.4. Lista Circula Simplemente Enlazada");
                        printf( "\n\n   Introduzca opcion (1-6): ");
                        printf( "\n\n   1.1. Insertar.");
                        printf( "\n   1.2. Ver.");
                        printf( "\n   1.3. Editar");
                        printf( "\n   1.4. Eliminar");
                        printf( "\n   1.5. Graficar");
                        printf( "\n   1.6. Regresar.\n\n" );
                        printf( "\n\n   Su eleccion: ");

                        scanf( "%d", &opcion );

                        /* Inicio del anidamiento */

                        switch ( opcion )
                        {
                            case 1:
                                insertarLCSE();
                                system("pause");
                                goto SixthMenu;
                                break;

                            case 2:
                                verLCSE();
                                system("pause");
                                goto SixthMenu;
                                break;

                            case 3:
                                editarLCSE();
                                system("pause");
                                goto SixthMenu;
                                break;

                            case 4:
                                eliminarLCSE();
                                system("pause");
                                goto SixthMenu;
                                break;

                            case 5:
                                graficarLCSE();
                                system("pause");
                                goto SixthMenu;
                                break;

                            case 6:
                                goto SecondMenu;
                                break;

                            default:
                                printf("\n   Seleccione un valor valido!");
                                break;
                        }
                        break;

                    case 5:
                        goto FirstMenu;
                        break;

                    default:
                        printf("\n   Seleccione un valor valido!");
                        break;
                }
                break;

            case 2:
                HojaMenu:
                system("cls");
                printf( "\n   ------------------------------------------");
                printf( "\n          2. Hoja de Calculo");
                printf( "\n\n   Introduzca opcion (1-7): ");
                printf( "\n\n   2.1. Crear Hoja.");
                printf( "\n   2.2. Insertar.");
                printf( "\n   2.3. Sumar.");
                printf( "\n   2.4. Restar.");
                printf( "\n   2.5. Multiplicar.");
                printf( "\n   2.6. Graficar.");
                printf( "\n   2.7. Regresar.\n\n" );
                printf( "\n\n   Su eleccion: ");

                scanf( "%d", &opcion );

                /* Inicio del anidamiento */

                switch ( opcion )
                {
                    case 1:
                        crearhoja();
                        system("pause");
                        goto HojaMenu;
                        break;

                    case 2:
                        insertarCelda();
                        system("pause");
                        goto HojaMenu;
                        break;

                    case 3:
                        suma();
                        system("pause");
                        goto HojaMenu;
                        break;

                    case 4:
                        resta();
                        system("pause");
                        goto HojaMenu;
                        break;

                    case 5:
                        multiplicar();
                        system("pause");
                        goto HojaMenu;
                        break;

                    case 6:
                        graficarHC();
                        system("pause");
                        goto HojaMenu;
                        break;

                    case 7:
                        goto FirstMenu;
                        break;

                    default:
                        printf("\n   Seleccione un valor valido!");
                        break;
                }
                break;

            case 3:
                printf("\n   Adios");
                break;

            default:
                printf("\n   Seleccione un valor valido!");
                break;
         }

         /* Fin del anidamiento */

    } while ( opcion != 3 );

    return 0;
}
