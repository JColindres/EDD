/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tarea2;

import java.util.Scanner;

/**
 *
 * @author pablo
 */
public class Tarea2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        NameRepository namesRepository = new NameRepository();

        for (Iterator iter = namesRepository.getIterator(); iter.hasNext();) {
            String name = (String) iter.next();
            System.out.println("Name : " + name);
        }

        Scanner teclado = new Scanner(System.in);

        int op1 = 0;
        int op2 = 0;
        double precio = 0;

        System.out.println("Seleccione una opcion.");

        do {

            System.out.println("-------------------------");
            System.out.println("1 - Lista Simplemente enlazada (Ordenada)");
            System.out.println("2 - Cola");
            System.out.println("3 - Salir");

            op1 = Integer.parseInt(teclado.next());

            switch (op1) {
                case 1:

                    while (op2 <= 3) {
                        System.out.println("\n-------------------------");
                        System.out.println("Lista Simplemente enlazada (Ordenada)");
                        System.out.println("1 - Insertar");
                        System.out.println("2 - Eliminar");
                        System.out.println("3 - Buscar");
                        System.out.println("4 - Volver");

                        op2 = Integer.parseInt(teclado.next());
                    }

                //break;
                case 2:

                    while (op2 <= 3) {
                        System.out.println("\n-------------------------");
                        System.out.println("Cola");
                        System.out.println("1 - Insertar");
                        System.out.println("2 - Eliminar");
                        System.out.println("3 - Ver cola");
                        System.out.println("4 - Volver");

                        op2 = Integer.parseInt(teclado.next());
                        int i = 0;
                        Cola c = new Cola();

                        if (op2 == 1) {
                            System.out.println("\nIngrese un digito:");
                            i = Integer.parseInt(teclado.next());
                            c.insertar(i);
                        } else if (op2 == 2) {
                            c.eliminar();
                            c.contador();
                        } else if (op2 == 3) {
                            for (Iterator iter = c.getIterator(); iter.hasNext();) {
                                Object name = iter.next();
                                System.out.println("Numero : " + name);
                            }
                        }

                    }

                //break;
            }

        } while (op1 != 3);

    }

}
