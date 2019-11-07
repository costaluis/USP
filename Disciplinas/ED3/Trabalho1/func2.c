#include "trabalho1.h"

void func2(FILE * arq_bin){
    char status;
    fseek(arq_bin,0,SEEK_SET);
    fread(&status,1,1,arq_bin);
    if(status == '0'){
        printf("Falha no processamento do arquivo.\n");
        return;
    }
    
    registro_dados * aux = (registro_dados*) malloc(sizeof(registro_dados));
    int c;
    int flag = 1;

    for(int i=0;; i++){
        c = func4(aux, i, arq_bin);
        if(c==1){
            break;
        }
        if(c==0){
            flag = 0;
            print_reg(i,aux);
        }  
    }
    if(flag){
        printf("Registro inexistente.\n");
    }

    free(aux);
}