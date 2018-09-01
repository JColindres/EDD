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

    public static nodo re;

    public static class nodo {

        public static int id;
        public static nodo siguiente;

        private nodo(int i) {
            this.id = i;
        }

    }

    public static nodo cabeza, ultimo;

    @Override
    public void insertar(int i) {
        nodo nuevo;
        nuevo = new nodo(i);
        if (cabeza == null) {
            cabeza = nuevo;
            ultimo = nuevo;
        } else {
            ultimo.siguiente = nuevo;
            ultimo = nuevo;
        }
        ultimo.siguiente = null;
    }

    @Override
    public void eliminar() {
        if (cabeza != null) {
            cabeza = cabeza.siguiente;
            if (cabeza == null) {
                ultimo = null;
            }
        }
    }

    @Override
    public void recorrer() {
        nodo aaa = cabeza;
        while(aaa != null){
            System.out.println("Numero: "+aaa.id);
            aaa = aaa.siguiente;
        }
    }

    @Override
    public Iterator getIterator() {
        return new ColaIterator();
    }

    private class ColaIterator implements Iterator {

        @Override
        public boolean hasNext() {

            if (re != null) {
                return true;
            }
            return false;
        }

        @Override
        public Object next() {
            if (this.hasNext()) {
                nodo a = re;
                re = re.siguiente;
                return a.id;
            }
            return null;
        }
    }
}
