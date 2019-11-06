#include "trabalho1.h"

int main(){
    FILE *arq_csv = fopen("/home/luis/Documentos/USP/Disciplinas/ED3/Trabalho1/Casos/caso02.csv", "rt");
    
    FILE *arq_bin = fopen("binario.bin", "w+b");

    if(arq_bin==NULL){
        printf("Falha no processamento do arquivo.");
        return 1;
    }

    func1(arq_csv,arq_bin);

    binarioNaTela1("binario.bin");

    fclose(arq_bin);
    fclose(arq_csv);
}
