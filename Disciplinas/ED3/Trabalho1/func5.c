#include "trabalho1.h"

void func5(FILE * arq_bin, char * campo, char * valor, cidade *city){  
    int i=0;
    int c, e;
    int s = 0;
    int vertices, arestas;
    char simbol = '*';
    registro_dados * dado = (registro_dados*) malloc(sizeof(registro_dados));

    fseek(arq_bin,1,SEEK_SET);
    fread(&vertices,4,1,arq_bin);
    fread(&arestas,4,1,arq_bin);
    while(1){
        c = busca_reg(campo,valor,arq_bin,i,dado);
        if(c==1){
            break;
        }
        if(c==0){
            fseek(arq_bin,19+85*i,SEEK_SET);
            
            fwrite(&simbol,1,1,arq_bin);
            e = busca_binaria(city,vertices,dado->cidadeOrigem);
            if(e != -1){
                city[e].repeticoes--;
                if(city[e].repeticoes == 0){
                    remove_cidade(city,vertices,e);
                    vertices--;
                }
            }
            e = busca_binaria(city,vertices,dado->cidadeDestino);
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
    fwrite(&vertices,4,1,arq_bin);
    fwrite(&arestas,4,1,arq_bin);
    
    return;
}