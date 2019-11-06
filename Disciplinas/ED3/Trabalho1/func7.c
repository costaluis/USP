#include "trabalho1.h"

void func7(FILE *arq_bin, int RRN, char *campo, char *valor, cidade *city){
    if(arq_bin==NULL){
        printf("Falha no processamento do arquivo.");
        return;
    }
    
    char c;

    fseek(arq_bin,19+85*RRN,SEEK_SET);
    fread(&c,1,1,arq_bin);
    if(c == '*'){
        return;
    }
    if(!strcmp(campo,"estadoOrigem")){
        fseek(arq_bin,19+85*RRN,SEEK_SET);
        fwrite(valor,2,1,arq_bin);
        return;
    }
    if(!strcmp(campo,"estadoDestino")){
        fseek(arq_bin,19+85*RRN+2,SEEK_SET);
        fwrite(valor,2,1,arq_bin);
        return;
    }
    if(!strcmp(campo,"distancia")){
        int val = atoi(valor);
        fseek(arq_bin,19+85*RRN+4,SEEK_SET);
        fwrite(&val,4,1,arq_bin);
        return;
    }
    if(!strcmp(campo,"cidadeOrigem")){
        int vertices, e;
        registro_dados *dado = (registro_dados *)malloc(sizeof(registro_dados));

        fseek(arq_bin,1,SEEK_SET);
        fread(&vertices,4,1,arq_bin);

        le_reg_bin(dado,RRN,arq_bin);
        
        e = busca_binaria(city,vertices,dado->cidadeOrigem);
        city[e].repeticoes--;
        if(city[e].repeticoes == 0){
            remove_cidade(city,vertices,e);
            vertices--;
        }
        
        e = busca_binaria(city,vertices,valor);
        if(e == -1){
            insere_ordenado(city,valor,vertices);
            vertices++;
        }else{
            city[e].repeticoes++;
        }

        fseek(arq_bin,1,SEEK_SET);
        fwrite(&vertices,4,1,arq_bin);

        strcpy((dado->cidadeOrigem),valor);
        fseek(arq_bin,19+85*RRN,SEEK_SET);
        func6(arq_bin,dado);
        free(dado);
        return;
    }
    if(!strcmp(campo,"cidadeDestino")){
        int vertices, e;
        registro_dados *dado = (registro_dados *)malloc(sizeof(registro_dados));

        fseek(arq_bin,1,SEEK_SET);
        fread(&vertices,4,1,arq_bin);

        le_reg_bin(dado,RRN,arq_bin);
        
        e = busca_binaria(city,vertices,dado->cidadeDestino);
        city[e].repeticoes--;
        if(city[e].repeticoes == 0){
            remove_cidade(city,vertices,e);
            vertices--;
        }
        
        e = busca_binaria(city,vertices,valor);
        if(e == -1){
            insere_ordenado(city,valor,vertices);
            vertices++;
        }else{
            city[e].repeticoes++;
        }
        
        fseek(arq_bin,1,SEEK_SET);
        fwrite(&vertices,4,1,arq_bin);

        strcpy((dado->cidadeDestino),valor);
        fseek(arq_bin,19+85*RRN,SEEK_SET);
        func6(arq_bin,dado);
        free(dado);
        return;
    }
    if(!strcmp(campo,"tempoviagem")){
        registro_dados *dado = (registro_dados *)malloc(sizeof(registro_dados));
        le_reg_bin(dado,RRN,arq_bin);
        if(!strcmp("NULO",valor)){
            dado->tempoViagem[0] = '\0';
        }else{
            strcpy((dado->tempoViagem),valor);
        }
        fseek(arq_bin,19+85*RRN,SEEK_SET);
        func6(arq_bin,dado);
        free(dado);
        return;
    }
}