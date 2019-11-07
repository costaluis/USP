#include "trabalho1.h"

int busca_reg(char*campo, char*valor, FILE*arq_bin, int RRN, registro_dados * dado){
    int c = func4(dado,RRN,arq_bin);

    if(c==1){
        return 1; //Fim do arquivo
    }

    if(c==2){
        return 3;
    }

    if(!strcmp(campo,"estadoOrigem")){
        if(!strcmp(valor,dado->estadoOrigem)){
            return 0;
        }
    }

    if(!strcmp(campo,"estadoDestino")){
        if(!strcmp(valor,dado->estadoDestino)){
            return 0;
        }
    }

    if(!strcmp(campo,"cidadeOrigem")){
        if(!strcmp(valor,dado->cidadeOrigem)){
            return 0;
        }
    }

    if(!strcmp(campo,"cidadeDestino")){
        if(!strcmp(valor,dado->cidadeDestino)){
            return 0;
        }
    }

    if(!strcmp(campo,"distancia")){
        int num = atoi(valor);
        if(num == dado->distancia){
            return 0;
        }
    }

    if(!strcmp(campo,"tempoViagem")){
        if(!strcmp(valor,"NULO")){
            if(!strcmp("",dado->tempoViagem)){
                return 0;
            }
        }
        if(!strcmp(valor,dado->tempoViagem)){
            return 0;
        }
    }

    return 2;

}

    