#include <stdio.h>
#include <limits.h>
#define N 4
#define VISITED_ALL (1<<N)-1
int dist[N][N];
int dp[1<<N][N];
int tsp(int mask, int pos) {
if (mask == VISITED_ALL)
return dist[pos][0];
if (dp[mask][pos] != -1)
return dp[mask][pos];
int ans = INT_MAX;
for (int city = 0; city < N; city++) {
if ((mask & (1 << city)) == 0) {
int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
if (newAns < ans)
ans = newAns;
}
}
return dp[mask][pos] = ans;
}
int main() {
printf("Enter the 4x4 distance matrix (0 for same node):\n");
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
printf("Distance from node %c to node %c: ", 'a' + i, 'a' + j);
scanf("%d", &dist[i][j]);
}
}
// Initialize DP table
for (int i = 0; i < (1 << N); i++)
for (int j = 0; j < N; j++)
dp[i][j] = -1;
printf("\nMinimum TSP cost: %d\n", tsp(1, 0)); // starting from node 0 (a)
return 0;
}