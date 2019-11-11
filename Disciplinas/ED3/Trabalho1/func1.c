#include "trabalho1.h"

//Função 1 - CSV para BIN

int func1(FILE * arq_csv, FILE * arq_bin, cidade *city){
   
    registro_dados * tmp = (registro_dados *) malloc(sizeof(registro_dados));
    registro_cabecalho * cab = (registro_cabecalho *) calloc(1,sizeof(registro_cabecalho));
    int i;
    int tam = 0;
    int c;
    char pipe = '|';
    char lixo = '#';
    char status = '1';

    fseek(arq_csv,76,SEEK_SET);   //Pula a linha auxiliar do arquivo csv
    fseek(arq_bin,19,SEEK_SET);   //Pula o cabeçalho no arquivo bin
    
    while(!le_reg_csv(arq_csv,tmp)){
        
        func6(arq_bin,tmp);     //Utiliza a função 6 - inserção de registro no arquivo binário

        cab->numeroArestas++;   //Incrementa o número de arestas
        c = busca_binaria(city,tam,tmp->cidadeOrigem);  //Verifica se a cidadeOrigem já está no vetor de cidades 
        if(c == -1){ //Se não está no vetor...
            insere_ordenado(city,tmp->cidadeOrigem,tam);
            tam++;
        }else{
            city[c].repeticoes++;
        }
        c = busca_binaria(city,tam,tmp->cidadeDestino);  //Verifica se a cidadeDestino já está no vetor de cidades 
        if(c == -1){  ////Se não está no vetor...
            insere_ordenado(city,tmp->cidadeDestino,tam);
            tam++;
        }else{
            city[c].repeticoes++;
        }
    }

    cab->numeroVertices = tam;  //Número de elementos do vetor de cidades
    
    fseek(arq_bin,0,SEEK_SET);
    
    fwrite(&status,1,1,arq_bin);  //Altera o status do arquivo binário
    fseek(arq_bin,1,SEEK_SET);

    fwrite(&(cab->numeroVertices),4,1,arq_bin); //Escreve o cabeçalho
    fwrite(&(cab->numeroArestas),4,1,arq_bin);
    for(int k=0; k<10; k++){    //Completa os bytes restantes do registro com #
        fwrite(&lixo,1,1,arq_bin);
    }


    free(tmp);

    return 0;
}