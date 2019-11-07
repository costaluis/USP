#include "trabalho1.h"

int main(){
    int func;
    scanf("%d",&func);
    

    switch(func){
        case (1):{
            char bin[50];   
            char csv[50];
            scanf("%s",csv);
            scanf("%s",bin);
            
            cidade *city = (cidade*)malloc(MAX_ARQ*sizeof(cidade));
            FILE *arq_csv = fopen(csv,"rt");
            FILE *arq_bin = fopen(bin,"w+b");

            if(arq_csv == NULL){
                printf("Falha no carregamento do arquivo.\n");
                free(city);
                if(arq_bin != NULL){
                    fclose(arq_bin);
                }
                return 1;
            }
            if(arq_bin == NULL){
                printf("Falha no carregamento do arquivo.\n");
                free(city);
                if(arq_csv != NULL){
                    fclose(arq_csv);
                }
                return 1;
            }

            func1(arq_csv,arq_bin,city);

            free(city);
            fclose(arq_bin);
            fclose(arq_csv);
            
            binarioNaTela1(bin);
            break;
        }
        case 2:{
            char bin[50];
            scanf("%s",bin);
            
            FILE *arq_bin = fopen(bin,"rb");
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");
                return 1;
            }

            func2(arq_bin);

            fclose(arq_bin);
            break;
        }
            
        case 3:{
            char bin[50];
            char campo[20];
            char valor[50];
            scanf("%s",bin);
            scanf("%s",campo);
            scan_quote_string(valor);
            
            FILE *arq_bin = fopen(bin,"rb");
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");
                return 1;
            }

            func3(campo,valor,arq_bin);

            fclose(arq_bin);
            break;
        }

        case 4:{
            registro_dados *dados = (registro_dados*)malloc(sizeof(registro_dados));
            char bin[50];
            int rrn;
            int c;
            scanf("%s",bin);
            scanf("%d",&rrn);
            
            FILE *arq_bin = fopen(bin,"rb");
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");
                free(dados);
                return 1;
            }

            c = func4(dados,rrn,arq_bin);

            if(!c){
                print_reg(rrn,dados);
            }else{
                if(c==1){
                     printf("Registro inexistente.\n");
                }
            }
            
            free(dados);
            fclose(arq_bin);
            break;

        }

        case 5:{
            char bin[50];
            int n;

            scanf("%s",bin);
            scanf("%d",&n);

            FILE *arq_bin = fopen(bin,"rb+");
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");
                return 1;
            }

            char campo[20];
            char valor[50];
            cidade * city = cria_tabela(arq_bin);
            if(city == NULL){
                fclose(arq_bin);
                return 1;
            }

            for(int i=0; i<n; i++){
                scanf("%s",campo);
                scan_quote_string(valor);
                func5(arq_bin,campo,valor,city);

            }
            fclose(arq_bin);
            free(city);

            binarioNaTela1(bin);

            break;
        }
            
        case 6:{
            char bin[50];
            char s;
            int n, c;
            int vertices, arestas;
            registro_dados *dado =(registro_dados*)malloc(sizeof(registro_dados));
            cidade *city = (cidade*)malloc(MAX_ARQ*sizeof(cidade));

            scanf("%s",bin);
            scanf("%d",&n);

            FILE *arq_bin = fopen(bin,"rb+");
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");
                free(dado);
                free(city);
                return 1;
            }
            fseek(arq_bin,0,SEEK_SET);
            fread(&s,1,1,arq_bin);

            if(s == '0'){
                printf("Falha no processamento do arquivo.\n");
                free(dado);
                free(city);
                fclose(arq_bin);
                return 1;
            }

            city = cria_tabela(arq_bin);

            fseek(arq_bin,1,SEEK_SET);
            fread(&vertices,4,1,arq_bin);
            fread(&arestas,4,1,arq_bin);
            
            for(int i=0; i<n; i++){
                scanf("%s",dado->estadoOrigem);
                scanf("%s",dado->estadoDestino);
                scanf("%d",&(dado->distancia));
                scan_quote_string(dado->cidadeOrigem);
                scan_quote_string(dado->cidadeDestino);
                scan_quote_string(dado->tempoViagem);

                fseek(arq_bin,0,SEEK_END);
                func6(arq_bin,dado);

                c = busca_binaria(city,vertices,dado->cidadeOrigem);
                if(c == -1){
                    insere_ordenado(city,dado->cidadeOrigem,vertices);
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

            fseek(arq_bin,1,SEEK_SET);
            fwrite(&vertices,4,1,arq_bin);
            fwrite(&arestas,4,1,arq_bin);
            
            free(city);
            free(dado);
            fclose(arq_bin);

            binarioNaTela1(bin);
            break;
        }
        case 7:{
            int n;
            char s;
            char bin[50];
            char campo[20];
            char valor[50];
            int RRN;
            scanf("%s",bin);
            scanf("%d",&n);
            FILE * arq_bin = fopen(bin,"r+b");
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.\n");
            }

            fseek(arq_bin,0,SEEK_SET);
            fread(&s,1,1,arq_bin);

            if(s == '0'){
                printf("Falha no processamento do arquivo.\n");
                fclose(arq_bin);
                return 1;
            }

            cidade * city = cria_tabela(arq_bin);

            for(int i=0; i<n; i++){
                scanf("%d",&RRN);
                scanf("%s",campo);
                scan_quote_string(valor);
                func7(arq_bin,RRN,campo,valor,city);
            }
            fclose(arq_bin);
            free(city);
            binarioNaTela1(bin);
            break;
        }
        case 8:
            
            break;
        default:
            break;
    }
    return 0;

}
