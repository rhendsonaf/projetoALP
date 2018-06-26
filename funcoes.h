#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGHT_MAX 50

typedef struct matriz{
    int rows;
    int columns;
} matriz;

void rand_Matriz(float mat[][LENGHT_MAX],struct matriz m){
    //
    srand(time(NULL));

    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            mat[i][j] = rand() % 10;
        }
    }
    printf("Matriz preenchida aleatoriamente.\n\n");
}

void manu_Matriz(float mat[][LENGHT_MAX], struct matriz m){
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            printf("\nDigite o valor da linha %d e coluna %d: \n", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
    printf("Matriz preenchida manualmente.\n\n");
}

void imprime_Matriz(float matriz[][LENGHT_MAX], struct matriz m){
    printf("-----------IMPRIMINDO MATRIZ-----------\n");
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

matriz somaMatriz(float matA[][LENGHT_MAX], float matB[][LENGHT_MAX], float matC[][LENGHT_MAX], struct matriz mA){
    for(int i = 0; i < mA.rows; i++){
        for(int j = 0; j < mA.columns; j++){
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }
    printf("Soma executada, selecione a opção 12 pra visualizar a nova matriz C.\n\n");
    return mA;
}
matriz subMatriz(float matA[][LENGHT_MAX], float matB[][LENGHT_MAX], float matC[][LENGHT_MAX], struct matriz mA){
    for(int i = 0; i < mA.rows; i++){
        for(int j = 0; j < mA.columns; j++){
            matC[i][j] = matA[i][j] - matB[i][j];
        }
    }
    printf("Subtração executada, selecione a opção 12 pra visualizar a nova matriz C.\n\n");
    return mA;
}
matriz multMatriz(float matA[][LENGHT_MAX], float matB[][LENGHT_MAX], float matC[][LENGHT_MAX], struct matriz mA, struct matriz mB){
    struct matriz mC;
    mC.columns = mA.columns;
    mC.rows = mB.rows;

    float aux = 0;
    for(int i = 0; i < mA.rows; i++){
        for(int j = 0; j < mB.columns; j++){
            matC[i][j] = 0;
            for(int k = 0; k < mB.rows; k++){
                aux += matA[i][k]*matB[k][j];
            }
            matC[i][j] = aux;
            aux = 0;
        }
    }
    printf("Multiplicação executada, pressione 12 para visualizar a nova matriz.\n");
    return mC;
}

void setaMatArquivo(float mat[][LENGHT_MAX], struct matriz m){
    FILE *f;
    int l, c;

    f = fopen("home/niohggir/ProjectALP/matriz.txt","r");

    if (f == NULL) {
        printf("O arquivo não foi localizado.");
        return;
    }

    fscanf(f, "%d", &l);
    fscanf(f, "%d", &c);

    m.rows = l;
    m.columns = c;

    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            fscanf(f, "%f", &mat[i][j]);
        }
    }

    printf("A matriz foi preenchida pressione 10(se for A) ou 11(se for B) para visualiza-la");
    fclose(f);
}
void escreveMatC(float matC[][LENGHT_MAX], struct matriz mC){
    FILE *f;
    f = fopen("home/niohggir/ProjectALP/matrizC.txt","w");

    fprintf(f, "%d %d \n", mC.rows, mC.columns);
    for(int i = 0; i < mC.rows; i++){
        for(int j = 0; j < mC.columns; j++){
            fprintf(f,"%.2f ", matC[i][j]);
        }
        fprintf(f, "\n");
    }
    printf("Matriz estrita no arquivo, procure o arquivo para visualiza-la.");
    fclose(f);
}
