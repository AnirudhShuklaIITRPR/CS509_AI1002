#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

//    Function : createMatrix   &   Purpose  : Dynamically allocate memory for a matrix

Matrix createMatrix(int rows, int cols)
{
    Matrix mat;

    mat.rows = rows;
    mat.cols = cols;

    mat.data = (int **)malloc(rows * sizeof(int *));

    if (mat.data == NULL)
    {
        printf("Memory Allocation Failed!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        mat.data[i] = (int *)malloc(cols * sizeof(int));

        if (mat.data[i] == NULL)
        {
            printf("Memory Allocation Failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    return mat;
}

//    Function : freeMatrix  &   Purpose  : Free dynamically allocated memory

void freeMatrix(Matrix *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        free(mat->data[i]);
    }

    free(mat->data);

    mat->data = NULL;
}

//   Function : readMatrix  &   Purpose  : Read matrix elements from input file

void readMatrix(FILE *fp, Matrix *mat)
{
    for (int i = 0; i < mat->rows; i++)
    {
        for (int j = 0; j < mat->cols; j++)
        {
            fscanf(fp, "%d", &mat->data[i][j]);
        }
    }
}

//   Function : printMatrix  &  Purpose  : Display matrix

void printMatrix(Matrix mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            printf("%d ", mat.data[i][j]);
        }

        printf("\n");
    }
}

void writeMatrix(FILE *fp, Matrix mat)
{
    for (int i = 0; i < mat.rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            fprintf(fp, "%d ", mat.data[i][j]);
        }
        fprintf(fp, "\n");
    }
}

//    Function : multiplySimple   &   Purpose  : Perform Simple GEMM

Matrix multiplySimple(Matrix A, Matrix B)
{
    if (A.cols != B.rows)
    {
        printf("Error: Matrix multiplication not possible.\n");
        exit(EXIT_FAILURE);
    }

    Matrix C = createMatrix(A.rows, B.cols);

    // Initialize Result Matrix 
    for (int i = 0; i < C.rows; i++)
    {
        for (int j = 0; j < C.cols; j++)
        {
            C.data[i][j] = 0;
        }
    }

    // Simple GEMM
    for (int i = 0; i < A.rows; i++)
    {
        for (int j = 0; j < B.cols; j++)
        {
            for (int k = 0; k < A.cols; k++)
            {
                C.data[i][j] +=
                    A.data[i][k] * B.data[k][j];
            }
        }
    }

    return C;
}

//    Function : multiplyBlocked   &  Purpose  : Perform Blocked (Tiled) GEMM

Matrix multiplyBlocked(Matrix A, Matrix B, int blockSize)
{
    if (A.cols != B.rows)
    {
        printf("Error: Matrix multiplication not possible.\n");
        exit(EXIT_FAILURE);
    }

    Matrix C = createMatrix(A.rows, B.cols);

    // Initialize Result Matrix
    for (int i = 0; i < C.rows; i++)
    {
        for (int j = 0; j < C.cols; j++)
        {
            C.data[i][j] = 0;
        }
    }

    // Blocked Multiplication
    for (int ii = 0; ii < A.rows; ii += blockSize)
    {
        for (int jj = 0; jj < B.cols; jj += blockSize)
        {
            for (int kk = 0; kk < A.cols; kk += blockSize)
            {
                int iMax = (ii + blockSize < A.rows) ? ii + blockSize : A.rows;
                int jMax = (jj + blockSize < B.cols) ? jj + blockSize : B.cols;
                int kMax = (kk + blockSize < A.cols) ? kk + blockSize : A.cols;

                for (int i = ii; i < iMax; i++)
                {
                    for (int j = jj; j < jMax; j++)
                    {
                        for (int k = kk; k < kMax; k++)
                        {
                            C.data[i][j] +=
                                A.data[i][k] * B.data[k][j];
                        }
                    }
                }
            }
        }
    }

    return C;
}