#include "trabalho1.h"

int busca_binaria(char ** cidades, int tamanho, char * item){
    int inicio = 0;
    int fim = tamanho-1;
    int meio;

    if(tamanho == 0){
        return -1;
    }

    while(inicio<=fim){
        meio = (fim+inicio)/2;

        if(!strcmp(cidades[meio],item)){
            return 0;
        }
        if(strcmp(cidades[meio],item)<0){
            inicio = meio+1;
        }
        else{
            fim = meio-1;
        }
    }
    
    return -1;
}

void insere_ordenado(char ** cidades, char * new_city, int tamanho){
    char * aux = (char *) malloc(tam_cidade_max * sizeof(char));
    char * aux2 = (char*) malloc(tam_cidade_max * sizeof(char));
    int i;

    if(tamanho==0){
        strcpy(cidades[0],new_city);
        return;
    }

    for(i=0; strcmp(new_city,cidades[i])>0 && i<tamanho;i++){
    }

    if(i==tamanho){
        strcpy(cidades[i],new_city);
        return;
    }

    while(i!=tamanho){
        strcpy(cidades[tamanho],cidades[tamanho-1]);
        tamanho--;
    }
    strcpy(cidades[i],new_city);

    free(aux);
}