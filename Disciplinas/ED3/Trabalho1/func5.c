#include "trabalho1.h"

void func5(FILE * arq_bin, char * campo, char * elemento){
    int i=0;
    int c;
    char simbol = '*';

    if(arq_bin==NULL){
        printf("Falha no processamento do arquivo.");
        return;
    }

    while(1){
        c = busca_reg(campo,elemento,arq_bin,i);
        if(c==1){
            break;
        }
        if(c==0){
            fseek(arq_bin,19+85*i,SEEK_SET);
            fread(&simbol,1,1,arq_bin);
        }
        i++;
    }
}