#include "trabalho1.h"

//Cria vetor de cidades

cidade * cria_tabela(FILE *arq_bin){
    char status;

    fseek(arq_bin,0,SEEK_SET);
    fread(&status,1,1,arq_bin);

    int c, m;
    int tam = 0;
    cidade *city = (cidade*)malloc(MAX_ARQ*sizeof(cidade));
    registro_dados *dados = (registro_dados*)malloc(sizeof(registro_dados));
    
    for(int i=0;;i++){
        c = func4(dados,i,arq_bin); //Leitura de registros por RRN
        if(c == 1){ //Fim do arquivo
            break;
        }
        if(c == 0){ //Registro válido
            m = busca_binaria(city,tam,dados->cidadeOrigem); //Verifica se cidadeOrigem está no vetor
            if(m == -1){ //Cidade não encontrada
                insere_ordenado(city,dados->cidadeOrigem,tam);
                tam++;
            }else{
                city[m].repeticoes++;
            }

            m = busca_binaria(city,tam,dados->cidadeDestino); //Verifica se cidadeDestino está no vetor
            if(m == -1){ //Cidade não encontrada
                insere_ordenado(city,dados->cidadeDestino,tam);
                tam++;
            }else{
                city[m].repeticoes++;
            }
        }
    }
    return city; //Retorna o vetor
}