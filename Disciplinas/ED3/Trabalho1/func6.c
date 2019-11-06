#include "trabalho1.h"

void func6(FILE *arq_bin, registro_dados *tmp){
    if(arq_bin==NULL){
        printf("Falha no processamento do arquivo.");
        return;
    }
    
    int cont = 0;
    int i;
    char lixo = hashtag;
    char pipe = '|';

    fwrite(tmp->estadoOrigem,2,1,arq_bin);
    fwrite(tmp->estadoDestino,2,1,arq_bin);  
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
    
}