#include "trabalho1.h"

//Função 6 - Inserção de registros

void func6(FILE *arq_bin, registro_dados *tmp){
    
    int cont = 0;   //Contador do número de bytes
    int i;
    char lixo = hashtag;
    char pipe = '|';

    //Escreve campos de tamanho fixo
    fwrite(tmp->estadoOrigem,2,1,arq_bin);
    fwrite(tmp->estadoDestino,2,1,arq_bin);  
    fwrite(&(tmp->distancia),4,1,arq_bin);
    cont += 8;  

    //Escreve campos de tamanho variável
    for(i=0; (tmp->cidadeOrigem)[i] != '\0' && cont < 85; i++){ //cidadeOrigem
        fwrite(&((tmp->cidadeOrigem)[i]),1,1,arq_bin);
        cont++;
    }
    if(cont < 85){  //pipe
        fwrite(&pipe,1,1,arq_bin);
        cont++;
    }

    for(i=0; (tmp->cidadeDestino)[i] != '\0' && cont < 85; i++){ //cidadeDestino
        fwrite(&((tmp->cidadeDestino)[i]),1,1,arq_bin);
        cont++;
    }
    if(cont < 85){  //pipe
        fwrite(&pipe,1,1,arq_bin);
        cont++;
    }
    for(i=0; (tmp->tempoViagem)[i] != '\0' && cont < 85; i++){  //tempoViagem
        fwrite(&((tmp->tempoViagem)[i]),1,1,arq_bin);
        cont++;
    }
    if(cont < 85){  //pipe
        fwrite(&pipe,1,1,arq_bin);
        cont++;
    }
    
    for (; cont < 85; cont++){  //Completa com #
        fwrite(&lixo,1,1,arq_bin);
    }
    
}