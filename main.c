#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

//Mis includes
#include "solucion.h"
#include "cargaguarda.h"
#include "funciones.h"

//Autor: Jesús Redondo García

//CABECERAS:
void procesarCombinaciones(int numeroIndice, int porCualAndo);

void eliminarParesUtilizados(PrimoConPares antiguoPrimoRecursivo, int * antiguoIndicesRecursivo,int * antiguoIndicesLateralRecursivo, int antiguoOrdenEstaAnidacion){
    printf("El primo antes de esta anidación tenía %llu pares\n",primoRecursivo.numPares);
    primoRecursivo.numPares = primoRecursivo.numPares - (antiguoOrdenEstaAnidacion*2-2);
    printf("El primo después de esta anidación tendrá %llu pares\n",primoRecursivo.numPares);


    primoRecursivo.pares = malloc(sizeof( BigInt *) * 2);
    primoRecursivo.pares[0] = malloc(sizeof(BigInt) * primoRecursivo.numPares);
    primoRecursivo.pares[1] = malloc(sizeof(BigInt) * primoRecursivo.numPares);


    int indexAux = 0;
    for (int i = 0; i < antiguoPrimoRecursivo.numPares; ++i) {
        if(!contieneArray(antiguoIndicesRecursivo,antiguoOrdenEstaAnidacion,i)){
            if(!contieneArray(antiguoIndicesLateralRecursivo,antiguoOrdenEstaAnidacion-2,i)){ //Si no se ha usado, entonces lo metemos:
                primoRecursivo.pares[0][indexAux] = antiguoPrimoRecursivo.pares[0][i];
                primoRecursivo.pares[1][indexAux] = antiguoPrimoRecursivo.pares[1][i];
                indexAux++;
            }
        }
    }
}


//Comprueba si la fina superior de la anidación es válida.
int comprobarFilaCandidata(){
    BigInt acumulador = 0;
    for (int i = 0; i < ordenEstaAnidacion; ++i) {
        acumulador += primoRecursivo.pares[indicesFilaRecursivo[i]][indicesRecursivo[i]];
    }
    return acumulador == ordenEstaAnidacion*primoRecursivo.primo;
}

//Comprueba si la fila lateral escogida es correcta.
int comprobarLateralCandidato(){
    BigInt acumulador = derechaArribaRecursivo + derechaAbajoRecursivo;
    for (int i = 0; i < numCombinacionesLateralesRecursivo; ++i) {
        acumulador += primoRecursivo.pares[indicesFilaLateralRecursivo[i]][indicesLateralRecursivo[i]];
    }
    return acumulador == ordenEstaAnidacion*primoRecursivo.primo;
}


//Selecciona todas las posibles combinaciones de pares restantes (con filas).
void procesarCombinacionesRecursivaLateralFila(int profundidad){
    if(profundidad == numCombinacionesLateralesRecursivo){
        if(comprobarLateralCandidato()){
            printf("\n\tANIDACIÓN ENCONTRADA\n");
            guardarAnidacion();
            if(ordenEstaAnidacion == 3){
                printf("\n----------------------------");
                printf("\n\tCUADRADO MÁGICO ENCONTRADO");
                printf("\n----------------------------\n");
                pintarSolucion();
                if (comprobarSolucion()){
                    printf("Se ha encontrado una solución correcta al problema.\n");
                }


                destruirMemoria();
                liberarMemoriaSolucion();
                exit(0);


            } else{
                //TODO: Guardamos y pintamos la anidación:
                pintarSolucion();

                //TODO:Guardamos los valores y las referencias a memoria.
                int antiguoOrdenEstaAnidacion = ordenEstaAnidacion;

                //Indices fila superior
                int * antiguoIndicesRecursivo = indicesRecursivo;
                //Filas fila superior
                int * antiguoIndicesFilaRecursivo = indicesFilaRecursivo;
                //Indices Lateral
                int * antiguoIndicesLateralRecursivo = indicesLateralRecursivo;
                //Lateral de la fila
                int * antiguoIndicesFilaLateralRecursivo = indicesFilaLateralRecursivo;
                //PrimoConPares
                PrimoConPares antiguoPrimoRecursivo;
                antiguoPrimoRecursivo.primo = primoRecursivo.primo;
                antiguoPrimoRecursivo.numPares = primoRecursivo.numPares;
                antiguoPrimoRecursivo.pares = primoRecursivo.pares; //Nos quedamos con las referencias de memoria
                //Esquinas
                BigInt antiguoDerechaArribaRecursivo = derechaArribaRecursivo;
                BigInt antiguoDerechaAbajoRecursivo = derechaAbajoRecursivo;
                //Índices no utilizados, para los laterales
                int * antiguoIndicesNoUtilizadosRecursivo =indicesNoUtilizadosRecursivo;
                int antiguoNumCombinacionesLateralesRecursivo = numCombinacionesLateralesRecursivo;
                int antiguoNumParesRestantesLateralRecursivo = numParesRestantesLateralRecursivo;

                //TODO:Preparamos nuevos valores.
                ordenEstaAnidacion = ordenEstaAnidacion-2;
                //Indices:
                inicializarMemoria();
                //Actualizamos el primo porque ya no tiene tantos pares disponibles:
                eliminarParesUtilizados(antiguoPrimoRecursivo,antiguoIndicesRecursivo,antiguoIndicesLateralRecursivo,antiguoOrdenEstaAnidacion);


                //TODO: Anidamos con un orden menor
                printf("ANIDANDO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                procesarCombinaciones(0,0);
                printf("Se intentaría volver para atrás");

                //TODO: Si no se encontró anidación interior, restauramos valores.
                ordenEstaAnidacion = antiguoOrdenEstaAnidacion;
                destruirMemoria();
                //Recuperamos los indices:
                indicesRecursivo = antiguoIndicesRecursivo;
                //Filas fila superior
                indicesFilaRecursivo = antiguoIndicesFilaRecursivo;
                //Indices Lateral
                indicesLateralRecursivo = antiguoIndicesLateralRecursivo;
                //Lateral de la fila
                indicesFilaLateralRecursivo = antiguoIndicesFilaLateralRecursivo;
                //PrimoConPares
                free(primoRecursivo.pares[0]);
                free(primoRecursivo.pares[1]);
                free(primoRecursivo.pares);
                primoRecursivo.primo = antiguoPrimoRecursivo.primo;
                primoRecursivo.numPares = antiguoPrimoRecursivo.numPares;
                primoRecursivo.pares = antiguoPrimoRecursivo.pares;

                //Esquinas
                derechaArribaRecursivo = antiguoDerechaArribaRecursivo;
                derechaAbajoRecursivo = antiguoDerechaAbajoRecursivo;
                //Índices no utilizados, para los laterales
                indicesNoUtilizadosRecursivo = antiguoIndicesNoUtilizadosRecursivo;
                numCombinacionesLateralesRecursivo = antiguoNumCombinacionesLateralesRecursivo;
                numParesRestantesLateralRecursivo = antiguoNumParesRestantesLateralRecursivo;
            }
        }
    }
    else{
        for (int i = 0; i < 2; ++i) {
            indicesFilaLateralRecursivo[profundidad] = i;
            procesarCombinacionesRecursivaLateralFila(profundidad+1);
        }
    }
}


//Selecciona todas las posibles combinaciones de pares restantes (sin filas)
void combinacionesRecursivaLateral(int numeroIndice, int porCualAndo){
    if(numeroIndice == numCombinacionesLateralesRecursivo){ //caso base, he llenado el lateral
        //Procesar.
        procesarCombinacionesRecursivaLateralFila(0);
    }
    else{
        for (int i = porCualAndo; i <= numParesRestantesLateralRecursivo-(numCombinacionesLateralesRecursivo - numeroIndice) ; ++i) {
            indicesLateralRecursivo[numeroIndice]=indicesNoUtilizadosRecursivo[i];
            combinacionesRecursivaLateral(numeroIndice+1,i+1);
        }
    }
}


//Método que se encarga de inicializar la resolución de la parte derecha de una anidación (lateral).
//Se utiliza una vez hemos encontrado la fila superior.
void procesarLaterales(){

    //PRIMERO SELECCIONAMOS ESQUINAS:
    for(int esquinaIzquierda = 0; esquinaIzquierda < ordenEstaAnidacion-1; esquinaIzquierda++){
        for (int esquinaDerecha = esquinaIzquierda+1; esquinaDerecha < ordenEstaAnidacion; ++esquinaDerecha) {
            derechaArribaRecursivo = primoRecursivo.pares[indicesFilaRecursivo[esquinaDerecha]][indicesRecursivo[esquinaDerecha]];
            derechaAbajoRecursivo = 2*primoRecursivo.primo - primoRecursivo.pares[indicesFilaRecursivo[esquinaIzquierda]][indicesRecursivo[esquinaIzquierda]];

            //sacamos los índices que no han sido utilizados:
            int indiceAuxParaNoUtilizados = 0;
            for (int i = 0; i < primoRecursivo.numPares; ++i) {
                int indiceCogido = FALSE;
                for (int j = 0; j < ordenEstaAnidacion; ++j) {
                    if(indicesRecursivo[j] == i){
                        indiceCogido = TRUE;
                        break;
                    }
                }
                if(indiceCogido == FALSE){
                    indicesNoUtilizadosRecursivo[indiceAuxParaNoUtilizados] = i;
                    indiceAuxParaNoUtilizados++;
                }
            }

            //Empezamos la llamada recursiva para el lateral:
            numParesRestantesLateralRecursivo = primoRecursivo.numPares - ordenEstaAnidacion;
            numCombinacionesLateralesRecursivo = ordenEstaAnidacion-2;
            combinacionesRecursivaLateral(0,0);

        }
    }
}


////Procesa todas las posibles combinaciones de pares (con filas) para colocar la fila superior.
void procesarCombinacionesRecursiva(int profundidad){
    if(profundidad == ordenEstaAnidacion){
        if (comprobarFilaCandidata()) {
            procesarLaterales();
        }
    }
    else{
        for (int i = 0; i < 2; ++i) {
            indicesFilaRecursivo[profundidad] = i;
            procesarCombinacionesRecursiva(profundidad+1);
        }
    }
}


//Procesa las combinaciones para poder encontrar un cuadrado mágico.
//Primero coloca la fila superior
//Después intenta colocar el lateral
//Si ha sido capaz, vuelve a procesar otra anidación.
void procesarCombinaciones(int numeroIndice, int porCualAndo){
    if(numeroIndice == ordenEstaAnidacion) {  // Hemos seleccionado el último índice.
        procesarCombinacionesRecursiva(0);
    }else{
        for (int i = porCualAndo; i <= primoRecursivo.numPares-(ordenEstaAnidacion - numeroIndice) ; ++i) {
            indicesRecursivo[numeroIndice]=i;
            procesarCombinaciones(numeroIndice+1,i+1);
        }
    }
}


int main() {

    const rlim_t kStackSize = 128L * 1024L * 1024L;   // min stack size = 64 Mb
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }

    struct rlimit limit;

    getrlimit (RLIMIT_STACK, &limit);
    printf ("\nStack Limit = %llu and %llu max\n", limit.rlim_cur, limit.rlim_max);

    printf("Let's test!\n");




    //INICIALIZACIÓN:
    printf("Generación de un cuadrado de %dx%d\n",ordenNuevo,ordenNuevo);
    printf("Buscando primos con pares mayores que %llu:\n",paresNecesarios);

    rellenarCandidatos();
    pintarCandidatos();






    int indiceCandidato = 0;//160;
    printf("El primer candidato es %llu con %llu pares\n", primosCandidatos[indiceCandidato].primo, primosCandidatos[indiceCandidato].numPares);
    printf("Pintando las posibles combinaciones de parejas teniendo en cuenta el orden del cuadrado...\n");



    //Preparamos la recursividad:
    primoRecursivo = primosCandidatos[indiceCandidato];
    ordenEstaAnidacion = ordenNuevo;
    inicializarMemoria();
    reservarMemoriaSolucion();
    solucion[(ordenNuevo/2)][(ordenNuevo/2)] = primoRecursivo.primo;

    procesarCombinaciones(0,0);



    //FINALIZACIÓN
    destruirMemoria();
    liberarMemoriaSolucion();

    return 0;
}