#include "trabalho1.h"

//Função 8 - Realiza a compactação do arquivo

int func8(FILE *bin_in, FILE *bin_out){
    char status;
    int c;
    registro_cabecalho * cabecalho = (registro_cabecalho*) malloc(sizeof(registro_cabecalho));
    registro_dados * dado = (registro_dados*) malloc(sizeof(registro_dados));

    cabecalho->status = '0';

    //Le informações do cabeçalho
    fread(&(cabecalho->numeroVertices),4,1,bin_in);
    fread(&(cabecalho->numeroArestas),4,1,bin_in);

    //Nova data de compactação
    strcpy(cabecalho->dataUltimaCompactacao,"01/11/2019");
    
    fseek(bin_out,0,SEEK_SET);

    //Escreve informações no novo arquivo
    fwrite(&(cabecalho->status),1,1,bin_out);
    fwrite(&(cabecalho->numeroVertices),4,1,bin_out);
    fwrite(&(cabecalho->numeroArestas),4,1,bin_out);
    fwrite(cabecalho->dataUltimaCompactacao,10,1,bin_out);

    for(int i=0;;i++){
        c = func4(dado,i,bin_in);   //Le registro por RRN
        if(c==1){   //Fim do arquivo
            break;
        }
        if(c==0){   //Registro válido
            func6(bin_out,dado);    //Insere registro no novo arquivo
        }
    }

    cabecalho->status = '1';
    fseek(bin_out,0,SEEK_SET);
    fwrite(&(cabecalho->status),1,1,bin_out);
    return 0;
} 