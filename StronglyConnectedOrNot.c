#include <stdio.h>
#include <stdlib.h>
#define MAX 100
// Structure to represent a graph
typedef struct Graph {
    int V;
    int adj[MAX][MAX];
} Graph;
// Function to create a graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}
// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v) {
    graph->adj[u][v] = 1;
}
// Function to perform DFS on the graph
void DFS(Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v][i] == 1 && visited[i] == 0) {
            DFS(graph, i, visited);
        }
    }
}
// Function to check if the graph is strongly connected
int isStronglyConnected(Graph* graph) {
    int visited[MAX] = {0};
    // Perform DFS from vertex 0
    DFS(graph, 0, visited);

    // Check if all vertices are visited
    for (int i = 0; i < graph->V; i++) {
        if (visited[i] == 0) {
            return 0; // Graph is not strongly connected
        }
    }
    // Create the transpose of the graph
    Graph* transposeGraph = createGraph(graph->V);
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            if (graph->adj[i][j] == 1) {
                addEdge(transposeGraph, j, i);
            }
        }
    }
    // Perform DFS on the transpose graph
    int visitedTranspose[MAX] = {0};
    DFS(transposeGraph, 0, visitedTranspose);

    // Check if all vertices are visited
    for (int i = 0; i < graph->V; i++) {
        if (visitedTranspose[i] == 0) {
            return 0; // Graph is not strongly connected
        }
    }
    return 1; // Graph is strongly connected
}
int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    Graph* graph = createGraph(V);
    int E;
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    for (int i = 0; i < E; i++) {
        int u, v;
        printf("Enter edge %d (u v): ", i + 1);
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    if (isStronglyConnected(graph)) {
        printf("The graph is strongly connected.\n");
    } else {
        printf("The graph is not strongly connected.\n");
    }
    return 0;
}
