#ifndef NODO_H
#define NODO_H
#include <string>

struct estudiante{
  int carnet;
  std::string dpi;
  std::string nombres;
  std::string apellidos;
  std::string nacimiento;
  std::string direccion;
  int creditos;
  std::string contrasena;
};

class Nodo{
  public:

          //  Atributos del Nodo
          struct estudiante estudiante;
          Nodo *izq;
          Nodo *der;


          //  Metodos del Nodo
          Nodo(struct estudiante nuevo);
          Nodo *getSiguiente();
          struct estudiante getEstudiante();
};

#endif // NODO_H