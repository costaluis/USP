#include "trabalho1.h"

void func1(FILE * arq_csv, FILE * arq_bin){
    registro_dados * tmp = (registro_dados *) malloc(sizeof(registro_dados));
    registro_dados * cab = (registro_cabecalho *) calloc(1,sizeof(registro_cabecalho));
    int i;
    char pipe = '|';
    char lixo = '#';

    fseek(arq_csv,77,SEEK_SET);
    
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
    }
    fseek(arq_bin,1,SEEK_SET);
    fwrite(&(cab->numeroVertices),4,1,arq_bin);
    fwrite(&(cab->numeroArestas),4,1,arq_bin);
    fwrite(cab->dataUltimaCompactacao,10,1,arq_bin);


    free(tmp);
}