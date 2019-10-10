//Inclusão de bibliotecas
#include <stdlib.h>
#include <stdio.h>


//Declaração das funções
double ** cria_matriz(int);
double somatorio(int,int,double**,double*,int);
double * gauss_seidel(double**,double*,int,double,int);
void imprime_matriz(double**,int);
void imprime_vetor(double*,int);
double norma_infinita(double*,int);
double * multiplica_matriz(double**,double*,int);
double * sub_matriz(double*,double*,int);
void remove_matriz(double **, int);

int main(){
    int n = 500;            //Indica o tamanho da matriz quadrada e dos vetores
    int e = 0.00000001;     //Indica o erro do método
    double soma;        //Variável utilizada na criação do vetor b da alternativa b)
    int itmax = 5*n;    //Número máximo de iterações
    double * x;         //Vetor resposta
    double ** A = cria_matriz(n);   //Criação da matriz A
    double * b = calloc(n,sizeof(double));      //Criação do vetor b
    
    /*for(int i=0; i<n;i++){                //Vetor b da alternativa b) da especificação do problema
        soma = 0;
        for(int j=0; j<n; j++){ 
            soma += A[i][j];
        }
        b[i] = soma;
    }*/
    
    for(int i=0; i<n;i++){                  //Vetor b da alternativa c) da especificação do problema
        b[i] = (1.0/(i+1.0));
    }
    
    x = gauss_seidel(A,b,n,e,itmax);   //Realiza o método iterativo, colocando seu retorno em x
    
    remove_matriz(A,n);             //Liberação do espaço alocado para A
    free(b);                        //Liberação do espaço alocado para b
    
    if(x==NULL){                    //Verifica a divergência do método
        printf("METODO DE GAUSS-SEIDEL DIVERGIU.\n");
        free(x);                    //Liberação do espaço alocado para x
        return 1;
    }
    
    imprime_vetor(x,n);             //Impressão e liberação de x            
    free(x);                        
}

//Executa o método iterativo de Gauss-Seidel
double * gauss_seidel(double ** A, double * b, int n, double e, int itmax){
    int k;
    double * x = calloc(n,sizeof(double));
    double * xk = calloc(n,sizeof(double));
    for(k=0; k<itmax; k++){             //Inicia um laço, verificando o número de iterações
        if(k!=0){
            if(norma_infinita(sub_matriz(x,xk,n),n) <= e){      //Verifica a norma infinita, comparando com o erro
                return x;
            }
            for(int i=0;i<n;i++){               //Para a próxima iteração, atribui x^(k+1) em x^(k)
                xk[i]=x[i];
            }
        }
        for(int i=0; i<n; i++){                 //Obtém x^(k+1)
            x[i] = (b[i] - somatorio(0,i-1,A,x,i) - somatorio(i+1,n-1,A,xk,i))/A[i][i];
        }
    }
    return NULL;
}

//Cria e retorna a matriz A
double ** cria_matriz(int n){
    double ** A = calloc(n, sizeof(double *));
    
    //Alocação do espaço
    for(int i=0; i<n; i++){
        A[i] = calloc(n,sizeof(double));
    }
    
    //Atribuição dos valores segundo as funções especificadas
    for(int i=0; i<n; i++){
        A[i][i] = 5;
    }
    for(int i=0; i<n-1; i++){
        A[i][i+1] = -1;
        A[i+1][i] = -1;
    }
    for(int i=0; i<n-3; i++){
        A[i][i+3] = -1;
        A[i+3][i] = -1;
    }
    return A;
}

//Realiza o somatorio a partir dos limites, da matriz, do vetor e da iteração
double somatorio(int lim_inf, int lim_sup, double ** A, double * x, int i){
    double soma = 0;
    for(int j=lim_inf; j<=lim_sup; j++){
        soma += A[i][j] * x[j];
    }
    return soma;
}


//Cálculo da norma infinita de um vetor de n elementos
double norma_infinita(double * v, int n){
    double maior = 0;
    for(int i=0; i<n; i++){
        if(v[i] < 0){
            v[i] *= -1;
        }
        if(v[i]>maior){
            maior = v[i];
        }
    }
    return maior;
}

//Realiza a subtração de duas matrizes nxn
double * sub_matriz(double * v1, double * v2, int n){
    double * r = calloc(n, sizeof(double));
    for(int i=0; i<n; i++){
        r[i] = v1[i]-v2[i];
    }
    return r;
}

//Realiza a liberação do espaço de uma matriz nxn
void remove_matriz(double **A, int n){
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
    }
    free(A);
}

//Realiza a multiplicação de uma matriz nxn por um vetor de n elementos
double * multiplica_matriz(double**A,double*x,int n){
    double * b = calloc(n,sizeof(double));
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            b[i] += A[i][j]*x[j];
        }
    }
    return b;
}

//Realiza a impressão de matriz nxn
void imprime_matriz(double ** A, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%.4lf ",A[i][j]);
        }
        printf("\n");
    }
}

//Realiza a impressão de vetor de n elementos
void imprime_vetor(double * x, int n){
    printf("[");
    for(int i=0; i<n; i++){
        if(i!= n-1){
            printf("%.4lf, ",x[i]);
        }
        else{
            printf("%.4lf]\n",x[i]);
        }
    }
}
