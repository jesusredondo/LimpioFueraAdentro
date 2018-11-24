//
// Created by jesus on 4/11/18.
//

#include "globales.h"


size_t tamanioBigInt = sizeof(BigInt);

int ordenNuevo = 5; //Lo cambiamos por el compilador de linux.
BigInt paresNecesarios= 25;//ordenNuevo*ordenNuevo -1; //todo: Ojo que tengo pares de más

BigInt RANGO_CANDIDATOS = 200; //Los primeros candidatos que se van a comprobar.
BigInt  RANGO_CRIBA = 100000; //Los primos que se cargan, ya cribados

PrimoConPares* primosCandidatos; //Posición de memoria desde donde se almacenan todos los primos con sus pares que son candidatos como centro del cuadrado.
BigInt numPrimos; //Los primos que hay en el fichero
BigInt numPrimosCandidatos = 0; //Los primos candidatos que se han cargado

char * FICHERO_PARES = "primosConParesMenores";



int ordenEstaAnidacion; //El orden de la anidación actual que se está resolviendo.

//Estructura para guardar los índices en las llamadas recursivas:
int * indicesRecursivo;
int * indicesFilaRecursivo;

PrimoConPares primoRecursivo;
BigInt derechaArribaRecursivo;
BigInt derechaAbajoRecursivo;
int * indicesNoUtilizadosRecursivo;
int numCombinacionesLateralesRecursivo;
int numParesRestantesLateralRecursivo;
int * indicesLateralRecursivo; //Ojo al pasarlo a linux no puedo utilizar numCombinacionesLateralesRecursivo
int * indicesFilaLateralRecursivo; //Lo mismo que arriba.