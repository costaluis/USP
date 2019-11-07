#include "trabalho1.h"

void func3(char*campo, char*valor, FILE*arq_bin){
    registro_dados * dado = (registro_dados*) malloc(sizeof(registro_dados));
    int c;
    char status;

    fseek(arq_bin,0,SEEK_SET);
    fread(&status,1,1,arq_bin);

    if(status == '0'){
        printf("Falha no processamento do arquivo.\n");
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