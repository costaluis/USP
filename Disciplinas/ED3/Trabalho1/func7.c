#include "trabalho1.h"

void func7(FILE *arq_bin, int RRN, char *campo, char *valor, cidade *city){  
    char c;
    char pipe = '|';

    fseek(arq_bin,19+85*RRN,SEEK_SET);
    fread(&c,1,1,arq_bin);
    if(c == '*'){
        return;
    }
    if(!strcmp(campo,"estadoOrigem")){
        if(fseek(arq_bin,19+85*RRN,SEEK_SET)){
            return;
        }
        fwrite(valor,2,1,arq_bin);
        return;
    }
    if(!strcmp(campo,"estadoDestino")){
        if(fseek(arq_bin,19+85*RRN+2,SEEK_SET)){
            return;
        }
        fwrite(valor,2,1,arq_bin);
        return;
    }
    if(!strcmp(campo,"distancia")){
        int val = atoi(valor);
        fseek(arq_bin,19+85*RRN+4,SEEK_SET);
        if(!fread(&c,1,1,arq_bin)){
            printf("Ruim deu %d\n",RRN);
            return;
        }
        fseek(arq_bin,19+85*RRN+4,SEEK_SET);
        
        fwrite(&val,4,1,arq_bin);
        return;
    }
    if(!strcmp(campo,"cidadeOrigem")){
        int vertices, e;
        registro_dados *dado = (registro_dados *)malloc(sizeof(registro_dados));

        fseek(arq_bin,1,SEEK_SET);
        fread(&vertices,4,1,arq_bin);

        if(func4(dado,RRN,arq_bin)){
            return;
        }
        
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
        fseek(arq_bin,19+85*RRN+8,SEEK_SET);
        for(int i=0; i <strlen(dado->cidadeOrigem); i++){
            fwrite(&(dado->cidadeOrigem[i]),1,1,arq_bin);
        }
        fwrite(&pipe,1,1,arq_bin);
        for(int i=0; i <strlen(dado->cidadeDestino); i++){
            fwrite(&(dado->cidadeDestino[i]),1,1,arq_bin);
        }
        fwrite(&pipe,1,1,arq_bin);
        for(int i=0; i <strlen(dado->tempoViagem); i++){
            fwrite(&(dado->tempoViagem[i]),1,1,arq_bin);
        }
        fwrite(&pipe,1,1,arq_bin);

        free(dado);
        return;
    }
    if(!strcmp(campo,"cidadeDestino")){
        int vertices, e;
        char entrada;
        registro_dados *dado = (registro_dados *)malloc(sizeof(registro_dados));

        fseek(arq_bin,1,SEEK_SET);
        fread(&vertices,4,1,arq_bin);

        if(func4(dado,RRN,arq_bin)){
            printf("Deu ruim %d\n",RRN);
            return;
        }
        
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
        fseek(arq_bin,19+85*RRN+9+strlen(dado->cidadeOrigem),SEEK_SET);
        for(int i=0; i <strlen(dado->cidadeDestino); i++){
            fwrite(&(dado->cidadeDestino[i]),1,1,arq_bin);
        }
        fwrite(&pipe,1,1,arq_bin);
        for(int i=0; i <strlen(dado->tempoViagem); i++){
            fwrite(&(dado->tempoViagem[i]),1,1,arq_bin);
        }
        fwrite(&pipe,1,1,arq_bin);
        free(dado);
        return;
    }
    if(!strcmp(campo,"tempoViagem")){
        registro_dados *dado = (registro_dados *)malloc(sizeof(registro_dados));

        if(func4(dado,RRN,arq_bin)){
            return;
        }
        if(!strcmp("",valor)){
            dado->tempoViagem[0] = '\0';
        }else{
            strcpy((dado->tempoViagem),valor);
        }
        fseek(arq_bin,19+85*RRN+10+strlen(dado->cidadeOrigem)+strlen(dado->cidadeDestino),SEEK_SET);
        for(int i=0; i <strlen(dado->tempoViagem); i++){
            fwrite(&(dado->tempoViagem[i]),1,1,arq_bin);
        }
        fwrite(&pipe,1,1,arq_bin);
        free(dado);
        return;
    }
}