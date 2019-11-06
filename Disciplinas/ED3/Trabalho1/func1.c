#include "trabalho1.h"

void func1(FILE * arq_csv, FILE * arq_bin){
    registro_dados * tmp = (registro_dados *) malloc(sizeof(registro_dados));
    registro_cabecalho * cab = (registro_cabecalho *) calloc(1,sizeof(registro_cabecalho));
    char ** cidades = (char**) malloc(MAX_ARQ * sizeof(char*));
    int i;
    int tam = 0;
    int pos;
    char pipe = '|';
    char lixo = '#';
    char status = '1';

    for(int j=0;j<MAX_ARQ;j++){
        cidades[j] = (char*) malloc(tam_cidade_max * sizeof(char));
    }

    fseek(arq_csv,76,SEEK_SET);
    fseek(arq_bin,19,SEEK_SET);
    
    while(!le_reg_csv(arq_csv,tmp)){
        int cont = 0;

        fwrite(&(tmp->estadoOrigem[0]),1,1,arq_bin);
        fwrite(&(tmp->estadoOrigem[1]),1,1,arq_bin);

        fwrite(&(tmp->estadoDestino[0]),1,1,arq_bin);  
        fwrite(&(tmp->estadoDestino[1]),1,1,arq_bin);

        fwrite(&(tmp->distancia),4,1,arq_bin);
        cont += 8;

        for(i=0; (tmp->cidadeOrigem)[i] != '\0' && cont < 85; i++){
            fwrite(&((tmp->cidadeOrigem)[i]),1,1,arq_bin);
            cont++;
        }
        if(cont < 85){
            fwrite(&pipe,1,1,arq_bin);
            cont++;
        }

        for(i=0; (tmp->cidadeDestino)[i] != '\0' && cont < 85; i++){
            fwrite(&((tmp->cidadeDestino)[i]),1,1,arq_bin);
            cont++;
        }
        if(cont < 85){
            fwrite(&pipe,1,1,arq_bin);
            cont++;
        }

        for(i=0; (tmp->tempoViagem)[i] != '\0' && cont < 85; i++){
            fwrite(&((tmp->tempoViagem)[i]),1,1,arq_bin);
            cont++;
        }
        if(cont < 85){
            fwrite(&pipe,1,1,arq_bin);
            cont++;
        }
        
        for (; cont < 85; cont++){
            fwrite(&lixo,1,1,arq_bin);
        }
        cab->numeroArestas++;
        pos = busca_binaria(cidades,tam,tmp->cidadeOrigem);
        if(pos != 0){
            insere_ordenado(cidades,tmp->cidadeOrigem,tam);
            tam++;
        }
        pos = busca_binaria(cidades,tam,tmp->cidadeDestino);
        if(pos != 0){
            insere_ordenado(cidades,tmp->cidadeDestino,tam);
            tam++;
        }
    }
    cab->numeroVertices = tam;
    
    fseek(arq_bin,0,SEEK_SET);
    fwrite(&status,1,1,arq_bin);
    fseek(arq_bin,1,SEEK_SET);
    fwrite(&(cab->numeroVertices),4,1,arq_bin);
    fwrite(&(cab->numeroArestas),4,1,arq_bin);
    for(int k=0; k<10; k++){
        fwrite(&lixo,1,1,arq_bin);
    }


    free(tmp);
}