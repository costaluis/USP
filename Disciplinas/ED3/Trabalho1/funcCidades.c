#include "trabalho1.h"

cidade * cria_tabela(FILE *arq_bin){
    int c, m;
    int tam = 0;
    cidade *city = (cidade*)malloc(MAX_ARQ*sizeof(cidade));
    registro_dados *dados = (registro_dados*)malloc(sizeof(registro_dados));
    
    for(int i=0;;i++){
        c = le_reg_bin(dados,i,arq_bin);
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
    return city;
}