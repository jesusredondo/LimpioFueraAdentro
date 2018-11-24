//
// Created by jesus on 5/11/18.
//

#include <stdlib.h>
#include "cargaguarda.h"

#include "globales.h"

//Método para rellenar los candidatos.
//Recorre el fichero de primos con pares y nos devuelve los RANGO_CANDIDATOS primeros.
void rellenarCandidatos(){

    primosCandidatos = malloc(sizeof(PrimoConPares)*RANGO_CANDIDATOS);


    char nombreDeFichero[200];
    snprintf(nombreDeFichero, sizeof(nombreDeFichero), "%s%llu%s", FICHERO_PARES, RANGO_CRIBA,".dat" );

    FILE * f = fopen(nombreDeFichero,"rb");
    fread(&numPrimos,tamanioBigInt,1,f);


    BigInt primoAux;
    BigInt numParesAux;
    for (BigInt i = 0; i <numPrimos ; ++i) {
        fread(&primoAux,tamanioBigInt,1,f);
        fread(&numParesAux,tamanioBigInt,1,f);


        if(numParesAux >= paresNecesarios){

            //Guardamos este candidato.
            primosCandidatos[numPrimosCandidatos].primo = primoAux;
            primosCandidatos[numPrimosCandidatos].numPares = numParesAux;
            //Guardamos sus pares
            primosCandidatos[numPrimosCandidatos].pares = malloc(sizeof( BigInt *) * 2); //Guardamos dos huecos para cada parte del par.
            primosCandidatos[numPrimosCandidatos].pares[0] = malloc(tamanioBigInt * numParesAux);
            primosCandidatos[numPrimosCandidatos].pares[1] = malloc(tamanioBigInt * numParesAux);
            for (BigInt j = 0; j < numParesAux; ++j) {
                BigInt menorPar;
                BigInt mayorPar;
                //fread(&(menorPar),tamanioBigInt,1,f);
                //fread(&(mayorPar),tamanioBigInt,1,f);

                fread(&(primosCandidatos[numPrimosCandidatos].pares[0][j]),tamanioBigInt,1,f);
                fread(&(primosCandidatos[numPrimosCandidatos].pares[1][j]),tamanioBigInt,1,f);

            }

            numPrimosCandidatos++;
        }else{ //Saltar pares:
            fseek(f,(tamanioBigInt*2*numParesAux),SEEK_CUR);

        }
        if (numPrimosCandidatos == RANGO_CANDIDATOS){ //Si ya hemos encontrados los suficientes, paramos.
            break;
        }
    }

    fclose(f);
}


//Pinta los candidatos encontrados:
void pintarCandidatos(){
    printf("CANDIDATOS: \n");
    for (BigInt i = 0; i < numPrimosCandidatos ; ++i) {
        printf("%llu: %llu - %llu pares --> ",i, primosCandidatos[i].primo,primosCandidatos[i].numPares);
        for (int j = 0; j < primosCandidatos[i].numPares; ++j) {
            printf("(%llu,%llu) - ", primosCandidatos[i].pares[0][j], primosCandidatos[i].pares[1][j]);
        }
        printf("\n");
    }
}



