#include <stdio.h>
#include <stdlib.h>

typedef struct registro_cabecalho{
    char status;
    int numeroVertices;
    int numeroArestas;
    char dataUltimaCompactacao[10];
}registro_cabecalho;

typedef struct registro_dados{
    char estadoOrigem[2];
    char estadoDestino[2];
    int distancia;
    char * cidadeOrigem;
    char * cidadeDestino;
    char * tempoViagem;
}