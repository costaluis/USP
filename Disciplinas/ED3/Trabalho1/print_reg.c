#include "trabalho1.h"

//Imprime o registro localizado no RRN dado.

void print_reg(int RRN, registro_dados *aux){
    printf("%d %s %s %d %s %s",RRN,aux->estadoOrigem,aux->estadoDestino,aux->distancia,aux->cidadeOrigem,aux->cidadeDestino);
    if(aux->tempoViagem[0]=='\0'){
        printf("\n");
    }else{
        printf(" %s\n",aux->tempoViagem);
    }
}