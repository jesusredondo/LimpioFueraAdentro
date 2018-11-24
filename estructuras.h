//
// Created by Jesús Redondo García on 28/10/2018.
//

#ifndef LIMPIOFUERAADENTRO_ESTRUCTURAS_H
#define LIMPIOFUERAADENTRO_ESTRUCTURAS_H


#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#include <stdio.h>

typedef unsigned long long BigInt;
//Necesitamos dos estructuras para almacenar la información:

//Una estructura que guarda un par y el siguiente par (una lista enlazada, para que crezca dinámicamente, no sabemos el número de pares de un primo).
typedef struct _S_Par {
    BigInt primeroPar;
    BigInt segundoPar;
    struct _S_Par* siguiente;
}Par;

//Una estructura que guarda un primo y sus pares asociados.
typedef struct _S_primoConPares{
    BigInt primo;
    BigInt numPares;
    BigInt ** pares;
}PrimoConPares;


//Una estructura que nos permite guardar info sobre el cuadrado que estamos resolviendo o bien cargarlo desde un fichero.
typedef struct _S_InfoResolucion{
    BigInt primoCentral;
    BigInt ordenCuadradoBase;
    BigInt paresNecesarios;
}InfoResolucion;

#endif //LIMPIOFUERAADENTRO_ESTRUCTURAS_H
