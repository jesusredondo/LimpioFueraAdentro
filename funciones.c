//
// Created by jesus on 5/11/18.
//

#include <stdlib.h>
#include "funciones.h"
#include "globales.h"
#include <omp.h>

//Inicializa las estructuras de índices para una anidación.
void inicializarMemoria(){
    //Estructura para guardar los índices en las llamadas recursivas:
    indicesRecursivo = (int*) malloc(sizeof(int) *ordenEstaAnidacion);
    indicesFilaRecursivo = (int *) malloc(sizeof(int)*ordenEstaAnidacion);
    //Estructura para guardar los índices en el lateral.
    indicesLateralRecursivo = (int*) malloc(sizeof(int) * (ordenEstaAnidacion-2));
    indicesFilaLateralRecursivo = (int*) malloc(sizeof(int) * (ordenEstaAnidacion-2));
    indicesNoUtilizadosRecursivo = (int*) malloc(sizeof(int) * primoRecursivo.numPares);
}

//Destruye la memoria
void destruirMemoria(){
    //Indices
    free(indicesRecursivo);
    free(indicesFilaRecursivo);
    //Indices laterales
    free(indicesLateralRecursivo);
    free(indicesFilaLateralRecursivo);
    free(indicesNoUtilizadosRecursivo);
}





int contieneArray(int * array,int longitud, int valor){
    for (int i = 0; i < longitud ; ++i) {
        if(array[i] == valor){
            return TRUE;
        }
    }
    return FALSE;
}




double inicio;
double fin;
void inicioTiempo(){
    //start = clock();
    inicio = omp_get_wtime();
}

void finTiempo(){
    fin = omp_get_wtime();
}

void pintarTiempo(){
    printf("%f segundos\n",fin-inicio);
}






