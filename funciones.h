//
// Created by jesus on 5/11/18.
//

#ifndef LIMPIOFUERAADENTRO_FUNCIONES_H
#define LIMPIOFUERAADENTRO_FUNCIONES_H






//Memoria
void inicializarMemoria();
void destruirMemoria();
int contieneArray(int * array,int longitud, int valor);

//Tiempo
#include <time.h>
clock_t start;
clock_t end;
void inicioTiempo();
void finTiempo();
void pintarTiempo();

#endif //LIMPIOFUERAADENTRO_FUNCIONES_H
