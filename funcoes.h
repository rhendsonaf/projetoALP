#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGHT_MAX 50

typedef struct matriz{
    int rows;
    int columns;
} matriz;

// This function allow the user to fill a matrix manually.
void matrixFill(float mat[][LENGHT_MAX], struct matriz m){
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            printf("\nInsira o valor da linha %d e coluna %d: \n", i+1, j+1);
            scanf("%f\n", &mat[i][j]);
        }
    }
    printf("A Matriz foi preenchida com sucesso.\n");
}

// This function fill the matrix with random numbers. 
void matrixRand(float mat[][LENGHT_MAX],struct matriz m){
    srand(time(NULL));

    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            mat[i][j] = rand() % 10;
        }
    }
    printf("A Matriz foi preenchida com valores aleatórios.\n");
}

// This function print a matrix in the screen.
void matrixPrint(float matriz[][LENGHT_MAX], struct matriz m){
    printf("\n");
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            printf("%.f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// This function make a sum of matrices (Arrays).
matriz matrixSum(float matA[][LENGHT_MAX], float matB[][LENGHT_MAX], float matC[][LENGHT_MAX], struct matriz mA){
    for(int i = 0; i < mA.rows; i++){
        for(int j = 0; j < mA.columns; j++){
            matC[i][j] = matA[i][j] + matB[i][j];
        }
    }
    printf("A soma de matrizes foi efetuada.\n\n");
    return mA;
}

// This function make a subtraction of matrices (Arrays).
matriz matrixSub(float matA[][LENGHT_MAX], float matB[][LENGHT_MAX], float matC[][LENGHT_MAX], struct matriz mA){
    for(int i = 0; i < mA.rows; i++){
        for(int j = 0; j < mA.columns; j++){
            matC[i][j] = matA[i][j] - matB[i][j];
        }
    }
    printf("A subtração de matrizes foi efetuada.\n\n");
    return mA;
}

// This function make a multiplication of matrices (Arrays).
matriz matrixMult(float matA[][LENGHT_MAX], float matB[][LENGHT_MAX], float matC[][LENGHT_MAX], struct matriz mA, struct matriz mB){
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
    printf("A multiplicação de matrizes foi efetuada.\n");
    return mC;
}

// This function read a matrix from a txt file.
void readMatrix(float mat[][LENGHT_MAX], struct matriz m){
    FILE *f;
    int r, c;

    f = fopen("home/niohggir/ProjectALP/matriz.txt","r");

    if (f == NULL) {
        printf("O arquivo não existe.");
        return;
    }

    fscanf(f, "%d", &r);
    fscanf(f, "%d", &c);

    m.rows = r;
    m.columns = c;

    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.columns; j++){
            fscanf(f, "%f", &mat[i][j]);
        }
    }

    printf("A matriz foi preenchida a partir do arquivo em questão.");
    fclose(f);
}

// This function write a matrix in a txt file.
void writeMatrix(float matC[][LENGHT_MAX], struct matriz mC){
    FILE *f;
    f = fopen("home/niohggir/ProjectALP/matrizC.txt", "w");

    fprintf(f, "%d %d \n", mC.rows, mC.columns);
    for(int i = 0; i < mC.rows; i++){
        for(int j = 0; j < mC.columns; j++){
            fprintf(f, "%.2f ", matC[i][j]);
        }
        fprintf(f ,"\n");
    }
    printf("A matriz C foi escrita em um arquivo.");
    fclose(f);
}
