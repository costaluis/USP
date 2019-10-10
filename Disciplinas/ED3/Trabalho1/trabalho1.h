#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE = 0, TRUE} Bool;


typedef struct registro_cabecalho{
    char status;
    int numeroVertices;
    int numeroArestas;
    char dataUltimaCompactacao[11];
}registro_cabecalho;

typedef struct registro_dados{
    Bool removido;
    int rrn;
    char estadoOrigem[3];
    char estadoDestino[3];
    int distancia;
    char cidadeOrigem[90];
    char cidadeDestino[90];
    char tempoViagem[90];
}registro_dados;