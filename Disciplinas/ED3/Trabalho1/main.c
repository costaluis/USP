/*  
Alunos Resposáveis:

João Pedro Fidelis Belluzzo         10716661
Luis Fernando Costa de Oliveira     10716532
*/

#include "trabalho1.h"

//Função principal do programa

int main(){
    char status_on = '1';
    char status_off = '0';
    char aux;
    int func;
    scanf("%d",&func);                      //Recebe um int referente à função a ser executada     

                                            //Realiza o switch case
    switch(func){                           
        case (1):{
            char bin[50];                   //Caso 1
            char csv[50];
            scanf("%s",csv);                //Recebe nome do arq bin
            scanf("%s",bin);                //Recebe nome do arq csv
            
            cidade *city = (cidade*)malloc(MAX_ARQ*sizeof(cidade));         //Cria um vetor de vértices (cidades)
            FILE *arq_csv = fopen(csv,"rt");                                //Abre o arquivo csv para leitura e o bin para escrita
            FILE *arq_bin = fopen(bin,"w+b");

            if(arq_csv == NULL){                                            
                printf("Falha no carregamento do arquivo.\n");
                free(city);
                if(arq_bin != NULL){
                    fclose(arq_bin);        
                }
                return 0;                                                   //Caso ocorra falha na abertura encerra e imprime mensagem de erro
            }
            if(arq_bin == NULL){
                printf("Falha no carregamento do arquivo.\n");
                free(city);
                if(arq_csv != NULL){
                    fclose(arq_csv);
                    fclose(arq_bin);
                }
                return 0;
            }

            func1(arq_csv,arq_bin,city);                              //Executa função 1

            free(city);
            fclose(arq_bin);                                        //Fecha os arquivos e desaloca a tabela de vértices
            fclose(arq_csv);
            
            binarioNaTela1(bin);                                    //Imprime saida
            break;
        }
        case 2:{                                        //Caso 2
            char bin[50];
            scanf("%s",bin);                        //Recebe nome do arq bin

            
            FILE *arq_bin = fopen(bin,"rb+");                                       //Abre arquivo bin para leitura e escrita
            if(arq_bin == NULL){    
                printf("Falha no processamento do arquivo.\n");                    //Se falhar a abertura encerra o processo e imprime mensagem de erro
                return 0;   
            }

            fseek(arq_bin,0,SEEK_SET);
            fread(&aux,1,1,arq_bin);

            if(aux == '0'){                                             //Verifica o status do arquivo
                printf("Falha no processamento do arquivo.\n");
                fclose(arq_bin);
                return 0;
            }

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_off,1,1,arq_bin);

            func2(arq_bin);                                         //Executa a função 2

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_on,1,1,arq_bin);
            fclose(arq_bin);                                        //Fecha o arquivo binário
            break;
        }
            
        case 3:{                                                //Caso 3
            char bin[50];
            char campo[20];
            char valor[50]; 
            scanf("%s",bin);                                    //Recebe nome do arquivo binário     
            scanf("%s",campo);
            scan_quote_string(valor);                               //Recebe o campo e valor do campo a serem buscados
            
            FILE *arq_bin = fopen(bin,"rb");                        //Abre arquivo binário para leitura
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");         //Caso falhe a abertura encerra o processo e imprime mensagem de erro
                return 0;
            }

            fseek(arq_bin,0,SEEK_SET);
            fread(&aux,1,1,arq_bin);

            if(aux == '0'){                                             //Verifica o status do arquivo
                printf("Falha no processamento do arquivo.\n");
                fclose(arq_bin);
                return 0;
            }

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_off,1,1,arq_bin);

            func3(campo,valor,arq_bin);                                //Executa função 3

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_on,1,1,arq_bin);

            fclose(arq_bin);                                    //Fecha arquivo binário
            break;
        }

        case 4:{                                                                                //Caso 4
            registro_dados *dados = (registro_dados*)malloc(sizeof(registro_dados));
            char bin[50];
            int rrn;
            int c;
            scanf("%s",bin);                                                          //Recebe nome do arquivo binário 
            scanf("%d",&rrn);                                                           //Recebe RRN 
            
            FILE *arq_bin = fopen(bin,"rb");                                    //Abre arquivo binário pra leitura
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");
                free(dados);                                                //Caso falhe abertura encerra processo e imprime mensagem de erro
                return 0;
            }

            if(aux == '0'){                                             //Verifica o status do arquivo
                printf("Falha no processamento do arquivo.\n");
                fclose(arq_bin);
                return 0;
            }

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_off,1,1,arq_bin);

            c = func4(dados,rrn,arq_bin);                           //Chama função 4

            if(!c){
                print_reg(rrn,dados);                               //Caso c==0, função executou corretamente, logo imprime
            }else{
                if(c==1){
                     printf("Registro inexistente.\n");             //Caso c==1, arquivo sem registros
                }
            }
            
            free(dados);    
            
            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_on,1,1,arq_bin);                                 //Desaloca memória de fecha arquivo binário
                                                 
            fclose(arq_bin);
            break;

        }

        case 5:{                                //Caso 5
            char bin[50];
            int n;

            scanf("%s",bin);                        //Recebe nome do arquivo binário    
            scanf("%d",&n);                             //Recebe número de repetições

            FILE *arq_bin = fopen(bin,"rb+");                           //Abre arquivo binário para leitura e escrita
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");         //Caso falhe encerra o programa e retorna mensagem de erro
                return 0;
            }
            
            fseek(arq_bin,0,SEEK_SET);
            fread(&aux,1,1,arq_bin);

            if(aux == '0'){                                             //Verifica o status do arquivo
                printf("Falha no processamento do arquivo.\n");
                fclose(arq_bin);
                return 0;
            }

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_off,1,1,arq_bin);

            char campo[20];
            char valor[50];
            cidade * city = cria_tabela(arq_bin);                   //Aloca vetor de vértices (cidades)
            if(city == NULL){
                fclose(arq_bin);
                return 0;
            }

            for(int i=0; i<n; i++){                                  //Executa a função 5 n vezes
                scanf("%s",campo);
                scan_quote_string(valor);
                func5(arq_bin,campo,valor,city);

            }

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_on,1,1,arq_bin); 

            fclose(arq_bin);
            free(city);                                             //Desaloca memória e fecha arquivo binário

            binarioNaTela1(bin);                                    //Imprime saída

            break;
        }
            
        case 6:{                                    //Caso 6
            char bin[50];
            char s;
            int n, c;
            int vertices, arestas;
            registro_dados *dado =(registro_dados*)malloc(sizeof(registro_dados));              
            cidade *city;

            scanf("%s",bin);                        //Recebe nome do arquivo binário    
            scanf("%d",&n);                         //Recebe numero de repetições

            FILE *arq_bin = fopen(bin,"rb+");                           //Abre arquivo binário para leitura e escrita
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");         //Caso falhe, encerra o processo e imprime mensagem de erro
                free(dado);
                return 0;
            }
            fseek(arq_bin,0,SEEK_SET);                                  //Volta ao primeiro byte do arquivo referente ao status
            fread(&s,1,1,arq_bin);

            if(s == '0'){                                                   //Caso o status seja '0', então retorna mensagem de falha e encerra o processo
                printf("Falha no processamento do arquivo.\n");
                free(dado);
                fclose(arq_bin);
                return 0;
            }

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_off,1,1,arq_bin);

            city = cria_tabela(arq_bin);                                    //Cria tabela de vértices

            fseek(arq_bin,1,SEEK_SET);
            fread(&vertices,4,1,arq_bin);                                   //Obtem o número de vértices e arestas do arquivo binário
            fread(&arestas,4,1,arq_bin);
            
            for(int i=0; i<n; i++){                                         //Executa a função n vezes
                scanf("%s",dado->estadoOrigem);                             //Recebe os dados do registro a ser inserido
                scanf("%s",dado->estadoDestino);
                scanf("%d",&(dado->distancia));
                scan_quote_string(dado->cidadeOrigem);
                scan_quote_string(dado->cidadeDestino);
                scan_quote_string(dado->tempoViagem);

                fseek(arq_bin,0,SEEK_END);                                  //Posiciona o ponteiro de arquivo para o final e insere o novo registro
                func6(arq_bin,dado);

                c = busca_binaria(city,vertices,dado->cidadeOrigem);
                if(c == -1){
                    insere_ordenado(city,dado->cidadeOrigem,vertices);          //Incrementa o número de vértices e arestas
                    vertices++;
                }else{
                    city[c].repeticoes++;
                }
                c = busca_binaria(city,vertices,dado->cidadeDestino);
                if(c == -1){
                    insere_ordenado(city,dado->cidadeDestino,vertices);
                    vertices++;
                }else{
                    city[c].repeticoes++;
                }
                arestas++;
            }

            fseek(arq_bin,1,SEEK_SET);                                      //Reescreve o número de vértices e arestas
            fwrite(&vertices,4,1,arq_bin);
            fwrite(&arestas,4,1,arq_bin);

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_on,1,1,arq_bin); 
            
            free(city);
            free(dado);                                                     //Desaloca memória e fecha arquivo binário
            fclose(arq_bin);

            binarioNaTela1(bin);                                                //Imprime saída
            break;
        }
        case 7:{                                        //Caso 7
            int n;
            char s;
            char bin[50];
            char campo[20];
            char valor[50];
            int RRN;
            scanf("%s",bin);                            //Recebe nome do arquivo binário
            scanf("%d",&n);                                 //Recebe número de repetições
            FILE * arq_bin = fopen(bin,"r+b");
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");                 //Tenta abrir o arquivo binário para leitura e escrita
                return 0;                                                       //Caso falhe encerra o processo e retorna mensagem de erro
            }

            fseek(arq_bin,0,SEEK_SET);
            fread(&s,1,1,arq_bin);

            if(s == '0'){                                                       //Obtém o status do arquivo, caso inválido encerra o processo e imprime mensagem de erro
                printf("Falha no processamento do arquivo.\n");
                fclose(arq_bin);
                return 0;
            }

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_off,1,1,arq_bin);

            cidade * city = cria_tabela(arq_bin);                               //Cria vetor de vértices

            for(int i=0; i<n; i++){                                     //Excuta a função n vezes
                scanf("%d",&RRN);
                scanf("%s",campo);                                      //Informa o RRN, campo e valor a ser atualizado
                scan_quote_string(valor);
                func7(arq_bin,RRN,campo,valor,city);                    //Executa func 7
            }

            fseek(arq_bin,0,SEEK_SET);
            fwrite(&status_on,1,1,arq_bin);

            fclose(arq_bin);
            free(city);                                             //Desaloca memória e fecha arquivo binário
            binarioNaTela1(bin);                                //Imprime saída
            break;
        }
        case 8:{                                        //Caso 8
            char bin_in[50];
            char bin_out[50];   
            scanf("%s",bin_in);                                  //Recebe nome do arquivo de entrada e saída       
            scanf("%s",bin_out);    
            FILE * arq_in = fopen(bin_in,"rb");
            FILE * arq_out = fopen(bin_out,"wb");

            if(arq_in==NULL){                                           //Tenta abrir os arquivos, caso ocorra falha encerra o processo e retorna mensagem de erro
                printf("Falha no carregamento do arquivo.\n");
                if(arq_out!=NULL){
                    fclose(arq_out);
                }
                return 0;
            }

            if(arq_out==NULL){
                printf("Falha no carregamento do arquivo.\n");
                if(arq_in != NULL){
                    fclose(arq_in);
                }
                return 0;
            }
            
            fseek(arq_in,0,SEEK_SET);
            fread(&aux,1,1,arq_in);

            if(aux == '0'){                                                       //Obtém o status do arquivo, caso inválido encerra o processo e imprime mensagem de erro
                printf("Falha no carregamento do arquivo.\n");
                fclose(arq_in);
                fclose(arq_out);
                return 0;
            }

            if(func8(arq_in,arq_out)){                          //Executa função 8 caso o status seja valido
                fclose(arq_in);
                fclose(arq_out);
                return 0;
            }

            fclose(arq_in);                                     //Fecha os arquivos binários
            fclose(arq_out);

            binarioNaTela1(bin_out);                        //Imprime saída

            break;
        }
        default:
            break;
    }
    return 0;                                       //Retorno final caso as funções tenham executado corretamente

}
