#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "C:\Users\Dell\Downloads\CS509\Assignment_1\CSR\include\graph.h"
#include "C:\Users\Dell\Downloads\CS509\Assignment_1\CSR\include\csr.h"

int main()
{
    Graph graph;
    CSR csr;

    int choice;
    int source;

    clock_t start, end;
    double executionTime;

    // Read Graph
    readGraph(&graph, "test/test_case_3.txt");

    // Convert Adjacency List to CSR
    csr = convertToCSR(graph);
    
    printCSR(csr);

    return 0;
}