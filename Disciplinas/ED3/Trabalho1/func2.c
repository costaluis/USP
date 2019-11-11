#include "trabalho1.h"

//Função 2 - Lista todos os registros do arquivo

void func2(FILE * arq_bin){
    char status;
    fseek(arq_bin,0,SEEK_SET);
    fread(&status,1,1,arq_bin);
    
    registro_dados * aux = (registro_dados*) malloc(sizeof(registro_dados));
    int c;
    int flag = 1;

    for(int i=0;; i++){
        c = func4(aux, i, arq_bin);  //Chama função 4 - leitura de registro a partir de RRN
        if(c==1){   //Fim do arquivo
            break;
        }
        if(c==0){   //Registro válido
            flag = 0;   //Indica que há registro no arquivo
            print_reg(i,aux);   //Printa o registro
        }  
    }
    if(flag){   //Não houve registros encontrados
        printf("Registro inexistente.\n");
    }

    free(aux);
}