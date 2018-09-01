#include "lista.h"

Lista::Lista(){
  raiz = NULL;
  otra = NULL;
}

Nodo *aux = NULL; 

Nodo* Lista::insertar(Nodo *raiz,struct estudiante e){
    if(!raiz){
      Nodo *nuevoNodo;
      nuevoNodo = new Nodo(e);
      raiz = nuevoNodo;
      raiz->izq = NULL;
      raiz->der = NULL;
      aux = raiz;
    }
    else{
        if(!aux){
            Nodo *nuevoNodo;
            nuevoNodo = new Nodo(e);
            aux = nuevoNodo;
        }
        else{
            if(e.carnet < aux->estudiante.carnet){
                aux->izq = insertar(aux->izq,e);
            }
            else if(e.carnet > aux->estudiante.carnet){
                aux->der = insertar(aux->der,e);
            }        
        }
    }
    return aux;
}

//{"carnet":"201602713","dpi":"45654654","nombres":"Soy","apellidos":"yo","nacimiento":"1111","direccion":"adad","creditos":"56","contrasena":"asdads"}