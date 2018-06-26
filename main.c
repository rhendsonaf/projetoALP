#include <funcoes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGHT_MAX 50

int main() {

    struct matriz matrixA;
    float matxA[LENGHT_MAX][LENGHT_MAX];

    struct matriz matrixB;
    float matxB[LENGHT_MAX][LENGHT_MAX];

    struct matriz matrixC;
    float matxC[LENGHT_MAX][LENGHT_MAX];

    int op = 0;

    while(op != 16){
        printf("PROGRAMA DE MANIPULACAO DE MATRIZES\n"
        "(1) Definir o tamanho da matriz A\n"
        "(2) Definir o tamanho da matriz B\n"
        "(3) Preencher a matriz A com valores aleatórios\n"
        "(4) Preencher a matriz B com valores aleatórios\n"
        "(5) Atribuir valores manualmente para os elementos da matriz A\n"
        "(6) Atribuir valores manualmente para os elementos da matriz B\n"
        "(7) Calcular A+B\n"
        "(8) Calcular A-B\n"
        "(9) Calcular A*B\n"
        "(10) Imprimir matriz A\n"
        "(11) Imprimir matriz B\n"
        "(12) Imprimir matriz C\n"
        "(13) Ler a mtriz A de um arquivo\n"
        "(14) Ler a mtriz B de um arquivo\n"
        "(15) Escrever a matriz C em um arquivo\n"
        "(16) Sair"
               "\n"
        );
        scanf("%d\n", &op);

    switch(op){
        case 1:
            printf("Insira a quantidade de linhas de A: ");
            scanf("%d\n", &matrixA.rows);
            printf("Insira a quantidade de colunas de A: ");
            scanf("%d\n", &matrixA.columns);
            printf("As dimensões da matriz A foram definidas.\n");
            break;
        case 2:
            printf("Insira a quantidade de linhas de B: \n");
            scanf("%d", &matrixB.rows);
            printf("Insira a quantidade de linhas de B: \n");
            scanf("%d", &matrixB.columns);
            printf("As dimensões da matriz B foram definidas.\n");
            break;
        case 3:
            matrixRand(matxA, matrixA);
            break;
        case 4:
            matrixRand(matxB, matrixB);
            break;
        case 5:
            matrixFill(matxA, matrixA);
            break;
        case 6:
            matrixFill(matxB, matrixB);
            break;
        case 7:
            if(matrixA.rows == matrixB.rows && matrixA.columns == matrixB.columns){
                matrixC = matrixSum(matxA, matxB, matxC, matrixA);
            }
            else {
                printf("As dimensões das matrizes A e B são diferentes, operação inválida.");
            }
            break;
        case 8:
            if(matrixA.rows == matrixB.rows && matrixA.columns == matrixB.columns){
                matrixC = matrixSub(matxA, matxB, matxC, matrixA);
            }
            else {
            printf("As dimensões das matrizes A e B são diferentes, operação inválida.");
            }
            break;
        case 9:
            if(matrixB.rows == matrixA.columns){
                matrixC = matrixMult(matxA, matxB, matxC, matrixA, matrixB);
            }
            else {
                printf("O número de linhas de B é diferente do número de colunas de A.");
            }
            break;
        case 10:
            matrixPrint(matxA, matrixA);
            break;
        case 11:
            matrixPrint(matxB, matrixB);
            break;
        case 12:
            matrixPrint(matxC, matrixC);
            break;
        case 13:
            readMatrix(matxA, matrixA);
            break;
        case 14:
            readMatrix(matxB, matrixB);
            break;
        case 15:
            writeMatrix(matxC, matrixC);
            break;
        case 16:
            exit(0);
        default :
            printf ("Operação inválida, digite um número de 1 a 16.\n");
    }
}
    return 0;
}
