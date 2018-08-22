/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tarea2;

import java.util.ArrayList;

/**
 *
 * @author pablo
 */
public class Cola implements Queue {

    public static ArrayList numeros = new ArrayList();

    public static class nodo {

        public static int id;
        public static nodo siguiente;

    }

    public static nodo cabeza, ultimo;

    @Override
    public void insertar(int i) {
        nodo nuevo = new nodo();
        nuevo.id = i;
        if (cabeza == null) {
            cabeza = nuevo;
            cabeza.siguiente = null;
            ultimo = cabeza;
            numeros.add(cabeza.id);
        } else {
            ultimo.siguiente = nuevo;
            ultimo = nuevo;
            ultimo.siguiente = null;
            numeros.add(ultimo.id);
        }
    }

    @Override
    public void eliminar() {
        if (cabeza != null) {
            nodo eliminar = cabeza;
            cabeza = cabeza.siguiente;
            eliminar.siguiente = null;
            eliminar = null;
            if (cabeza == null) {
                ultimo = null;
            }
        }
    }

    @Override
    public Iterator getIterator() {
        return new ColaIterator();
    }

    public static void contador() {
        nodo aux = cabeza;
        numeros = new ArrayList();
        while (aux != null) {
            numeros.add(aux.id);
            aux = aux.siguiente;
        }
    }

    private class ColaIterator implements Iterator {

        int index;

        @Override
        public boolean hasNext() {

            if (index < numeros.size()) {
                return true;
            }
            return false;
        }

        @Override
        public Object next() {
            if (this.hasNext()) {
                return numeros.get(index++);
            }
            return null;
        }
    }
}
