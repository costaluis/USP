#include "trabalho1.h"

int busca_binaria(char ** cidades, int tamanho, char * item){
    int inicio = 0;
    int fim = tamanho-1;
    int meio;

    if(tamanho == 0){
        return 0;
    }

    while(inicio!=fim){
        meio = (fim+inicio)/2;
        if(!strcmp(cidades[meio],item)){
            return -1;
        }
        if(strcmp(cidades[meio],item)<0){
            inicio = meio+1;
        }
        else{
            fim = meio-1;
        }
    }
    if(strcmp(item,cidades[inicio])>0){
        return inicio+1;
    }else{
        return inicio;
    }
}

void insere_ordenado(char ** cidades, char * new_city, int pos, int tamanho){
    char * aux = (char *) malloc(tam_cidade_max * sizeof(char));

    if(tamanho==0){
        strcpy(cidades[0],new_city);
    }

    while(pos < tamanho){
        strcpy(aux,cidades[pos]);
        strcpy(cidades[pos],new_city);
        strcpy(cidades[pos+1], aux);
        pos++;

    }

    free(aux);
}