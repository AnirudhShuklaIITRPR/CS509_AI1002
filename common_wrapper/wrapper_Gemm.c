#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "C:\Users\Dell\Downloads\CS509\Assignment_1\GEMM\src\matrix.h"

int main()
{
    FILE *fp;
    FILE *fo1;
    FILE *fo2;

    int M, K, N;
    int choice;
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
        return 0;
    }

    fp = fopen("tests/test_case_3.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to open input file.\n");
        return 1;
    }

    fo1 = fopen("output/SimpleGemm/output_3.txt", "w");
    fo2 = fopen("output/BlockedGemm/output_3.txt", "w");

    if (fo1 == NULL)
    {
        printf("Unable to create output file.\n");
        fclose(fp);
        return 1;
    }

    if (fo2 == NULL)
    {
        printf("Unable to create output file.\n");
        fclose(fp);
        return 1;
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

            executionTime = (double)(end-start)/CLOCKS_PER_SEC;

            printf("\nSimple GEMM Result\n");
            printMatrix(C);
            printf("\nExecution Time : %.6f seconds\n",executionTime);
            
            fprintf(fo1,"Simple GEMM Result\n");
            writeMatrix(fo1,C);
            fprintf(fo1,"\nExecution Time : %.6f seconds\n",executionTime);

            freeMatrix(&C);
            break;
        }

        case 2:
        {
            start = clock();
            Matrix D = multiplyBlocked(A,B,blockSize);
            end = clock();

            executionTime = (double)(end-start)/CLOCKS_PER_SEC;

            printf("\nBlocked GEMM Result\n");
            printMatrix(D);
            printf("\nExecution Time : %.6f seconds\n",executionTime);

            fprintf(fo2,"Blocked GEMM Result\n");
            writeMatrix(fo2,D);
            fprintf(fo2,"\nExecution Time : %.6f seconds\n",executionTime);

            freeMatrix(&D);
            break;
        }

        case 3:
        {
            double simpleTime, blockedTime;

            start = clock();
            Matrix C = multiplySimple(A,B);
            end = clock();

            simpleTime =(double)(end-start)/CLOCKS_PER_SEC;

            start = clock();
            Matrix D = multiplyBlocked(A,B,blockSize);
            end = clock();

            blockedTime =(double)(end-start)/CLOCKS_PER_SEC;

            printf("\nSimple GEMM Time : %.6f seconds\n",simpleTime);
            printf("Blocked GEMM Time : %.6f seconds\n",blockedTime);

            break;
        }

        default:
            printf("Invalid Choice\n");
    }

    freeMatrix(&A);
    freeMatrix(&B);

    fclose(fo1);
    fclose(fo2);

    return 0;
}
