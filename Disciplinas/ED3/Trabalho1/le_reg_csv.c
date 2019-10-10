#include "trabalho1.h"

int le_reg_csv(FILE * arq_csv, registro_dados * dado){
    registro_dados temp;
    fscanf(arq_csv, "%[^,],%[^,],%d,%[^,],%[^,],", temp.estadoOrigem,temp.estadoDestino,temp.distancia,temp.cidadeOrigem,temp.cidadeDestino);
    fscanf(arq_csv, "%[^\n]", temp.tempoViagem);
    
}