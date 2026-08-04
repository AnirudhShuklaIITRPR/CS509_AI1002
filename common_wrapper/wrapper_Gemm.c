#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "C:\Users\Dell\Downloads\CS509\Assignment_1\GEMM\src\matrix.h"

void wrapper()
{
    FILE *fp;

    int M, K, N;
    int choice;
    int inputfile;
    int blockSize = 32;

    printf("\nMATRIX MULTIPLICATION MENU\n");
    printf("1. Simple GEMM\n");
    printf("2. Blocked GEMM\n");
    printf("3. Compare Both\n");
    printf("0. Exit\n");
    printf("-------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        printf("Program Terminated.\n");
        return;
    }

    printf("Enter the number of Input File: ");
    scanf("%d", &inputfile);

    fp = fopen("tests/test_case_{inputfile}.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to open input file.\n");
        return;
    }

    fscanf(fp, "%d %d %d", &M, &K, &N);

    Matrix A = createMatrix(M, K);
    Matrix B = createMatrix(K, N);

    readMatrix(fp, &A);
    readMatrix(fp, &B);

    fclose(fp);

    clock_t start, end;
    double executionTime;

    switch(choice)
    {
        case 1:
        {
            start = clock();
            Matrix C = multiplySimple(A, B);
            end = clock();

            executionTime = (double)(end - start) / CLOCKS_PER_SEC;

            printf("\nSimple GEMM Result\n");
            printMatrix(C);
            printf("\nExecution Time : %.6f seconds\n", executionTime);

            freeMatrix(&C);
            break;
        }

        case 2:
        {
            start = clock();
            Matrix D = multiplyBlocked(A, B, blockSize);
            end = clock();

            executionTime = (double)(end - start) / CLOCKS_PER_SEC;

            printf("\nBlocked GEMM Result\n");
            printMatrix(D);
            printf("\nExecution Time : %.6f seconds\n", executionTime);

            freeMatrix(&D);
            break;
        }

        case 3:
        {
            double simpleTime, blockedTime;

            start = clock();
            Matrix C = multiplySimple(A, B);
            end = clock();
            simpleTime = (double)(end - start) / CLOCKS_PER_SEC;

            start = clock();
            Matrix D = multiplyBlocked(A, B, blockSize);
            end = clock();
            blockedTime = (double)(end - start) / CLOCKS_PER_SEC;

            printf("\nSimple GEMM Result\n");
            printMatrix(C);
            printf("\nSimple GEMM Execution Time : %.6f seconds\n", simpleTime);

            printf("\nBlocked GEMM Result\n");
            printMatrix(D);
            printf("\nBlocked GEMM Execution Time : %.6f seconds\n", blockedTime);

            freeMatrix(&C);
            freeMatrix(&D);
            break;
        }

        default:
            printf("\nInvalid Choice\n");
    }

    freeMatrix(&A);
    freeMatrix(&B);
}