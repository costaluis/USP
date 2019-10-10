#include <stdlib.h>
#include <stdio.h>

double ** cria_matriz(int);
double somatorio(int,int,double**,double*,int);
double * gauss_seidel(double**,double*,int,double,int);
void imprime_matriz(double**,int);
void imprime_vetor(double*,int);
double norma_infinita(double*,double*,int);
double * multiplica_matriz(double**,double*,int);

int main(){
    int n = 500;
    double soma;
    int itmax = 5*n;
    double ** A = cria_matriz(n);
    //imprime_matriz(A,n);
    double * b = calloc(n,sizeof(double));
    /*for(int i=0; i<n;i++){
        soma = 0;
        for(int j=0; j<n; j++){
            soma += A[i][j];
        }
        b[i] = soma;
    }*/
    for(int i=0; i<n;i++){
        b[i] = (1.0/(i+1.0));
    }
    double * x = gauss_seidel(A,b,n,0.00000001,itmax);
    imprime_vetor(x,n);
    
}

double * gauss_seidel(double ** A, double * b, int n, double e, int itmax){
    double * x = calloc(n,sizeof(double));
    double * xk = calloc(n,sizeof(double));
    for(int k=0; k<itmax; k++){
        if(k!=0){
            if(norma_infinita(x,xk,n) <= e){
                return x;
            }
            for(int i=0;i<n;i++){
                xk[i]=x[i];
            }
        }
        for(int i=0; i<n; i++){
            x[i] = (b[i] - somatorio(0,i-1,A,x,i) - somatorio(i+1,n-1,A,xk,i))/A[i][i];
        }
    }
    return x;
        
}

double ** cria_matriz(int n){
    double ** A;
    A = calloc(n, sizeof(double *));
    for(int i=0; i<n; i++){
        A[i] = calloc(n,sizeof(double));
    }
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

double somatorio(int lim_inf, int lim_sup, double ** A, double * x, int i){
    double soma = 0;
    for(int j=lim_inf; j<=lim_sup; j++){
        soma += A[i][j] * x[j];
    }
    return soma;
}

void imprime_matriz(double ** A, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%.4lf ",A[i][j]);
        }
        printf("\n");
    }
}

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

double norma_infinita(double * v1, double * v2, int n){
    double * r = calloc(n, sizeof(double));
    double maior = 0;
    for(int i=0; i<n; i++){
        r[i] = v1[i]-v2[i];
    }
    for(int i=0; i<n; i++){
        if(r[i] < 0){
            r[i] *= -1;
        }
        if(r[i]>maior){
            maior = r[i];
        }
    }
    return maior;
}

double * multiplica_matriz(double**A,double*x,int n){
    double * b = calloc(n,sizeof(double));
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            b[i] += A[i][j]*x[j];
        }
    }
    imprime_vetor(b,n);
    return b;

}

