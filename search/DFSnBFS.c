#include <stdio.h>
int Graph[1001][1001] = {0}; 
int dfsVisit[1001] = {0}; 
int bfsVisit[1001] = {0}; 
int queue[1001]; 

void DFS(int v, int N) {
	dfsVisit[v] = 1;
	printf("%d ", v); 

	for (int i = 1; i <= N; i++) {
		if (Graph[v][i] == 1 && dfsVisit[i] == 0) {
			DFS(i, N); 
		}
	} 

	return; 
}

void BFS(int start, int N) {
	int front = 0, rear = 0, Pop; 

	queue[0] = start; 
	rear++; 
	bfsVisit[start] = 1; 
	printf("%d ", start); 

	while (front < rear) {
		Pop = queue[front]; 
		front++; 

		for (int i = 1; i <= N; i++) {
			if (Graph[Pop][i] == 1 && bfsVisit[i] == 0) {
				queue[rear] = i; 
				rear++; 
				printf("%d ", i); 
				bfsVisit[i] = 1; 
			}
		}
	}
}

int main()
{
	int N, M, start; 
	scanf("%d %d %d", &N, &M, &start); 

	int x, y; 
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y); 
		Graph[x][y] = 1; 
		Graph[y][x] = 1; 
	}

	DFS(start, N); 
	printf("\n");
	BFS(start, N); 
}