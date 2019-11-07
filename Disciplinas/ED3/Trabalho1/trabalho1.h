#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam_cidade_max 90
#define MAX_ARQ 1000
#define hashtag '#'

typedef struct registro_cabecalho{
    char status;
    int numeroVertices;
    int numeroArestas;
    char dataUltimaCompactacao[11];
}registro_cabecalho;

typedef struct registro_dados{
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
int busca_reg(char*,char*,FILE*,int,registro_dados*);
void print_reg(int,registro_dados*);
int func1(FILE *, FILE *, cidade*);
void func2(FILE*);
void func3(char*,char*,FILE*);
int func4(registro_dados*,int, FILE*);
void func5(FILE*,char*,char*,cidade*);
void func6(FILE*,registro_dados*);
void func7(FILE *, int , char *, char *,cidade*);
void func8(FILE *, FILE *);
int busca_binaria(cidade*,int,char*);
void insere_ordenado(cidade*,char*,int);
void remove_cidade(cidade*,int,int);
cidade * cria_tabela(FILE*);


#ifndef H_ESCREVERNATELA_
	#define H_ESCREVERNATELA_
	#include <stdio.h>

	void binarioNaTela1(char *nomeArquivoBinario);
	void trim(char *str);
	void scan_quote_string(char *str);
#endif