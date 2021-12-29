#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "pol.h"

void menu();
void man(int num);
int main()
{

    int op;
    polinomio p, p0, p1, res;
    int n, n0, n1, num;
    iniciar_memoria();
    while (true)
    {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("----------Leer polinomio de teclado------------\n");
            p = leer_polinomio();
            burbuja(p);
            escribir_memoria(p);
            break;

        case 2:
            printf("----------Leer polinomio de archivo------------\n");
            printf("----------Se leerá el archivo: <datos.txt>\n");
            p = leer_archivo();
            burbuja(p);
            break;

        case 3:
            printf("----------Suma------------\n");
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            printf("Selecciona 2: \n");
            scanf("%i", &n0);
            scanf("%i", &n1);
            p0 = leer_memoria(n0);
            p1 = leer_memoria(n1);
            mostrar_polinomio(n0);
            mostrar_polinomio(n1);
            res = pol_suma(p0, p1);
            imprimir_polinomio(res);
            escribir_memoria(res);
            break;

        case 4:
            printf("----------Resta------------\n");
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            printf("Selecciona 2: \n");
            scanf("%i", &n0);
            scanf("%i", &n1);
            p0 = leer_memoria(n0);
            p1 = leer_memoria(n1);
            mostrar_polinomio(n0);
            mostrar_polinomio(n1);
            res = pol_resta(p0, p1);
            imprimir_polinomio(res);
            escribir_memoria(res);
            break;

        case 5:
            printf("----------Multiplicacion por escalar------------\n");
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            printf("Selecciona 1: \n");
            scanf("%i", &n0);
            p0 = leer_memoria(n0);
            mostrar_polinomio(n0);
            res = pol_multiplicacion_escalar(p0, res);
            imprimir_polinomio(res);
            escribir_memoria(res);
            break;

        case 6:
            printf("----------Multiplicacion------------\n");
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            printf("Selecciona 2: \n");
            scanf("%i", &n0);
            scanf("%i", &n1);
            p0 = leer_memoria(n0);
            p1 = leer_memoria(n1);
            mostrar_polinomio(n0);
            mostrar_polinomio(n1);
            pol_multiplicacion(p0, p1);
            escribir_memoria(res);
            break;

        case 7:
            printf("----------Division entre monomio------------\n");
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            printf("Selecciona 1: \n");
            scanf("%i", &n0);
            p0 = leer_memoria(n0);
            mostrar_polinomio(n0);
            res = pol_divisionm(p0, res);
            imprimir_polinomio(res);
            escribir_memoria(res);
            break;

        case 8:
            printf("----------Division entre binomio------------\n");
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            printf("Selecciona 1 polinomio: \n");
            scanf("%i", &n0);
            p0 = leer_memoria(n0);
            mostrar_polinomio(n0);
            printf("Selecciona 1 binomio: \n");
            scanf("%i", &n1);
            p1 = leer_memoria(n1);
            mostrar_polinomio(n1);
            res = pol_division(p0, p1);
            imprimir_polinomio(res);
            escribir_memoria(res);
            break;

        case 9:
            printf("----------Escribir en pantalla------------\n");
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            printf("Selecciona 1: \n");
            scanf("%i", &n);
            leer_memoria(n);
            mostrar_polinomio(n);
            break;

        case 10:
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            printf("Selecciona 1: \n");
            scanf("%i", &n);
            leer_memoria(n);
            mostrar_polinomio_archivo(n);
            break;
            // escribir_archivo(p)

        case 11:
            printf("-------------------Polinomios en memoria-----------\n");
            printf("Existen en memoria %d polinomios\n", memoria_principal.numPol);
            imprimir_memoria();
            break;

        case 12:
            man(num);
            break;

        case 13:
            mostrar_memoria_archivo();
            free(memoria_principal.datos);
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("\nOpción no valida\n");
        }
    }
    system("pause");
    return 0;
}

void menu()
{
    printf("\n----------Calculadora de polinomios----------\n");
    printf("1. Leer polinomio de teclado\n");
    printf("2. Leer polinomio de archivo\n");
    printf("3. Suma\n");
    printf("4. Resta\n");
    printf("5. Multiplicación con un escalar\n");
    printf("6. Multiplicación\n");
    printf("7. División entre monomio\n");
    printf("8. División entre binomio\n");
    printf("9. Escribir en pantalla\n");
    printf("10. Escribir a un archivo\n");
    printf("11. Mostrar polinomios en memoria\n");
    printf("12. Manual de usuario \n");
    printf("13. Salir \n");
}

void man(int num)
{
    printf("-------------------Manual de usuario-----------\n");
    printf("Se despliega un menu que incluye diversas opciones que pueden ser seleccionadas,\nsin embargo, para comenzar, es necesario ");
    printf("ingresar polinomios para que sean almacenados en memoria, \nesto puede realizarse seleccionando la opción 1 o 2.");
    printf("\n");
    printf("\n1. Leer polinomio de teclado\n");
    printf("2. Leer polinomio de archivo\n");
    printf("3. Suma, Resta y Multiplicacion\n");
    printf("4. Multiplicación con un escalar\n");
    printf("5. División entre monomio\n");
    printf("6. División entre binomio\n");
    printf("7. Escribir en pantalla\n");
    printf("8. Escribir a un archivo\n");
    printf("9. Mostrar polinomios en memoria\n");
    printf("\n Selecciona una opccion para saber como utilizarla: \n");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("\n----------Leer polinomio de teclado------------\n");
        printf("Esta opcion solicita el grado del polinomio, el numero de terminos que lo componen,\n");
        printf("sus coeficientes y exponentes; ingresa la informacion solicitada. \n");
        printf("Al finalizar el ingreso de los coeficientes y exponentes del polinomio, este sera almacenado en la memoria de la calculadora.");
        break;
    case 2:
        printf("\n----------Leer polinomio de archivo------------\n");
        printf("La opcion leer polinomio desde archivo, lee un archivo .txt con nombre indicado en el codigo,\nlocalizado en la misma carpeta que el codigo ");
        printf("y el ejecutable, de forma predeterminada se leera el archivo con nombre \ndatos.txt en el caso en el que se quiera leer un archivo fuera de la carpeta se debera indicar la ruta del mismo en el codigo.\n");
        printf("Al seleccionar la opcion, se preguntará por el numero de terminos, es decir el numero de conjuntos de coeficientes y exponentes\n");
        printf("Cada numero esta separado por un triple espacio y tiene que ser estrictamente escrito de esta forma, de lo contrario no funcionara correctamente.\n");
        printf("Esto ya que esta función está basada principalmente en la función fscanf, y la forma en la que este lee los conjuntos es en pares separada por un tabulador.\n");
        printf("Una vez tomados los datos de archivo, los guardara en la memoria y fungira como cualquiera de los demás polinomios escritos desde teclado.\n");
        break;

    case 3:
        printf("\n----------Suma, Resta y Multiplicacion------------\n");
        printf(" Dependiendo del numero de los polinomios que ingresaste podras elegir dos para realizar dichas operaciones,\npara esto ingresa el numero del polinomio separandolos con un salto de linea.");
        break;
    case 4:
        printf("\n----------Multiplicacion por escalar------------\n");
        printf("En esta opccion se  solicitara que selecciones un polinomio de la memoria, y posteriormente deberas ingresar el escalar que usaras para la operación, \ndespues se te mostrara el resultado de la misma, y el polinomio resultante sera escrito en memoria.");

        break;
    case 5:
        printf("\n----------Division entre monomio------------\n");
        printf("Este opcion  solicita la selección de un polinomio en memoria, y posteriormente el\n");
        printf("exponente y coeficiente del monomio para realizar la operacion, se mostrara el polinomio resultante en consola y se almacenara en la memoria.\n");
        break;
    case 6:
        printf("\n----------Division entre binomio------------\n");
        printf("Esta opcion solicita la seleccion de un polinomio de la memoria, y posteriormente un binomio almacenado en memoria,\n");
        printf("se debe tener en cuenta que el binomio seleccionado debe ser de grado 1 y contener dos terminos,\n siendo que debe componerse de una incognita de coeficiente 1 y exponente 1, y un termino independiente.");

        break;
    case 7:
        printf("\n----------Escribir en pantalla------------\n");
        printf("Esta opcion te mostrara el polinomio en la posición de memoria que selecciones.");

        break;
    case 8:
        printf("-------------------Escribir a un archivo-------------------\n");
        printf("La opcion escribir a un archivo, escribira el polinomio seleccionado en el archivo localizado en la carpeta del codigo y del ejecutable,\n ");
        printf("con nombre escritura.txt en el caso de querer cambiar el archivo se deberá indicar la ruta o el nombre del archivo en el caso de que esté \n ");
        printf("en la misma carpeta que el ejecutable.\n");
        printf("Esta funcion, llama a su vez a la funcion imprimir_polinomio_arch, imprime el polinomio en memoria indicado mediante la variable n dentro \n ");
        printf("de esta función hay una serie de verificaciones e iteraciones para verificar si hay exponentes = 0 o = 1 y que de este modo no se impriman\n ");
        printf("en pantalla para parecer mas convencional. La función esta basada en la función fprintf funcionando como un printf comun.\n");
        printf("El modo en que se imprimen los datos sera de la forma comunmente usada, el programa agrega las x correspondientes, \n");
        printf("así como ^ para indicar el exponente de su coeficiente.\n");

        break;

    case 9:
        printf("-------------------Polinomios en memoria-----------\n");
        printf("Esta opcion te indicara el numero de polinomios en memoria y se imprimiran en la consola los polinomios almacenados en formato de lista.\n");

        break;

    default:
        printf("\nOpción no valida\n");
    }
}