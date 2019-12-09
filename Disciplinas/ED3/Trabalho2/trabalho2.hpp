#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <iterator>
#include <map>
#include <functional>
#include <string>
#include <vector>
#define tam_cidade_max 90

using namespace std;

typedef struct registro_dados{
    char estadoOrigem[3];
    char estadoDestino[3];
    int distancia;
    char cidadeOrigem[tam_cidade_max];
    char cidadeDestino[tam_cidade_max];
    char tempoViagem[90];
}registro_dados;

typedef struct lista_ad{
    string cidade;
    string estado;
    string temp_viagem;
    int peso;
    lista_ad * next;
}lista_ad;

typedef struct city{
    string cidade;
    string estado;
    inline const bool operator<(const city &a) const{
        return cidade < a.cidade;
    }
    inline const city operator=(const city &a){
        cidade = a.cidade;
        estado = a.estado;
        return *this;
    }
}city;  


int func4(registro_dados *, int, FILE *);
map<string,lista_ad*> func9(FILE*);
bool isEmpty(city*,int);
void extrai_min(map<city,int>, city *, int, city*);
void print_hash(map<string,lista_ad*>);
int func10(map<string,lista_ad*>, map<city,int> * , map<city,city> * , string);
pair<string,string> extrai_min_prim(map<string,lista_ad*>);
bool IsInU(map<string,lista_ad*>,string);
int CalcPeso(pair<string,string>, map<string,lista_ad*>);
int func11(map<string,lista_ad*>, string);
bool dontFirst(string, map<pair<string,string>,int>);
void freeMem(map<string,lista_ad*>);
void freeLista(lista_ad *);

#ifndef H_ESCREVERNATELA_
	#define H_ESCREVERNATELA_
	#include <stdio.h>

	void binarioNaTela1(char *nomeArquivoBinario);
	void trim(char *str);
	void scan_quote_string(char *str);
#endif