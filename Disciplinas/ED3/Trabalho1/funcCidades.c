#include "trabalho1.h"

cidade * cria_tabela(FILE *arq_bin){
    char status;

    fseek(arq_bin,0,SEEK_SET);
    fread(&status,1,1,arq_bin);

    if(status == '0'){
        printf("Falha no processamento do arquivo.\n");
        return NULL;
    }


    int c, m;
    int tam = 0;
    cidade *city = (cidade*)malloc(MAX_ARQ*sizeof(cidade));
    registro_dados *dados = (registro_dados*)malloc(sizeof(registro_dados));
    
    for(int i=0;;i++){
        c = func4(dados,i,arq_bin);
        if(c == 1){
            break;
        }
        if(c == 0){
            m = busca_binaria(city,tam,dados->cidadeOrigem);
            if(m == -1){
                insere_ordenado(city,dados->cidadeOrigem,tam);
                tam++;
            }else{
                city[m].repeticoes++;
            }

            m = busca_binaria(city,tam,dados->cidadeDestino);
            if(m == -1){
                insere_ordenado(city,dados->cidadeDestino,tam);
                tam++;
            }else{
                city[m].repeticoes++;
            }
        }
    }
    free(dados);
    return city;
}