#include "trabalho1.h"

int le_reg_bin(registro_dados * dado, int RRN, FILE * arq_bin){
    char * tmp = malloc(sizeof(char));
    int i;
    
    if(fseek(arq_bin,(RRN * 85) +19, SEEK_SET)){
        free(tmp);
        return 1;
    }

    if(!fread(dado->estadoOrigem,2,1,arq_bin)){
        free(tmp);
        return 1;
    }
    dado->estadoOrigem[2] = '\0';

    if(dado->estadoOrigem[0]=='*'){
        free(tmp);
        return 2;
    }
    
    fread(dado->estadoDestino,2,1,arq_bin);
    dado->estadoDestino[2] = '\0';

    fread(&(dado->distancia),4,1,arq_bin);

    fread(tmp,1,1,arq_bin);
    for(i=0; *tmp != '|'; i++){
        (dado->cidadeOrigem)[i] = *tmp;
        fread(tmp,1,1,arq_bin);
    }
    (dado->cidadeOrigem)[i] = '\0';

    fread(tmp,1,1,arq_bin);
    for(i=0; *tmp != '|'; i++){
        (dado->cidadeDestino)[i] = *tmp;
        fread(tmp,1,1,arq_bin);
    }
    (dado->cidadeDestino)[i] = '\0';

    fread(tmp,1,1,arq_bin);
    for(i=0; *tmp != '|'; i++){
        (dado->tempoViagem)[i] = *tmp;
        fread(tmp,1,1,arq_bin);
    }
    (dado->tempoViagem)[i] = '\0';

    free(tmp);
    return 0;
    
}   