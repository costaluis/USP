//Exercicio Prático
//Aluno: Luis Fernando Costa de Oliveira
//Nº USP: 10716532
//Professora: Cristina Ciferri


#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    char firstname[20];
    char lastname[20];
    char email[40];
    char nationality[20];
    int age;
}registro;

int ler_registro(registro * pessoa, FILE * fp){
    if(fp==NULL){
        return 0;
    }

    if(!fread(pessoa->firstname,20,1,fp)){
        return 0;
    }
    fread(pessoa->lastname,20,1,fp);
    fread(pessoa->email,40,1,fp);
    fread(pessoa->nationality,20,1,fp);
    fread(&(pessoa->age),4,1,fp);

    return 1;
}

int escreve_registro(registro * pessoa, FILE * fp){
    if(fp==NULL){
        return 0;
    }

    fwrite(pessoa->firstname,20,1,fp);
    fwrite(pessoa->lastname,20,1,fp);
    fwrite(pessoa->email,40,1,fp);
    fwrite(pessoa->nationality,20,1,fp);
    fwrite(&(pessoa->age),4,1,fp);

    return 1;
}

int ler_todos(FILE * fp){
    int i = 0;
    registro * pessoa = malloc(sizeof(registro));
    fseek(fp,0,SEEK_SET);

    while(ler_registro(pessoa,fp)){

        printf("--- Usuario %d ---\n",i);
        printf("FIRSTNAME: %s\n",pessoa->firstname);
        printf("LASTNAME: %s\n",pessoa->lastname);
        printf("EMAIL: %s\n",pessoa->email);
        printf("NATIONALITY: %s\n",pessoa->nationality);
        printf("AGE: %d\n",pessoa->age);
        
        i++;
    }

    return 1;
}

int ler_rrn(FILE * fp, int rrn){
    registro * pessoa = malloc(sizeof(registro));

    fseek(fp,rrn*104,SEEK_SET);

    if(!ler_registro(pessoa,fp)){
        printf("Registro nao encontrado!\n");
        return 0;
    }

    printf("--- Usuario ---\n");
    printf("FIRSTNAME: %s\n",pessoa->firstname);
    printf("LASTNAME: %s\n",pessoa->lastname);
    printf("EMAIL: %s\n",pessoa->email);
    printf("NATIONALITY: %s\n",pessoa->nationality);
    printf("AGE: %d\n",pessoa->age);

    return 1;
}

void recebe_dados(registro * pessoa){

    printf("Insira o primeiro nome: ");
    scanf("%s",pessoa->firstname);
    printf("Insira o ultimo nome: ");
    scanf("%s",pessoa->lastname);
    printf("Insira o email: ");
    scanf("%s",pessoa->email);
    printf("Insira a nacionalidade: ");
    scanf("%s",pessoa->nationality);
    printf("Insira a idade: ");
    scanf("%d",&(pessoa->age));
}

int main(int argc, char * argv[]){
    int a;
    int b;
    int rrn;
    FILE * fp = fopen("registros.bin","w+b");

    while(1){
        printf("--- Inserir Registro ---\n");
        registro * user = malloc(sizeof(registro));
        recebe_dados(user);
        if(!escreve_registro(user,fp)){
            printf("Erro ocorrido!");
            return 0;
        }

        printf("Digite 1 para continuar inserindo ou 0 para encerrar...\n");
        scanf("%d",&a);
        if(a==1){
            continue;
        }else{
            if(a==0){
                break;
            }else{
                printf("Entrada Invalida!\n");
                return 0;
            }
        }
    }

    while(1){
        printf("---------------------------------------\n");
        printf("O que voce deseja?\n");
        printf("1. Ler todos os registros\n");
        printf("2. Ler registro por RRN\n");
        printf("3. Encerrar o programa\n");

        scanf("%d",&b);

        switch (b)
        {
        case 1:
            ler_todos(fp);
            break;
        case 2:
            printf("Insira o RRN: ");
            scanf("%d",&rrn);
            ler_rrn(fp,rrn);
            break;
        case 3:
            printf("Programa encerrado!\n");
            return 1;
        default:
            printf("Entrada invalida!\n");
            break;
        }

    }
    
    
    
    fclose(fp);
}