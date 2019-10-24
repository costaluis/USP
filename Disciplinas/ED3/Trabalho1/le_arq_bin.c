#include "trabalho1.h"

void le_arq_bin(FILE * arq_bin){
    registro_dados * aux = (registro_dados*) malloc(sizeof(registro_dados));

    for(int i=0;!le_reg_bin(aux, i, arq_bin); i++){
        printf("%d %c%c %c%c %d %s %s",i,aux->estadoOrigem[0],aux->estadoOrigem[1],aux->estadoDestino[0],aux->estadoDestino[1],aux->distancia,aux->cidadeOrigem,aux->cidadeDestino);
        if(aux->tempoViagem[0]=='\0'){
            printf("\n");
        }else{
            printf(" %s\n",aux->tempoViagem);
        }
    }
}