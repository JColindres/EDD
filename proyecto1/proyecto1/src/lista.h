#ifndef LISTA_H
#define LISTA_H

#include <list>
#include <string>
#include "nodo.h"

class Lista{
  public:
          //  Atributos de Lista
          Nodo *raiz;
          Nodo *otra;
          //  Metodos de Lista
          Lista();
          Nodo* insertar(Nodo *raiz, struct estudiante e);
          std::list<struct estudiante> linealizar();
};


#endif // LISTA_H