#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int separa(int vetor[], int esq, int dir){
    int pivo = vetor[dir]; 
    int t, j = esq;
    for(int k=esq; k<dir; k++){
        if(vetor[k] <= pivo){
            t = vetor[j];
            vetor[j] = vetor[k];
            vetor[k] = t;
            j++; 
        } 
    }
    t = vetor[j];
    vetor[j] = vetor[dir];
    vetor[dir] = t;
    return j; 
}

void quickSort(int vetor[], int esq, int dir){
   if(esq < dir){                   
      int j = separa (vetor, esq, dir);   
      quickSort(vetor, esq, j-1);      
      quickSort(vetor, j+1, dir);      
   }
}

void preencherVetor(int vetor[], int n){ //Função que preenche vetor automaticamente
    srand((unsigned)time(NULL)); //Utilizada para renovar a semente do random
    int i;
    for(i=0; i<n; i++){
        vetor[i] = rand() % 10000000; //Random de 0 a 99999
    }
}

void imprimirVetor(int vetor[], int n){ //Função que imprime o vetor
    printf("\n\t----------------VETOR----------------\n");
    int i;
    for(i=0; i<n; i++){
        printf("[%d]  ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int n = 1000000;
    int vetor[n];
    preencherVetor(vetor, n);
    imprimirVetor(vetor, n);
    quickSort(vetor, 0, n-1);
    imprimirVetor(vetor, n);   
    return 0;
}
