/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tarea2;

/**
 *
 * @author pablo
 */
public interface Queue {
    
    void insertar (int i);
    void eliminar();
    void recorrer();
    public Iterator getIterator();
    
}
