#include <stdio.h>
#include <limits.h>
#define V 100 // Maximum number of vertices (you can change this)
int i,j,v;
int minKey(int key[], int mstSet[], int n) {
int min = INT_MAX, minIndex;
for ( v = 0; v < n; v++)
if (mstSet[v] == 0 && key[v] < min)
min = key[v], minIndex = v;
return minIndex;
}
void printMST(int parent[], int graph[V][V], int n) {
printf("Edge \tWeight\n");
for (i = 1; i < n; i++)
printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[V][V], int n) {
int parent[n], key[n], mstSet[n];
for ( i = 0; i < n; i++) {
key[i] = INT_MAX;
mstSet[i] = 0;
}
key[0] = 0;
parent[0] = -1;
int count = 0;
for (count = 0; count < n - 1; count++) {
int u = minKey(key, mstSet, n);
mstSet[u] = 1;
for ( v = 0; v < n; v++) {
if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
parent[v] = u;
key[v] = graph[u][v];
}
}
}
printMST(parent, graph, n);
}
int main() {
int n;
int graph[V][V];
printf("Enter the number of vertices: ");
scanf("%d", &n);
printf("Enter the adjacency matrix :\n", n, n);
for ( i = 0; i < n; i++)
for ( j = 0; j < n; j++)
scanf("%d", &graph[i][j]);
primMST(graph, n);
return 0;
}
