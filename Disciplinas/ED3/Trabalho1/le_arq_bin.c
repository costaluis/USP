#include "trabalho1.h"

void le_arq_bin(FILE * arq_bin){
    registro_dados * aux = (registro_dados*) malloc(sizeof(registro_dados));
    int c;

    for(int i=0;; i++){
        c = le_reg_bin(aux, i, arq_bin);
        if(c==1){
            break;
        }
        if(c==0){
            print_reg(i,aux);
        }  
    }

    free(aux);
}