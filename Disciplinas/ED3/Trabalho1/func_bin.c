#include "trabalho1.h"

//Funções para a manipulação do vetor de cidades

//Realiza a busca binária no vetor
int busca_binaria(cidade * cidades, int tamanho, char * item){
    int inicio = 0;
    int fim = tamanho-1;
    int meio;

    if(tamanho == 0){
        return -1;
    }

    while(inicio<=fim){
        meio = (fim+inicio)/2;

        if(!strcmp((cidades[meio]).nome,item)){
            return meio;
        }
        if(strcmp((cidades[meio]).nome,item)<0){
            inicio = meio+1;
        }
        else{
            fim = meio-1;
        }
    }
    
    return -1;
}

//Realiza a inserção ou o incremento do número de repetições no vetor de cidades
void insere_ordenado(cidade * cidades, char * new_city, int tamanho){
    cidade * aux = (cidade *) malloc(tam_cidade_max * sizeof(cidade));
    int i;

    if(tamanho==0){
        strcpy(cidades[0].nome,new_city);
        cidades[0].repeticoes = 1;
        return;
    }

    for(i=0; strcmp(new_city,cidades[i].nome)>0 && i<tamanho;i++){
    }

    if(i==tamanho){
        strcpy(cidades[i].nome,new_city);
        cidades[i].repeticoes = 1;
        return;
    }

    while(i!=tamanho){
        cidades[tamanho] = cidades[tamanho-1];
        tamanho--;
    }
    strcpy(cidades[i].nome,new_city);
    cidades[i].repeticoes = 1;

    free(aux);
}

//Realiza a remoção de uma cidade, shiftando os elementos seguintes
void remove_cidade(cidade *city, int vertices, int pos){
    for(int i=pos;i<vertices;i++){
        city[i] = city[i+1];
    }
    return;
}