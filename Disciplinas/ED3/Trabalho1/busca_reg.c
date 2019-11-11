#include "trabalho1.h"

//Busca um registro a partir de um valor de um campo especificado e de um RRN
int busca_reg(char*campo, char*valor, FILE*arq_bin, int RRN, registro_dados * dado){
    int c = func4(dado,RRN,arq_bin);	//chama a func4 para a recuperação de um registro

    if(c==1){	//Fim do arquivo
        return 1; 
    }

    if(c==2){	//Registro removido
        return 3;
    }

    //Identificação do campo
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

    return 2;	//Retorno se não atende ao critério buscado

}

    