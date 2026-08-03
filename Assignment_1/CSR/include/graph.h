#ifndef GRAPH_H
#define GRAPH_H

// Node of Adjacency List
typedef struct Node
{
    int destination;      // Destination vertex
    int weight;           // Edge weight
    struct Node *next;    // Next adjacent vertex
} Node;

// Graph Structure
typedef struct
{
    int vertices;         // Number of vertices
    int edges;            // Number of edges
    Node **adjList;       // Array of adjacency lists
} Graph;

// Function Prototypes
Graph createGraph(int vertices);
void addEdge(Graph *graph, int source, int destination, int weight);
void readGraph(Graph *graph, const char *filename);
void printGraph(Graph graph);
void freeGraph(Graph *graph);

#endif