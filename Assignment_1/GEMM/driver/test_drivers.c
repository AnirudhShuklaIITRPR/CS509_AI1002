#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "C:\Users\Dell\Downloads\CS509\Assignment_1\GEMM\src\matrix.h"

int main()
{
    FILE *fp;    
    FILE *fo;

    int M;
    int K;
    int N;

    // Open Input File
    fp = fopen("tests/test_case_1.txt", "r");   // Subject to Change

    if (fp == NULL)
    {
        printf("Error: Unable to open input file.\n");
        return 1;
    }
    
    // creatr Output File
    fo = fopen("output/output_1.txt", "w");
    
    if (fo == NULL)
    {
        printf("Unable to create output file.\n");
        return 1;
    }

    // Read Matrix Dimensions 
    fscanf(fp, "%d %d %d", &M, &K, &N);

    // Create Matrices 
    Matrix A = createMatrix(M, K);
    Matrix B = createMatrix(K, N);

    // Read Matrix A and Matrix B
    readMatrix(fp, &A);
    readMatrix(fp, &B);

    fclose(fp);

    clock_t start, end;
    double simpleTime, blockedTime;

    int blockSize = 32;

    // Simple GEMM 
    start = clock();
    Matrix C = multiplySimple(A, B);
    end = clock();
    simpleTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Blocked GEMM
    start = clock();
    Matrix D = multiplyBlocked(A, B, blockSize);
    end = clock();
    blockedTime = (double)(end - start) / CLOCKS_PER_SEC;

    // Display Input 
    printf("\nMATRIX MULTIPLICATION\n");
    printf("\nMatrix A (%d x %d)\n", A.rows, A.cols);
    printMatrix(A);
    printf("\nMatrix B (%d x %d)\n", B.rows, B.cols);
    printMatrix(B);

    // Simple GEMM Output 
    printf("\nSimple GEMM Result\n");
    printMatrix(C);
    printf("\nExecution Time (Simple GEMM) : %.6f seconds\n",simpleTime);
    // writing of output
    fprintf(fo, "Simple GEMM Result\n");
    writeMatrix(fo, C);
    fprintf(fo, "\nExecution Time (Simple GEMM): %.6f seconds\n",simpleTime);

    // Blocked GEMM Output 
    printf("\nBlocked GEMM Result\n");
    printMatrix(D);
    printf("\nExecution Time (Blocked GEMM) : %.6f seconds\n",blockedTime);
    // writing of output
    fprintf(fo, "\nBlocked GEMM Result\n");
    writeMatrix(fo, D);
    fprintf(fo, "\nExecution Time (Blocked GEMM): %.6f seconds\n",blockedTime);

    // Free Memory 
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&D);

    fclose(fo);

    return 0;
}