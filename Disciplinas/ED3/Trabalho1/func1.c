#include "trabalho1.h"

int func1(FILE * arq_csv, FILE * arq_bin, cidade *city){
   
    registro_dados * tmp = (registro_dados *) malloc(sizeof(registro_dados));
    registro_cabecalho * cab = (registro_cabecalho *) calloc(1,sizeof(registro_cabecalho));
    int i;
    int tam = 0;
    int c;
    char pipe = '|';
    char lixo = '#';
    char status = '1';

    fseek(arq_csv,76,SEEK_SET);
    fseek(arq_bin,19,SEEK_SET);
    
    while(!le_reg_csv(arq_csv,tmp)){
        
        func6(arq_bin,tmp);

        cab->numeroArestas++;
        c = busca_binaria(city,tam,tmp->cidadeOrigem);
        if(c == -1){
            insere_ordenado(city,tmp->cidadeOrigem,tam);
            tam++;
        }else{
            city[c].repeticoes++;
        }
        c = busca_binaria(city,tam,tmp->cidadeDestino);
        if(c == -1){
            insere_ordenado(city,tmp->cidadeDestino,tam);
            tam++;
        }else{
            city[c].repeticoes++;
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
    free(cab);

    return 0;
}