#include "nodo.h"

Nodo::Nodo(struct estudiante nuevo){
  estudiante  = nuevo;
  izq   = NULL;
  der   = NULL;
}

struct estudiante Nodo::getEstudiante(){
  return estudiante;
}