#include "trabalho1.h"

//Função 3 - Busca a partir de um campo e um valor especificados

void func3(char*campo, char*valor, FILE*arq_bin){
    registro_dados * dado = (registro_dados*) malloc(sizeof(registro_dados));
    int c;
    char status;

    fseek(arq_bin,0,SEEK_SET);
    fread(&status,1,1,arq_bin);

    for(int i=0;;i++){
        c = busca_reg(campo,valor,arq_bin,i,dado);  //Busca registro no arquivo
        if(c==1){   //Fim do arquivo
            break;
        }
        if(c==0){   //Registro encontrado
            print_reg(i,dado);
        }
    }

    free(dado);
}