#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node *next;
	struct _Node *prev; 
	int number; 
} Node; 

void insertNode(int graph[][12], int from, int to) {
	graph[from][to] = 1; 
	graph[to][from] = 0; 
}

void insertQueue(Node *end, int num) {
	Node *newNode = malloc(sizeof(Node)); 
	newNode -> number = num; 

	end -> prev -> next = newNode; 
	newNode -> prev = end -> prev; 
	end -> prev = newNode; 
	newNode -> next = end;
}

void deleteNode(Node *front) {
	Node *target = front -> next; 

	front -> next = target -> next; 
	target -> next -> prev = front; 

	free(target); 
}

int BFSsearch(int graph[][12], Node *front, Node *end, int find) {
	
	int i;  
	insertQueue(end, 1);

	Node *curr; 

	do {
		curr = front -> next; 
		printf("=======\n"); 
		while (curr != end) {
			printf("queue %d\n", curr -> number); 
			curr = curr -> next; 
		}
		printf("======="); 
		i = front -> next -> number;  
		if (i == find) {
			return 1; 
		}
		for (int j = 1; j <= 11; j++) {
			if (graph[i][j] == 1) {
				insertQueue(end, j); 
			}
		}
		deleteNode(front); 

	} while (front -> next != end); 

	return 0; 
}

int main()
{
	int graph[12][12] = {0};

	Node *front = malloc(sizeof(Node)); 
	Node *end = malloc(sizeof(Node)); 
	front -> next = end;
	front -> prev = NULL; 
	end -> next = NULL; 
	end -> prev = front; 


	insertNode(graph, 1, 2); 
	insertNode(graph, 1, 7); 
	insertNode(graph, 1, 10); 
	insertNode(graph, 2, 3);
	insertNode(graph, 2, 5);
	insertNode(graph, 3, 4);
	insertNode(graph, 5, 6);
	insertNode(graph, 7, 8);
	insertNode(graph, 7, 9);
	insertNode(graph, 10, 11);


	// for (int i = 1; i <= 11; i++) {
	// 	for (int j = 1; j <= 11; j++) {
	// 		printf("%d ", graph[i][j]);
	// 	}
	// 	printf("\n"); 
	// }

	if (BFSsearch(graph, front, end, 20)) {
		printf("Exists!!\n"); 
	} else {
		printf("Doesn't exist!!\n"); 
	}

	free(front);
	free(end); 

}