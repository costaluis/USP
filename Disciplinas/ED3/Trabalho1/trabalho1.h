#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_cidade_max 90
#define MAX_ARQ 1000

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

int le_reg_csv(FILE *, registro_dados*);
void func1(FILE *, FILE *);
void le_arq_bin(FILE*);
int le_reg_bin(registro_dados*,int, FILE*);
int busca_reg(char*,char*,FILE*,int,registro_dados*);
void print_reg(int,registro_dados*);
void func3(char*,char*,FILE*);
int busca_binaria(char**,int,char*);
void insere_ordenado(char**,char*,int);

#ifndef H_ESCREVERNATELA_
	#define H_ESCREVERNATELA_
	#include <stdio.h>

	void binarioNaTela1(char *nomeArquivoBinario);
	void trim(char *str);
	void scan_quote_string(char *str);
#endif