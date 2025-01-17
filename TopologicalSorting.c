#include <stdio.h>
#include <stdlib.h>
int s[100], j, res[100];
void AdjacencyMatrix(int a[][100], int n) 
{
    int i, j;
    for (i = 0; i < n; i++) { 
        for (j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            a[i][j] = rand() % 2;
            a[j][i] = 0; 
        }
    }
}
void dfs(int u, int n, int a[][100]) {
    int v;
    s[u] = 1;
    for (v = 0; v < n; v++) {
        if (a[u][v] == 1 && s[v] == 0) {
            dfs(v, n, a);
        }
    }
    res[j++] = u;
}
void topological_order(int n, int a[][100]) {
    int i, u;
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }
    j = 0;
    for (u = 0; u < n; u++) {
        if (s[u] == 0) {
            dfs(u, n, a);
        }
    }
}
int main() {
    int a[100][100], n, i, k;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    AdjacencyMatrix(a, n);
    printf("\nAdjacency Matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            printf("%d ", a[i][k]);
        }
        printf("\n");
    }
    printf("\nTopological order:\n");
    topological_order(n, a);
    for (i = j - 1; i >= 0; i--) {
        printf("-->%d", res[i]);
    }
    printf("\n");
    return 0;
}
