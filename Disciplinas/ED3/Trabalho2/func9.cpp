#include "trabalho2.hpp"

map<string,lista_ad*> func9(FILE * arq_bin){            //Algoritmo de Dijkstra
    map<string,lista_ad*> hash;
    char status;
    fseek(arq_bin,0,SEEK_SET);
    fread(&status,1,1,arq_bin);
    if(status == '0'){                                      //Testa o status do arquivo de dados
        cout << "Falha no carregamento do arquivo.";        //Caso inválido, encerra o método e retorna uma hash vazia
        return hash;
    }
    map<string,lista_ad*>::iterator itera;
    registro_dados * dado = (registro_dados*) malloc(sizeof(registro_dados));
    lista_ad * aux;
    int RRN = 0;
    int c;

    while(c=func4(dado, RRN, arq_bin)!=1){              //func4 - Função responsável por ler um registro do arquivo de dados
        if(c==2){
            RRN++;                                      //Caso o retorno de func4==2 -> registro removido
            continue;
        }
        if(!hash.count(dado->cidadeOrigem)){            //Verifica se o vértice já existe na lista de adjacências
            lista_ad * no = new lista_ad();
            no->estado = dado->estadoOrigem;            //Caso não, insere o novo vértice na hash referente à lista
            no->cidade = dado->cidadeOrigem;
            no->peso = -1;
            no->temp_viagem = "";
            no->next = new lista_ad();
            aux = no->next;
            
            aux->cidade = dado->cidadeDestino;
            aux->estado = dado->estadoDestino;
            aux->peso = dado->distancia;
            aux->temp_viagem = dado->tempoViagem;
            aux->next = NULL;
            
            hash.insert(pair<string,lista_ad*>(dado->cidadeOrigem,no));
        }else{                                                              //Caso o vértice já esteja na lista
            itera = hash.find(dado->cidadeOrigem);                          // o vértice adjacente é inserido em ordem alfabética
            aux = itera->second;
            while(aux->next != NULL && aux->next->cidade < dado->cidadeDestino){
                aux = aux->next;
            }
            if(aux->next == NULL){
                aux->next = new lista_ad();
                aux = aux->next;
                aux->cidade = dado->cidadeDestino;
                aux->estado = dado->estadoDestino;
                aux->temp_viagem = dado->tempoViagem;
                aux->peso = dado->distancia;
                aux->next = NULL;
            }else{
                lista_ad * temp = aux->next;
                aux->next = new lista_ad();
                aux = aux->next;
                aux->cidade = dado->cidadeDestino;
                aux->peso = dado->distancia;
                aux->temp_viagem = dado->tempoViagem;
                aux->estado = dado->estadoDestino;
                aux->next = temp;
            }
        }
        if(!hash.count(dado->cidadeDestino)){           //Passo de inserção é repetido para o vértice da cidade destino
            lista_ad * no = new lista_ad();             //isto porque o grafo é não direcionado
            no->estado = dado->estadoDestino;
            no->cidade = dado->cidadeDestino;
            no->peso = -1;
            no->temp_viagem = "";
            no->next = new lista_ad();
            aux = no->next;
            
            aux->cidade = dado->cidadeOrigem;
            aux->estado = dado->estadoOrigem;
            aux->peso = dado->distancia;
            aux->temp_viagem = dado->tempoViagem;
            aux->next = NULL;
            
            hash.insert(pair<string,lista_ad*>(dado->cidadeDestino,no));
        }else{
            itera = hash.find(dado->cidadeDestino);
            aux = itera->second;
            while(aux->next != NULL && aux->next->cidade < dado->cidadeOrigem){
                aux = aux->next;
            }
            if(aux->next == NULL){
                aux->next = new lista_ad();
                aux = aux->next;
                aux->cidade = dado->cidadeOrigem;
                aux->peso = dado->distancia;
                aux->estado = dado->estadoOrigem;
                aux->temp_viagem = dado->tempoViagem;
                aux->next = NULL;
            }else{
                lista_ad * temp = aux->next;
                aux->next = new lista_ad();
                aux = aux->next;
                aux->cidade = dado->cidadeOrigem;
                aux->estado = dado->estadoOrigem;
                aux->peso = dado->distancia;
                aux->temp_viagem = dado->tempoViagem;
                aux->next = temp;
            }
        }

        RRN++;
    }
    free(dado);                 //Libera espaço utilizado para armazenar os registros

    return hash;                //Retorna a lista de adjacências criada (estrutura)
}
