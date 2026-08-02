#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

// Matrix Structure 
typedef struct
{
    int rows;
    int cols;
    int **data;
} Matrix;

// Memory Management 
Matrix createMatrix(int rows, int cols);
void freeMatrix(Matrix *mat);

// File Operations
void readMatrix(FILE *fp, Matrix *mat);
void printMatrix(Matrix mat);
void writeMatrix(FILE *fp, Matrix mat);

// Matrix Operations 
Matrix multiplySimple(Matrix A, Matrix B);
Matrix multiplyBlocked(Matrix A, Matrix B, int blockSize);

#endif