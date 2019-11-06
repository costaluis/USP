#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_cidade_max 90
#define MAX_ARQ 1000
#define hashtag '#'

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
    char cidadeOrigem[tam_cidade_max];
    char cidadeDestino[tam_cidade_max];
    char tempoViagem[90];
}registro_dados;

typedef struct cidade{
    char nome[tam_cidade_max];
    int repeticoes;
}cidade;

int le_reg_csv(FILE *, registro_dados*);
void le_arq_bin(FILE*);
int le_reg_bin(registro_dados*,int, FILE*);
int busca_reg(char*,char*,FILE*,int,registro_dados*);
void print_reg(int,registro_dados*);
int func1(FILE *, FILE *, cidade*);
void func3(char*,char*,FILE*);
void func5(FILE*,char*,char*);
void func6(FILE*,registro_dados*);
void func7(FILE *, int , char *, char *);
void func8(FILE *, FILE *);
int busca_binaria(cidade*,int,char*);
void insere_ordenado(cidade*,char*,int);
void remove_cidade(cidade*,int,int);

#ifndef H_ESCREVERNATELA_
	#define H_ESCREVERNATELA_
	#include <stdio.h>

	void binarioNaTela1(char *nomeArquivoBinario);
	void trim(char *str);
	void scan_quote_string(char *str);
#endif