#include "trabalho1.h"

int main(){
    //FILE *arq_csv = fopen("/home/luis/Documentos/USP/Disciplinas/ED3/Trabalho1/Casos/caso02.csv", "rt");
    
    FILE *arq_bin = fopen("/home/luis/Documentos/USP/Disciplinas/ED3/Trabalho1/Casos/caso21.bin", "rb");

    if(arq_bin==NULL){
        printf("Falha no processamento do arquivo.");
        return 1;
    }

    char campo[20] = "estadoDestino\0";

    char valor[3] = "MG\0";

    //csvtobin(arq_csv,arq_bin);

    //binarioNaTela1("binario.bin");

    func3(campo,valor,arq_bin);

    fclose(arq_bin);
    //fclose(arq_csv);
}
