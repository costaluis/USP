#include "trabalho1.h"

//Função 5 - Realiza a remoção lógica de um registro, a partir de um campo e um valor especificados

void func5(FILE * arq_bin, char * campo, char * valor, cidade *city){  
    int i=0;
    int c, e;
    int s = 0;
    int vertices, arestas;
    char simbol = '*';
    registro_dados * dado = (registro_dados*) malloc(sizeof(registro_dados));

    fseek(arq_bin,1,SEEK_SET);
    fread(&vertices,4,1,arq_bin);   //Armazena o nº de vértices
    fread(&arestas,4,1,arq_bin);    //Armazena o nº de arestas
    while(1){
        c = busca_reg(campo,valor,arq_bin,i,dado);  //Realiza a busca do registro
        if(c==1){   //Fim do arquivo
            break;
        }
        if(c==0){   //Registro encontrado
            fseek(arq_bin,19+85*i,SEEK_SET);
            
            fwrite(&simbol,1,1,arq_bin);    
            e = busca_binaria(city,vertices,dado->cidadeOrigem);    //Trata da cidadeOrigem no vetor de cidades
            if(e != -1){
                city[e].repeticoes--;
                if(city[e].repeticoes == 0){
                    remove_cidade(city,vertices,e);
                    vertices--;
                }
            }
            e = busca_binaria(city,vertices,dado->cidadeDestino);   //Trata da cidadeDestino no vetor de cidades
            if(e != -1){
                city[e].repeticoes--;
                if(city[e].repeticoes == 0){
                    remove_cidade(city,vertices,e);
                    vertices--;
                }
            }
            arestas--;
        }
        i++;
    }
    fseek(arq_bin,1,SEEK_SET);
    fwrite(&vertices,4,1,arq_bin);  //Escrever o novo nº de vértices
    fwrite(&arestas,4,1,arq_bin);   //Escrever o novo nº de arestas
    
    return;
}