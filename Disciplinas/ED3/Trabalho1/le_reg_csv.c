#include "trabalho1.h"

//Lê um registro do arquivo CSV

int le_reg_csv(FILE * arq_csv, registro_dados * dado){
    char tmp;
    char num[5];
    int i;

    if(!fread(dado->estadoOrigem,2,1,arq_csv)){            //Se a leitura falhar, então chegou ao fim do arquivo
        return 1;
    }
    dado->estadoOrigem[2] = '\0';
    fread(&tmp,1,1,arq_csv);
    fread(dado->estadoDestino,2,1,arq_csv);
    dado->estadoDestino[2] = '\0';                          //Armazena os valores dos campos na struct registro_dados
    fread(&tmp,1,1,arq_csv);
    
    fread(&tmp,1,1,arq_csv);
    for(i=0; tmp != ','; i++){
        num[i] = tmp;
        fread(&tmp,1,1,arq_csv);
    }
    num[i] = '\0';

    dado->distancia = atoi(num);

    fread(&tmp,1,1,arq_csv);
    for(i=0; tmp != ','; i++){
        (dado->cidadeOrigem)[i] = tmp;
        fread(&tmp,1,1,arq_csv);
    }
    (dado->cidadeOrigem)[i] = '\0';

    fread(&tmp,1,1,arq_csv);

    for(i=0; tmp != ','; i++){
        (dado->cidadeDestino)[i] = tmp;
        fread(&tmp,1,1,arq_csv);
    }
    (dado->cidadeDestino)[i] = '\0';

    fread(&tmp,1,1,arq_csv);
    for(i=0; tmp!= '\n'; i++){
        (dado->tempoViagem)[i] = tmp;
        fread(&tmp,1,1,arq_csv);
    }
    (dado->tempoViagem) [i] = '\0';

    return 0;                                          //Retorna 0 se a leitura foi bem sucedida
}