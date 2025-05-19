#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int graph[MAX][MAX], visited[MAX];
char nodes[MAX];
void bfs(int start, int n) {
int queue[MAX], front = 0, rear = 0;
visited[start] = 1;
queue[rear++] = start;
while (front < rear) {
int current = queue[front++];
printf("%c ", nodes[current]);
for (int i = 0; i < n; i++) {
if (graph[current][i] == 1 && !visited[i]) {
visited[i] = 1;
queue[rear++] = i;
}
}
}
}
int main() {
int n, i, j;
printf("Enter number of nodes: ");
scanf("%d", &n);
printf("Enter labels of nodes (e.g. A B C ...):\n");
for (i = 0; i < n; i++) {
scanf(" %c", &nodes[i]);
}
printf("Enter adjacency matrix (%d x %d):\n", n, n);
for (i = 0; i < n; i++)
for (j = 0; j < n; j++)
scanf("%d", &graph[i][j]);
// Initialize visited array
for (i = 0; i < n; i++)
visited[i] = 0;
char startNode;
printf("Enter starting node: ");
scanf(" %c", &startNode);
int startIndex = -1;
for (i = 0; i < n; i++) {
if (nodes[i] == startNode) {
startIndex = i;
break; } }
if (startIndex == -1) {
printf("Invalid start node!\n");
return 1;
}
printf("BFS traversal starting from node %c:\n", startNode);
bfs(startIndex, n);
return 0;
}