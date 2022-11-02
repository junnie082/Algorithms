#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node *next;
	int number;
} Node;


void insertNode(Node graph[], int head, int to) {

	if (graph[head].next == NULL) {
		graph[head].next = malloc(sizeof(Node));
		graph[head].next -> number = head;
		graph[head].next -> next = NULL; 
	} 

	Node *newNode = malloc(sizeof(Node));
	newNode -> next = NULL;
	newNode -> number = to; 

	Node *curr = graph[head].next;
	while (curr -> next != NULL) {
		curr = curr -> next; 
	}
	curr -> next = newNode;
	
}


int BFSsearch(Node graph[], int num) {

	for (int head = 1; head <= 11; head++) {
		if (graph[head].next == NULL) continue; 

		Node *target;
		printf("--------------\n");


		while (graph[head].next != NULL) {
			printf("found %d\n", graph[head].next -> number); 
			target = graph[head].next; 
			if (target -> number == num) {
				return 1; 
			}
			if (target -> next == NULL) {
				graph[head].next = NULL; 
				free(target);
			} else if (target -> next != NULL) {
				graph[head].next = target -> next; 
				free(target); 
			}
		}
	}
	return 0; 
}

void deleteAllNodes(Node graph[]) {
		
	Node *curr;

	for (int i = 1; i <= 11; i++) {
		if (graph[i].next == NULL) continue; 

		curr = graph[i].next;

		if (curr -> next == NULL) {
			free(curr);
			graph[i].next = NULL; 
		} else {
			graph[i].next = curr -> next;
			free(curr); 
		}


	}
}


int main()
{
	Node *graph = malloc(sizeof(Node) * 12);

	for (int i = 1; i <= 11; i++) {
		graph[i].next = NULL;
		graph[i].number = i; 
	}

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
 
 	int exists;
	exists = BFSsearch(graph, 5);

	if (exists) {
		printf("Exists!!!\n");
	} else {
		printf("Doesn't exist!!!\n"); 
	}

	deleteAllNodes(graph);

	free(graph); 
}