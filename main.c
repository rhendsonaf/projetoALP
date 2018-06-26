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
        scanf("%d", &op);

    switch(op){
        case 1:
            printf("===> Quantidade de linhas de A:");
            scanf("%d", &matrixA.rows);
            printf("\n===> Quantidade de colunas de A:");
            scanf("%d", &matrixA.columns);
            printf("Dimensões da Matriz A definidas, para começar a preenche-la pressione 3 ou 5\n");
            break;
        case 2:
            printf("===> Quantidade de linhas de B:");
            scanf("%d", &matrixB.rows);
            printf("\n===> Quantidade de colunas de B:");
            scanf("%d", &matrixB.columns);
            printf("Dimensões da Matriz A definidas, para começar a preenche-la pressione 4 ou 6\n");
            break;
        case 3:
            rand_Matriz(matxA, matrixA);
            break;
        case 4:
            rand_Matriz(matxB, matrixB);
            break;
        case 5:
            manu_Matriz(matxA, matrixA);
            break;
        case 6:
            manu_Matriz(matxB, matrixB);
            break;
        case 7:
            if(matrixA.rows == matrixB.rows && matrixA.columns == matrixB.columns){
            matrixC = somaMatriz(matxA, matxB, matxC, matrixA);
        }else{
            printf("A dimensões das matrizes são diferentes entre si, tente redefinir seus tamanhos.");
        }
            break;
        case 8:
            if(matrixA.rows == matrixB.rows && matrixA.columns == matrixB.columns){
            matrixC = subMatriz(matxA, matxB, matxC, matrixA);
        }else{
            printf("A dimensões das matrizes são diferentes entre si, tente redefinir seus tamanhos.");
        }
            break;
        case 9:
            if(matrixA.columns == matrixB.rows){
                matrixC = multMatriz(matxA, matxB, matxC, matrixA, matrixB);
            }else{
                printf("A multiplicação não pode ser executada, edite as dimensões das matrizes e tente novamente");
            }
            break;
        case 10:
            imprime_Matriz(matxA, matrixA);
            break;
        case 11:
            imprime_Matriz(matxB, matrixB);
            break;
        case 12:
            imprime_Matriz(matxC, matrixC);
            break;
        case 13:
            setaMatArquivo(matxA, matrixA);
            break;
        case 14:
            setaMatArquivo(matxB, matrixB);
            break;
        case 15:
            escreveMatC(matxC, matrixC);
            break;
        case 16:
            exit(0);
        default :
            printf ("Valor invalido!\n");
    }
}
    return 0;
}
