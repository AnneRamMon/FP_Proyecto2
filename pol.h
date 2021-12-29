#ifndef POL_H
#define POL_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int contadormemoria;

struct _termino
{
    float coef;
    int exp;
};

typedef struct _termino termino;

struct _polinomio
{
    int grado;
    int numTerm;
    termino *terminos; //terminos[numTerm];
};

typedef struct _polinomio polinomio;

struct _memoria
{
    polinomio *datos;
    int numPol;
};

typedef struct _memoria memoria;

memoria memoria_principal;

polinomio pol_suma(polinomio , polinomio );
polinomio pol_resta(polinomio , polinomio );
polinomio pol_multiplicacion_escalar(polinomio , polinomio);
polinomio pol_multiplicacion(polinomio , polinomio );
polinomio pol_divisionm(polinomio , polinomio );
polinomio pol_division(polinomio , polinomio );
void iniciar_memoria();
void escribir_memoria(polinomio);
polinomio leer_memoria(int);
polinomio leer_polinomio();
void burbuja(polinomio); 
void mostrar_polinomio(int n);
void imprimir_polinomio(polinomio);
void imprimir_memoria();

polinomio leer_archivo();
void escribir_archivo(polinomio p);

void imprimir_polinomio_arch(polinomio p);
void mostrar_polinomio_archivo(int n);
void mostrar_memoria_archivo();

#endif //!POL_H