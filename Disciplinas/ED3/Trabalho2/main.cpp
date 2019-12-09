/*
Trabalho 2 - Estrutura de Dados III
Prof Dra. Cristina Dutra de Aguiar Ciferri
Alunos:
    João Pedro Fidelis Belluzzo         NºUSP: 10716661
    Luis Fernando Costa de Oliveira     NºUSP: 10716532
*/

#include "trabalho2.hpp"

int main(){     //Main Function
    int op;
    cin >> op;                  //Recebe o código referente à função a ser executada

    switch(op){
        case 9:{                //Caso 09 - Criação do grafo (Lista de Adjacências)
            char arq_bin[90];
            cin >> arq_bin;
            FILE * fp = fopen(arq_bin,"rb");            //Abre arquivo de dados para leitura
            if (fp==NULL){
                cout << "Falha no carregamento do arquivo.";        //Verificação da abertura
                return 0;
            }

            map<string,lista_ad*> hash = func9(fp);             //Cria hash correspondente à lista de adjacências

            if(!hash.size()){                       //Caso a hash esteja vazia temos que o arquivo de dados estava com status inválido
                fclose(fp);                         //Fecha o arquivo e encerra o processo
                fp = NULL;      
                return 0;
            }

            print_hash(hash);                   //Caso tudo esteja OK, imprime o grafo

            fclose(fp);                         //Fecha o arquivo de dados e libera os dados alocados pelo grafo.                                       
            freeMem(hash);

            break;
        }
        case 10:{                               //Caso 10 - Algoritmo de Dijkstra
            char arq_bin[90];
            cin >> arq_bin;
            FILE * fp = fopen(arq_bin,"rb");                //Abre arquivo de dados para leitura
            if (fp==NULL){
                cout << "Falha no carregamento do arquivo.";            //Verifica abertura do arquivo de dados
                return 0;
            }
            char campo[90];
            cin >> campo;
            char valor[90];
            scan_quote_string(valor);               //Recebe o nome do vértice inicial, sendo as distâncias calculadas a partir dele

            map<string,lista_ad*> hash = func9(fp);        //Cria lista de adjacências referente ao grafo

            if(!hash.size()){                          //Caso a hash esteja vazia temos que o arquivo de dados estava com status inválido
                fclose(fp);                             //Fecha o arquivo e encerra o processo
                return 0;
            }

            map<city,int> dist;
            map<city,city> ant;                         //Criação das hashs referentes ao vetor de antecessores e de distancias
            func10(hash,&dist,&ant,valor);                      //Chama da função responsável pelo algoritmo Dijkstra 

            freeMem(hash);                              //Libera dados alocados e fecha arquivo de dados
            fclose(fp);

            break;
        }
        case 11:{                                   //Caso 11 - Algoritmo de Prim (Árvore geradora mínima)
            char arq_bin[90];
            cin >> arq_bin;
            FILE * fp = fopen(arq_bin,"rb");            //Abre arquivo de dados para leitura
            if(fp == NULL){
                cout << "Falha no carregamento do arquivo.";        //Verifica abertura do arquivo de dados
                return 0;
            }

            map<string,lista_ad*> hash = func9(fp);                 //Cria hash referente à lista de adjacências

            if(!hash.size()){                               //Caso a hash esteja vazia temos que o arquivo de dados estava com status inválido
                fclose(fp);                                   //Fecha o arquivo e encerra o processo
                return 0;
            }

            string campo;
            char ValorCampo[90];
            cin >> campo;
            scan_quote_string(ValorCampo);                    //Recebe vértice inicial do algoritmo

            func11(hash,ValorCampo);                    //Chama função responsável pelo algoritmo de Prim

            fclose(fp);                             //Fecha arquivo de dados e libera dados alocados
            freeMem(hash);

            break;
        }
        default:{                                           //Caso Default
            cout << "Comando desconhecido.";        
            break;                                      //Método não existente
        }
        return 0;

    }
}