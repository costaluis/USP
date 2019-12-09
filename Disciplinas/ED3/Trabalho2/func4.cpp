#include "trabalho2.hpp"

//Função 4 - Busca por RRN

int func4(registro_dados * dado, int RRN, FILE * arq_bin){
    char status;

    fseek(arq_bin,0,SEEK_SET);
    fread(&status,1,1,arq_bin);
    
    char * tmp = (char*) malloc(sizeof(char));
    int i;
    
    if(fseek(arq_bin,(RRN * 85) +19, SEEK_SET)){    //Testa existência do RRN
        free(tmp);
        return 1;
    }

    if(!fread(dado->estadoOrigem,2,1,arq_bin)){     //Testa fim do arquivo
        free(tmp);
        return 1;
    }
    dado->estadoOrigem[2] = '\0';

    if(dado->estadoOrigem[0]=='*'){     //Testa se o registro está removido
        free(tmp);
        return 2;
    }
    
    fread(dado->estadoDestino,2,1,arq_bin);
    dado->estadoDestino[2] = '\0';

    fread(&(dado->distancia),4,1,arq_bin);

    //Le registro de tamanho variável
    fread(tmp,1,1,arq_bin);     
    for(i=0; *tmp != '|'; i++){
        (dado->cidadeOrigem)[i] = *tmp;     //cidadeOrigem
        fread(tmp,1,1,arq_bin);
    }
    (dado->cidadeOrigem)[i] = '\0';

    fread(tmp,1,1,arq_bin);
    for(i=0; *tmp != '|'; i++){
        (dado->cidadeDestino)[i] = *tmp;    //cidadeDestino
        fread(tmp,1,1,arq_bin);
    }
    (dado->cidadeDestino)[i] = '\0';

    fread(tmp,1,1,arq_bin);
    for(i=0; *tmp != '|'; i++){
        (dado->tempoViagem)[i] = *tmp;      //tempoViagem
        fread(tmp,1,1,arq_bin);
    }
    (dado->tempoViagem)[i] = '\0';

    free(tmp);
    return 0;
    
}   