#ifndef CSR_H
#define CSR_H

#include "graph.h"

// CSR Structure
typedef struct
{
    int vertices;      // Number of vertices
    int edges;         // Number of edges

    int *rowPtr;       // Row pointer array
    int *colIndex;     // Column index array
    int *weight;       // Edge weight array

} CSR;

// Function Prototypes
CSR createCSR(int vertices, int edges);
CSR convertToCSR(Graph graph);
void printCSR(CSR csr);
void freeCSR(CSR *csr);

#endif