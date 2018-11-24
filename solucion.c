//
// Created by Jesús Redondo García on 28/10/2018.
//

#include <stdlib.h>
#include "solucion.h"




//Inicializa suficiente memoria para guardar la solución:
void reservarMemoriaSolucion() {
    solucion = (BigInt **) malloc(sizeof(BigInt *)*ordenNuevo); //Guardamos un puntero por cada fila
    for (int i = 0; i < ordenNuevo; ++i) {
        solucion[i] = (BigInt*) malloc(sizeof(BigInt)*ordenNuevo);
        for (int j = 0; j < ordenNuevo; ++j) { //Nos movemos por columnas.
            solucion[i][j] = 0; //Los inicializamos a un valor no posible.
        }
    }
}


//Elimina la memoria reservada para guardar la solución.
void liberarMemoriaSolucion(){
    for (int i = 0; i <ordenNuevo; ++i) {
        free(solucion[i]); //Liberando filas;
    }
    free(solucion); //liberar los punteros a las filas.
}

//Pinta la solución.
void pintarSolucion(){
    for (int i = 0; i < ordenNuevo; ++i) {
        for (int j = 0; j < ordenNuevo; ++j) {
            printf("%10llu\t\t",solucion[i][j]);
        }
        printf("\n");
    }
}


//Comprueba que la solución es correcta:
int comprobarSolucion(){
    BigInt lateralMagico = primoRecursivo.primo*ordenNuevo;
    BigInt aColumna = 0;
    BigInt aFila = 0;
    BigInt aDiagonal = 0;
    BigInt aDiagonal2 = 0;

    for (int i = 0; i < ordenNuevo; ++i) {
        aColumna = 0;
        aFila = 0;
        for (int j = 0; j <ordenNuevo; ++j) {
            aFila += solucion[i][j];
            aColumna += solucion[j][i];
        }
        if((aColumna!= lateralMagico) || (aFila != lateralMagico)){
            return FALSE;
        }
        //Diagonal:
        aDiagonal += solucion[i][i];
        aDiagonal2 += solucion[ordenNuevo-i-1][i];
    }
    return (aDiagonal == lateralMagico) && (aDiagonal2 == lateralMagico);
}

//Guardamos la anidación actual en la solución:
void guardarAnidacion(){
    //Índices:
    int indiceInicial = (ordenNuevo - ordenEstaAnidacion) /2;
    int indiceFinal = indiceInicial + ordenEstaAnidacion - 1;
    printf("Indice Inicial: %i\n",indiceInicial);
    printf("Indice Final: %i\n",indiceFinal);

    //Esquinas:
    solucion[indiceInicial][indiceInicial] = primoRecursivo.primo*2 - derechaAbajoRecursivo; //Sup-izq
    solucion[indiceInicial][indiceFinal] = derechaArribaRecursivo; //Sup-der
    solucion[indiceFinal][indiceInicial] = primoRecursivo.primo*2 - derechaArribaRecursivo; //Abj-izq
    solucion[indiceFinal][indiceFinal] = derechaAbajoRecursivo; //Abj-der


    //Fila superior:
    int indexAux = indiceInicial+1;
    for (int i = 0; i < ordenEstaAnidacion; ++i) {
        BigInt aux = primoRecursivo.pares[indicesFilaRecursivo[i]][indicesRecursivo[i]];
        if ((aux != solucion[indiceInicial][indiceInicial]) && (aux != solucion[indiceInicial][indiceFinal] )){
            solucion[indiceInicial][indexAux] = aux;
            //Fila Inferior:
            solucion[indiceFinal][indexAux] = 2*primoRecursivo.primo - aux;
            indexAux++;
        }
    }

    //Columna Final:
    indexAux = indiceInicial+1;
    for (int j = 0; j < ordenEstaAnidacion-2; ++j) {
        //Lateral derecho
        solucion[indexAux][indiceFinal]= primoRecursivo.pares[indicesFilaLateralRecursivo[j]][indicesLateralRecursivo[j]];
        //Lateral izquierdo
        solucion[indexAux][indiceInicial] = 2*primoRecursivo.primo - primoRecursivo.pares[indicesFilaLateralRecursivo[j]][indicesLateralRecursivo[j]];
        indexAux++;
    }
}