#include "trabalho1.h"

int busca_reg(char*campo, char*elemento, FILE*arq_bin, int RRN, registro_dados * dado){
    
    if(le_reg_bin(dado,RRN,arq_bin)){
        return 1; //Fim do arquivo
    }

    if(!strcmp(campo,"estadoOrigem")){
        if(!strcmp(elemento,dado->estadoOrigem)){
            return 0;
        }
    }

    if(!strcmp(campo,"estadoDestino")){
        if(!strcmp(elemento,dado->estadoDestino)){
            return 0;
        }
    }

    if(!strcmp(campo,"cidadeOrigem")){
        if(!strcmp(elemento,dado->cidadeOrigem)){
            return 0;
        }
    }

    if(!strcmp(campo,"cidadeDestino")){
        if(!strcmp(elemento,dado->cidadeDestino)){
            return 0;
        }
    }

    if(!strcmp(campo,"distancia")){
        int num = atoi(elemento);
        if(num == dado->distancia){
            return 0;
        }
    }

    if(!strcmp(campo,"tempoViagem")){
        if(!strcmp(elemento,dado->tempoViagem)){
            return 0;
        }
    }

    return 2;

}

    