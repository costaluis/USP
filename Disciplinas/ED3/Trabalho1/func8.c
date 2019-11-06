#include "trabalho1.h"

void func8(FILE *bin_in, FILE *bin_out){
    if(bin_in==NULL){
        printf("Falha no processamento do arquivo.");
        return;
    }

    if(bin_out==NULL){
        printf("Falha no processamento do arquivo.");
        return;
    }
    
    char status;
    int c;
    registro_cabecalho * cabecalho = (registro_cabecalho*) malloc(sizeof(registro_cabecalho));
    registro_dados * dado = (registro_dados*) malloc(sizeof(registro_dados));
    fseek(bin_in,0,SEEK_SET);
    fread(&status,1,1,bin_in);
    
    if(status == '0'){
        printf("Falha no carregamento do arquivo.");
        return;
    }

    cabecalho->status = '0';
    fread(&(cabecalho->numeroVertices),4,1,bin_in);
    fread(&(cabecalho->numeroArestas),4,1,bin_in);
    strcpy(cabecalho->dataUltimaCompactacao,"01/11/2019");
    
    fseek(bin_out,0,SEEK_SET);

    fwrite(&(cabecalho->status),1,1,bin_out);
    fwrite(&(cabecalho->numeroVertices),4,1,bin_out);
    fwrite(&(cabecalho->numeroArestas),4,1,bin_out);
    fwrite(cabecalho->dataUltimaCompactacao,10,1,bin_out);

    for(int i=0;;i++){
        c = le_reg_bin(dado,i,bin_in);
        if(c==1){
            break;
        }
        if(c==0){
            func6(bin_out,dado);
        }
    }

    cabecalho->status = '1';
    fseek(bin_out,0,SEEK_SET);
    fwrite(&(cabecalho->status),1,1,bin_out);
    return;
}