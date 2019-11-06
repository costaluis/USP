#include "trabalho1.h"

void le_arq_bin(FILE * arq_bin){
    if(arq_bin==NULL){
        printf("Falha no processamento do arquivo.");
        return;
    }
    
    registro_dados * aux = (registro_dados*) malloc(sizeof(registro_dados));
    int c;
    int flag = 1;

    for(int i=0;; i++){
        c = le_reg_bin(aux, i, arq_bin);
        if(c==1){
            break;
        }
        if(c==0){
            flag = 0;
            print_reg(i,aux);
        }  
    }
    if(flag){
        printf("Registro inexistente.");
    }

    free(aux);
}