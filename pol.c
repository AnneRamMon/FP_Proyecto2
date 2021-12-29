#include "pol.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/* Función: Inicia el programa con los valores iniciales establecidos para la memoria
 *  Programada por: Ramírez Monzón Ana Cristina
 *  Fecha de modificación: 16/12/21
 */
void iniciar_memoria()
{
    memoria_principal.datos = (polinomio *)malloc(10 * sizeof(polinomio));
    memoria_principal.numPol = 0;
}

/* Función: Lee polinomio desde teclado, apartendo memoria para los términos del mismo
 *  Programada por: Arzate Huerta Monserrat Alexandra, Ramírez Monzón Ana Cristina y Garcia Hernandez Diego Aldair.
 *  Fecha de modificación: 16/12/21
 */
polinomio leer_polinomio()
{
    //"Digita el numero de datos, coeficientes, exponentes"
    polinomio p;
    int i, numTerm;
    termino t0;
    printf("Introduzca el grado del polinomio: \n");
    scanf("%d", &p.grado);
    printf("Introduzca el numero de terminos que tiene el polinomio: ");
    scanf("%d", &p.numTerm);
    p.terminos = (termino *)malloc(numTerm * sizeof(termino));
    // p.numTerm = numTerm;
    printf("\n%d", p.numTerm);
    printf("\n--- Polinomio---\n");
    for (i = 0; i < p.numTerm; i++)
    {
        printf("Introduzca el exponente ENTERO del término %d : ", i + 1);
        scanf("%d", &p.terminos[i].exp);
        printf("Introduzca el coeficiente REAL del término %d : ", i + 1);
        scanf("%f", &p.terminos[i].coef);
    }
    return p;
}

/* Función: Imprime en consola un polinomio elemento de la memoria
 *  Programada por: Ramírez Monzón Ana Cristina
 *  Fecha de modificación: 16/12/21
 */
void mostrar_polinomio(int n)
{
    fflush(stdin);
    imprimir_polinomio(memoria_principal.datos[n - 1]);
}

/* Función:Imprime un polinomio en consola, descartando términos cuyo coeficiente sea igual a 0
 *  Programada por: Garcia Hernandez Diego Aldair.
 *  Fecha de modificación: 20/12/21
 */
void imprimir_polinomio(polinomio p) // L
{
    if (p.terminos[0].coef == 0.00)
    {
        printf("\t");
    }
    else if (p.terminos[0].coef < 0 || p.terminos[0].coef > 0)
    {
        printf("\t%.2fx^%i ", p.terminos[0].coef, p.terminos[0].exp);
    }
    else if (p.terminos[0].exp == 0)
    {
        printf("\t%.2f ", p.terminos[0].coef);
    }
    else if (p.terminos[0].exp == 1)
    {
        printf("\t%.2fx ", p.terminos[0].coef);
    }

    for (int i = 1; i < p.numTerm; i++)
    {
        if (p.terminos[i].exp == 0 && p.terminos[i].coef > 0)
        {
            printf("+ %.2f ", p.terminos[i].coef);
        }
        else if (p.terminos[i].exp == 0 && p.terminos[i].coef < 0)
        {
            printf("%.2f ", p.terminos[i].coef);
        }
        else if (p.terminos[i].exp == 1 && p.terminos[i].coef > 0)
        {
            printf("+ %.2fx ", p.terminos[i].coef);
        }
        else if (p.terminos[i].exp == 1 && p.terminos[i].coef < 0)
        {
            printf("%.2fx ", p.terminos[i].coef);
        }
        else if (p.terminos[i].coef < 0)
        {
            printf("%.2fx^%i ", p.terminos[i].coef, p.terminos[i].exp);
        }
        else if (p.terminos[i].coef > 0)
        {
            printf("+ %.2fx^%i ", p.terminos[i].coef, p.terminos[i].exp);
        }
        else if (p.terminos[i].coef == 0.00)
        {
            printf("");
        }
    }
    printf("\n");
}

/* Función: Lee polinomio desde memoria, para ser usado en operaciones.
 *  Programada por: Ramírez Monzón Ana Cristina
 *  Fecha de modificación: 17/12/21
 */
polinomio leer_memoria(int n)
{
    polinomio p0;
    p0.terminos = (termino *)malloc((memoria_principal.datos[n - 1].numTerm) * sizeof(termino));
    p0 = memoria_principal.datos[n - 1];
    return p0;
}

/* Función: Escribe un polinomio en memoria, apartando espacio en la memoria principal
 *  Programada por: Ramírez Monzón Ana Cristina
 *  Fecha de modificación: 20/12/21
 */
void escribir_memoria(polinomio p0)
{
    if (memoria_principal.numPol >= 0 && memoria_principal.numPol < 10)
    {

        memoria_principal.datos[memoria_principal.numPol] = p0;
        memoria_principal.numPol++;
    }
    else if (memoria_principal.numPol >= 10)
    {

        (memoria_principal.numPol)++;
        memoria_principal.datos = (polinomio *)realloc(memoria_principal.datos, memoria_principal.numPol * sizeof(polinomio));
        memoria_principal.datos[memoria_principal.numPol - 1] = p0;
    }
}

/* Función: Ordena los términos del polinomio de forma decreciente con respecto a sus exponentes
 *  Programada por: Garcia Hernandez Diego Aldair
 *  Fecha de modificación: 23/12/21
 */
void burbuja(polinomio p)
{
    bool follow = true;
    int pasada;
    int i, numTerm;
    termino aux;
    for (pasada = 0; pasada < p.numTerm && follow; pasada++)
    {
        follow = false;
        for (i = 0; i < p.numTerm - 1 - pasada; i++)
        {
            if (p.terminos[i].exp < p.terminos[i + 1].exp)
            {
                aux = p.terminos[i];
                p.terminos[i] = p.terminos[i + 1];
                p.terminos[i + 1] = aux;
                follow = true;
            }
        }
    }
}

/* Función: Recibe dos polinomios para efectuar la suma, devolviendo polinomio resultante.
 *  Programada por: Arzate Huerta Monserrat Alexandra
 *  Fecha de modificación: 17/12/21
 */

polinomio pol_suma(polinomio p0, polinomio p1)
{
    polinomio res;
    int k = 0, j = 0, i = 0;
    termino t0, t1;
    res.numTerm = p0.numTerm + p1.numTerm;
    res.terminos = (termino *)malloc(res.numTerm * sizeof(termino));
    // codigo para suma
    while (i < p0.numTerm) // recorrer todos los términos del primer polinomio
    {
        while (p0.terminos[i].exp < p1.terminos[j].exp)
        {
            res.terminos[k].coef = (p1.terminos[j].coef);
            res.terminos[k].exp = p1.terminos[j].exp;
            k++;
            j++;
        }
        while (j < p1.numTerm)
        {
            t0 = p0.terminos[i];
            t1 = p1.terminos[j];
            if (t0.exp > t1.exp)
            {
                res.terminos[k].coef = t0.coef;
                res.terminos[k].exp = t0.exp;
                k++;
                i++;
            }
            else if (t0.exp == t1.exp)
            {
                res.terminos[k].coef = t0.coef + t1.coef;
                res.terminos[k].exp = t1.exp;
                i++;
                j++;
                k++;
            }
            else if (t0.exp < t1.exp)
            {
                res.terminos[k].coef = t1.coef;
                res.terminos[k].exp = t1.exp;
                k++;
                j++;
            }
        }
    }
    // contar de terminos del polinomio resultante: k
    res.numTerm = k;
    res.terminos = (termino *)realloc(res.terminos, k * sizeof(termino));
    return res;
}

/* Función: Recibe dos polinomios para realizar la resta, devolviendo polinomio resultante.
 *  Programada por: Ramírez Monzón Ana Cristina
 *  Fecha de modificación: 17/12/21
 */

polinomio pol_resta(polinomio p0, polinomio p1)
{
    polinomio res;
    int k = 0; // contador de términos de polinomio resultante
    int i = 0, j = 0;
    termino t0, t1;
    res.numTerm = p0.numTerm + p1.numTerm;
    res.terminos = (termino *)malloc(res.numTerm * sizeof(termino));
    // codigo para resta
    while (i < p0.numTerm) // recorrer todos los términos del primer polinomio
    {
        while (j < p1.numTerm) // recorrer todos los términos del segundo polinomio
        {
            t0 = p0.terminos[i];
            t1 = p1.terminos[j];
            if (t0.exp > t1.exp) // if (p0.terminos[i].exp > p1.terminos[i].exp)
            {
                res.terminos[k].coef = t0.coef; // pasa directamente término a resultado, sin cambiar signo por operación
                res.terminos[k].exp = t0.exp;
                k++;
                i++;
            }
            else if (t0.exp == t1.exp)
            {
                res.terminos[k].coef = t0.coef - t1.coef;
                res.terminos[k].exp = t0.exp;
                i++;
                j++;
                k++;
            }
            else if (t0.exp < t1.exp)
            {
                res.terminos[k].coef = (t1.coef) * -1; // coeficiente cambia de signo debido a resta
                res.terminos[k].exp = t1.exp;
                k++;
                j++;
            }
        }
    }
    // contar de terminos del polinomio resultante: k
    res.numTerm = k;
    // reajustar memoria usada
    res.terminos = (termino *)realloc(res.terminos, k * sizeof(termino));
    return res;
}

/* Función: Recibe un polinomio , recibe escalar para efectuar multiplicación y retorna polinomio resultante
 *  Programada por: Arzate Huerta Monserrat Alexandra
 *  Fecha de modificación: 18/12/21
 */
polinomio pol_multiplicacion_escalar(polinomio p0, polinomio res)
{
    int i, k;
    float scalar;
    res.numTerm = p0.numTerm;
    res.terminos = (termino *)malloc(res.numTerm * sizeof(termino));
    printf("Introduzca el escalar a multiplicar por el polinomio: ");
    scanf("%f", &scalar);
    for (int i = 0; i < p0.numTerm; i++)
    {
        res.terminos[i].coef = (p0.terminos[i].coef) * (scalar);
        res.terminos[i].exp = p0.terminos[i].exp;
    }

    return res;
}

/* Función:Recibe dos polinomios para efectuar la multiplicación y retorna polinomio resultante
 *  Programada por: Garcia Hernandez Diego Aldair
 *  Fecha de modificación: 23/12/21
 */
polinomio pol_multiplicacion(polinomio p0, polinomio p1)
{
    polinomio res;
    int k = 0, j = 0, i = 0, l = 0, h = 0;
    termino t0, t1, eliminado;
    res.numTerm = p0.numTerm + p1.numTerm;
    res.terminos = (termino *)malloc(res.numTerm * sizeof(termino));
    // codigo para multiplicación
    for (int i = 0; i < p0.numTerm; i++)
    {
        for (int j = 0; j < p1.numTerm; j++, k++)
        {
            t0 = p0.terminos[i];
            t1 = p1.terminos[j];

            res.terminos[k].coef = t0.coef * t1.coef;
            res.terminos[k].exp = t0.exp + t1.exp;
        }
    }

    res.numTerm = k;
    burbuja(res);

    for (int l = 0; l < res.numTerm; l++)
    {
        if (res.terminos[l].exp == res.terminos[l + 1].exp)
        {
            res.terminos[l].coef = res.terminos[l].coef + res.terminos[l + 1].coef;
            res.terminos[l].exp = res.terminos[l].exp;
            // l++;
            eliminado = res.terminos[l];
            for (i = 0; i < res.numTerm; i++)
            {
                if (i == l)
                {
                    while (i < res.numTerm)
                    {
                        res.terminos[i] = res.terminos[i + 1];
                        i++;
                    }
                    break;
                }
            }
            res.numTerm -= 1;
        }
        else
        {
            res.terminos[l].coef = res.terminos[l].coef;
            res.terminos[l].exp = res.terminos[l].exp;
        }
    }
    // contar de terminos del polinomio resultante: k
    res.terminos = (termino *)realloc(res.terminos, k * sizeof(termino));
    return res;
}

/* Función: Recibe un polinomio y un monomio para efectuar la division y retorna el polinomio resultante.
 *  Programada por: Arzate Huerta Monserrat Alexandra
 *  Fecha de modificación: 18/12/21
 */
polinomio pol_divisionm(polinomio p0, polinomio res)
{

    int i, k, e;
    float c;
    res.numTerm = p0.numTerm;
    res.terminos = (termino *)malloc(res.numTerm * sizeof(termino));
    printf("Introduzca el exponente del monomio ");
    scanf("%d", &e);
    printf("Introduzca el coeficiente del monomio ");
    scanf("%f", &c);

    for (int i = 0; i < p0.numTerm; i++)
    {
        res.terminos[i].exp = p0.terminos[i].exp - e;
        res.terminos[i].coef = p0.terminos[i].coef / c;
    }

    return res;
}

/* Función: Recibe un polinomio y un binomio para efectuar la division y retorna el polinomio resultante.
 *  Programada por: Ramírez Monzón Ana Cristina.
 *  Fecha de modificación: 20/12/21
 */
polinomio pol_division(polinomio p0, polinomio bin)
{
    if (bin.terminos[1].exp == 0)
    {
        int x, i, j, k;
        x = bin.terminos[1].coef;
        printf("%i\n", x);

        polinomio aux, res;

        aux.numTerm = p0.grado + 1;
        aux.grado = p0.grado;
        aux.terminos = (termino *)malloc(aux.numTerm * sizeof(termino));

        res.numTerm = p0.grado;
        res.grado = p0.grado - 1;
        res.terminos = (termino *)malloc(res.numTerm * sizeof(termino));

        // Asignar coeficientes de p0 a aux, llenando espacios con ceros
        // Se usa para recorrer términos de aux(aumentar después de asignar coeficientes)
        k = p0.grado;
        i = 0;
        j = 0;
        while ((k > -1) && (i < p0.numTerm + 1) && (j < p0.grado + 1))
        {
            if (p0.terminos[i].exp == k) // permitir aumento de "i", permitir aumento de j
            {
                aux.terminos[j] = p0.terminos[i]; // asignamos directamente el término a aux
                k--;
                i++;
                j++;
            }
            else // mantener valor de i, permitir aumento de j;
            {

                aux.terminos[j].coef = 0; // llenar coeficiente faltante con 0
                aux.terminos[j].exp = k;
                // mantener valor de "i" para comparar con k en siguiente iteración
                k--;
                j++;
            }
        }

        imprimir_polinomio(aux);
        res.terminos[0].coef = aux.terminos[0].coef;
        res.terminos[0].exp = aux.terminos[0].exp - 1;
        float residuo;
        for (int i = 1; i < aux.numTerm; i++)
        {
            res.terminos[i].coef = aux.terminos[i].coef + (res.terminos[i - 1].coef * (x * (-1)));
            res.terminos[i].exp = aux.terminos[i].exp - 1;
            residuo = aux.terminos[i + 1].coef + (res.terminos[i].coef * (x * (-1))) / (-x);
        }
        printf("El residuo es: %f /x +(%i)\n", residuo, x);
        return res;
    }
    else
    {
        printf("Error al leer binomio\n");
        return p0;
    }
}

/* Función: Imprime en consola todos los polinomios almacenados en memoria
 *  Programada por: Ramírez Monzón Ana Cristina.
 *  Fecha de modificación: 19/12/21
 */
void imprimir_memoria()
{
    int i;
    for (i = 0; i < memoria_principal.numPol; i++)
    {
        imprimir_polinomio(memoria_principal.datos[i]);
    }
}

/* Función: Lee el polinomio del archivo <datos.txt> y lo almacena en memoria
 *  Programada por: Santiago Augusto Kam
 *  Fecha de modificación: 21/12/21
 */
polinomio leer_archivo()
{
    polinomio p;
    FILE *archivo;
    float coef;
    int exp;
    fflush(stdin);
    printf("Introduzca el numero de terminos del polinomio en el archivo: ");
    scanf("%d", &p.numTerm);
    archivo = fopen("datos.txt", "r");
    p.terminos = (termino *)malloc(p.numTerm * sizeof(polinomio));

    // Tomar datos del archivo y asignarlos a sus respectivas variables
    for (int i = 0; i < p.numTerm; i++)
    {

        fscanf(archivo, "%f", &coef);
        p.terminos[i].coef = coef;
        fscanf(archivo, "%d", &exp);
        p.terminos[i].exp = exp;
        // printf("%f", coefExpTemp[50]);
    }
    printf("Datos contenidos en el archivo\n");
    for (int k = 0; k < p.numTerm; k++)
    {
        printf("\t%.2f", p.terminos[k].coef);
        printf("\t%d", p.terminos[k].exp);
    }
    escribir_memoria(p);
    fclose(archivo);
}

/* Función: Imprime todos los polinomios de la memoria en el archivo <escritura.txt>
 *  Programada por: Santiago Augusto Kam
 *  Fecha de modificación: 21/12/21
 */
void escribir_archivo(polinomio p)
{
    FILE *archivo = fopen("escritura.txt", "w");
    if (archivo == NULL)
    {
        printf("Error en la creación del archivo\n");
    }
    for (int i = 0; i < memoria_principal.numPol; i++)
    {
        imprimir_polinomio_arch(memoria_principal.datos[i - 1]);
    }
    fclose(archivo);
}

/* Función: Recibe un polinomio y lo imprime en el archivo <escritura.txt>
 *  Programada por: Santiago Augusto Kam
 *  Fecha de modificación: 21/12/21
 */
void imprimir_polinomio_arch(polinomio p)
{
    FILE *archivo = fopen("escritura.txt", "w");
    if (p.terminos[0].coef == 0.00)
    {
        fprintf(archivo, "\t");
    }
    else if (p.terminos[0].coef < 0 || p.terminos[0].coef > 0)
    {
        fprintf(archivo, "\t%.2fx^%i ", p.terminos[0].coef, p.terminos[0].exp);
    }
    else if (p.terminos[0].exp == 0)
    {
        fprintf(archivo, "\t%.2f ", p.terminos[0].coef);
    }
    else if (p.terminos[0].exp == 1)
    {
        fprintf(archivo, "\t%.2fx ", p.terminos[0].coef);
    }

    for (int i = 1; i < p.numTerm; i++)
    {
        if (p.terminos[i].exp == 0 && p.terminos[i].coef > 0)
        {
            fprintf(archivo, "+ %.2f ", p.terminos[i].coef);
        }
        else if (p.terminos[i].exp == 0 && p.terminos[i].coef < 0)
        {
            fprintf(archivo, "%.2f ", p.terminos[i].coef);
        }
        else if (p.terminos[i].exp == 1 && p.terminos[i].coef > 0)
        {
            fprintf(archivo, "+ %.2fx ", p.terminos[i].coef);
        }
        else if (p.terminos[i].exp == 1 && p.terminos[i].coef < 0)
        {
            fprintf(archivo, "%.2fx ", p.terminos[i].coef);
        }
        else if (p.terminos[i].coef < 0)
        {
            fprintf(archivo, "%.2fx^%i ", p.terminos[i].coef, p.terminos[i].exp);
        }
        else if (p.terminos[i].coef > 0)
        {
            fprintf(archivo, "+ %.2fx^%i ", p.terminos[i].coef, p.terminos[i].exp);
        }
        else if (p.terminos[i].coef == 0.00)
        {
            fprintf(archivo, "");
        }
    }
    printf("\n");
    fclose(archivo);
}

// mostrar polinomio archivo
/* Función: Recibe un entero indicando la posición del polinomio seleccionado de la memoria para
 *  imprimirlo
 *  Programada por: Santiago Augusto Kam
 *  Fecha de modificación: 21/12/21
 */
void mostrar_polinomio_archivo(int n)
{
    fflush(stdin);
    imprimir_polinomio_arch(memoria_principal.datos[n - 1]);
}

/* Función: Escribe la memoria de la calculadora en el archivo <escritura.txt>
 *  Programada por: Ramírez Monzón Ana Cristina
 *  Fecha de modificación: 22/12/21
 */
void mostrar_memoria_archivo()
{
    FILE *archivo = fopen("escritura.txt", "w");
    polinomio p;
    fprintf(archivo, "--------------Memoria de calculadora de polinomios---------\n");
    for (int j = 1; j < memoria_principal.numPol + 1; j++)
    {
        p = leer_memoria(j);
        if (p.terminos[0].coef == 0.00)
        {
            fprintf(archivo, "\t");
        }
        else if (p.terminos[0].coef < 0 || p.terminos[0].coef > 0)
        {
            fprintf(archivo, "\t%.2fx^%i ", p.terminos[0].coef, p.terminos[0].exp);
        }
        else if (p.terminos[0].exp == 0)
        {
            fprintf(archivo, "\t%.2f ", p.terminos[0].coef);
        }
        else if (p.terminos[0].exp == 1)
        {
            fprintf(archivo, "\t%.2fx ", p.terminos[0].coef);
        }

        for (int i = 1; i < p.numTerm; i++)
        {
            if (p.terminos[i].exp == 0 && p.terminos[i].coef > 0)
            {
                fprintf(archivo, "+ %.2f ", p.terminos[i].coef);
            }
            else if (p.terminos[i].exp == 0 && p.terminos[i].coef < 0)
            {
                fprintf(archivo, "%.2f ", p.terminos[i].coef);
            }
            else if (p.terminos[i].exp == 1 && p.terminos[i].coef > 0)
            {
                fprintf(archivo, "+ %.2fx ", p.terminos[i].coef);
            }
            else if (p.terminos[i].exp == 1 && p.terminos[i].coef < 0)
            {
                fprintf(archivo, "%.2fx ", p.terminos[i].coef);
            }
            else if (p.terminos[i].coef < 0)
            {
                fprintf(archivo, "%.2fx^%i ", p.terminos[i].coef, p.terminos[i].exp);
            }
            else if (p.terminos[i].coef > 0)
            {
                fprintf(archivo, "+ %.2fx^%i ", p.terminos[i].coef, p.terminos[i].exp);
            }
            else if (p.terminos[i].coef == 0.00)
            {
                fprintf(archivo, "");
            }
        }
        fprintf(archivo, "\n");
    }
    fclose(archivo);
}