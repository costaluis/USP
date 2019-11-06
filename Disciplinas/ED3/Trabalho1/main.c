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
            FILE *arq_bin = fopen(bin,"rt");

            if(arq_csv == NULL){
                printf("Falha no processamento do arquivo.");
                return 1;
            }
            if(arq_bin == NULL){
                printf("Falha no processamento do arquivo.");
                return 1;
            }\

            func1(arq_csv,arq_bin,city);

            free(city);
            fclose(arq_bin);
            fclose(arq_csv);
            
            binarioNaTela1(bin);
            break;
        }
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        default:
            break;
    }
    return 0;

}
