//
// Created by Jesús Redondo García on 28/10/2018.
//

#ifndef LIMPIOFUERAADENTRO_GLOBALES_H
#define LIMPIOFUERAADENTRO_GLOBALES_H



#include "estructuras.h"

extern size_t tamanioBigInt;


extern const int ordenNuevo; //Lo cambiamos por el compilador de linux.
extern  BigInt paresNecesarios;
extern int indiceCandidato;


extern  BigInt RANGO_CANDIDATOS; //Los primeros candidatos que se van a comprobar.
extern BigInt  RANGO_CRIBA; //Los primos que se cargan, ya cribados

extern PrimoConPares* primosCandidatos; //Posición de memoria desde donde se almacenan todos los primos con sus pares que son candidatos como centro del cuadrado.
extern BigInt numPrimos; //Los primos que hay en el fichero
extern BigInt numPrimosCandidatos; //Los primos candidatos que se han cargado

extern char * FICHERO_PARES;



extern int ordenEstaAnidacion; //El orden de la anidación actual que se está resolviendo.

//Estructura para guardar los índices en las llamadas recursivas:
extern int * indicesRecursivo;
extern int * indicesFilaRecursivo;

extern PrimoConPares primoRecursivo;
extern BigInt derechaArribaRecursivo;
extern BigInt derechaAbajoRecursivo;
extern int * indicesNoUtilizadosRecursivo;
extern int numCombinacionesLateralesRecursivo;
extern int numParesRestantesLateralRecursivo;
extern int * indicesLateralRecursivo; //Ojo al pasarlo a linux no puedo utilizar numCombinacionesLateralesRecursivo
extern int * indicesFilaLateralRecursivo; //Lo mismo que arriba.


#endif //LIMPIOFUERAADENTRO_GLOBALES_H
