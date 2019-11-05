#include "trabalho1.h"

void func3(char*campo, char*valor, FILE*arq_bin){
    registro_dados * dado = (registro_dados*) malloc(sizeof(registro_dados));
    int c;

    if(arq_bin==NULL){
        printf("Falha no processamento do arquivo.");
        return;
    }

    for(int i=0;;i++){
        c = busca_reg(campo,valor,arq_bin,i,dado);
        if(c==1){
            break;
        }
        if(c==0){
            print_reg(i,dado);
        }
    }

    free(dado);
}