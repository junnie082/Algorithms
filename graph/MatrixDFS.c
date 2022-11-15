#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node *next;
	int number;
} Node; 

// 이 부분은 조금 수정할 필요가 있어 보여.
// 대칭인 위치에 있는 원소를 0으로 바꾸어야 할까 말까?
void insertNode(int graph[][12], int from, int to) {
	if (graph[to][from] == 0){
		graph[from][to] = 1; 
	}
	//graph[to][from] = 0; 
}

void insertStack(Node *top, int number) {
	Node *newNode = malloc(sizeof(Node)); 
	newNode -> number = number; 

	newNode -> next = top -> next; 
	top -> next = newNode; 
}

void deleteStack(Node *top) {
	Node *target = top -> next; 

	top -> next = target -> next; 
	free(target); 
}

int DFSsearch(int graph[][12], Node *top, Node *bottom, int find) {
	insertStack(top, 1); 
	int i, flag;

	while (top -> next != bottom) {
		flag = 1;
		i = top -> next -> number; 
		if (i == find) return 1; 

		for (int j = 1; j <= 11; j++) {
			if (graph[i][j] == 1) {
				insertStack(top, j); 
				flag = 0; 
				graph[i][j] = 0; 
				break;
			}
		}

		// insert 된 적이 한 번도 없으면 deleteNode.
		if (flag) {
			deleteStack(top); 
		} 

		Node *curr = top -> next;
		printf("========\n");
		while (curr != bottom) {
			printf("stack %d\n", curr -> number); 
			curr = curr -> next; 
		}
		printf("========\n"); 
	}
	return 0; 
}

int main()
{
	int graph[12][12] = {0}; 
	Node *top = malloc(sizeof(Node)); 
	Node *bottom = malloc(sizeof(Node)); 
	top -> next = bottom; 
	bottom -> next = NULL; 

	insertNode(graph, 1, 2); 
	insertNode(graph, 1, 7);
	insertNode(graph, 1, 10);
	insertNode(graph, 2, 1);
	insertNode(graph, 2, 3);
	insertNode(graph, 2, 5);
	insertNode(graph, 3, 4);
	insertNode(graph, 5, 6);
	insertNode(graph, 7, 1); 
	insertNode(graph, 7, 8);
	insertNode(graph, 7, 9);
	insertNode(graph, 10, 11);

	if(DFSsearch(graph, top, bottom, 11)) {
		printf("Exists!!!\n"); 
	} else {
		printf("Doesn't exist!!!\n"); 
	}

	free(top); free(bottom); 
}