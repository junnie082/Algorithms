#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
	struct _Node *next; 
	int number; 

} Node;


void insertNode(Node graph[], int head, int to) {

	Node *newNode = malloc(sizeof(Node)); 
	newNode -> number = to; 
	newNode -> next = NULL;

	if (graph[head].next == NULL) {
		graph[head].next = newNode; 
	} else {
		Node *point = graph[head].next;
		while (point -> next != NULL) {
			point = point -> next; 
		}
		point -> next = newNode; 
	} 

	//printf("head: %d to: %d\n", head, graph[head].next -> number); 
}


void deleteNode(Node *graph, int head) {

	if (graph[head].next == NULL) {
		return; 
	}

	Node *target = graph[head].next;

	// 이 부분에 문제가 있는 것 같다!!!!
	// if (target -> next != NULL) {
	// 	graph[head].next = target -> next; 
	// 	//free(target);
	// } //else if (target -> next == NULL) {
	// // 	graph[head].next = NULL; 
	// }
	printf("target: %d\n", target->number); 
	if (target -> next == NULL) {
		free(target); 
		graph[head].next = NULL; 
	} else if (target -> next != NULL) {
		graph[head].next = target -> next;
		free(target); 
	}

}

int DFSsearch(Node *graph, int *stack, int search) {

	int size = 1, val = 1, head = 1;
	stack[0] = -1; 
	stack[size] = graph[head].number;



	// 이 코드를 추가하면 또 stack[1] = 0 이라고 뜨는데...
	// 도대체 뭐지?? 왜 이런 일들이 발생하는 걸까.
	// graph[6].next = NULL;

	// if (graph[6].next -> next == NULL) {
	// 	printf("NULLLLLLLL!\n"); 
	// }


	// 왜 graph[6]에 NULL 이 연결되어 있지 않을까? 
	do {

		//어디서부터 graph[6].next 가 NULL이 아니게 되는지를 보자. 
		// if (graph[11].next == NULL) {
		// 	printf("!11!\n");
		// }
		//어!!! 처음부터 NULL 이 아니라고 뜨는데?
		//함수에서는 분명이 NULL 이라고 했잖아...
		printf("head: %d ", head); 
		// 
		if (graph[head].next == NULL) {
			printf("head: %d, NULL!!\n", head); 
		}
			
		if (graph[head].next == NULL) {
			size--; 
			head = stack[size]; 
		}
		else if (graph[head].next != NULL) {
			size++; 
			// val 이 다음 노드의 값으로 바뀜.  
			val = graph[head].next -> number; 
			stack[size] = val;
 
			deleteNode(graph, head); 
			head = val; 
		}

		printf("----\n");
		for (int i = 1; i <= size; i++) {
			printf("stack[%d]: %d\n", i, stack[i]); 
		}
		printf("----\n");
		if (stack[size] == search) return 1; 

	} while (size > 0); 

	return 0; 
}



int main()
{
	int result; 
	//Node *graph = malloc(sizeof(Node *) * 12); 
	Node graph[13]; 
	int *stack = malloc(sizeof(int *) * 11); 

	for (int i = 1; i <= 11; i++) {
		graph[i].next = NULL; 
		graph[i].number = i; 
	}

	// insertNode(graph, 1, 2);
	// insertNode(graph, 1, 7); 
	// insertNode(graph, 1, 10); 
	// insertNode(graph, 2, 3);
	// insertNode(graph, 2, 5);
	// insertNode(graph, 3, 4); 
	// insertNode(graph, 5, 6); 
	// insertNode(graph, 7, 8); 
	// insertNode(graph, 10, 11);
	insertNode(graph, 1, 5); 
	insertNode(graph, 1, 4);
	insertNode(graph, 4, 7);
	insertNode(graph, 5, 6);
	insertNode(graph, 6, 8);
	insertNode(graph, 6, 9);


	// if (graph[6].next  == NULL) {
	// 	printf("NULLLLLLLL!\n"); 
	// }

	//구조체 배열에 NULL 이 연결 되어 있는지를 확인. 
	// for (int i = 1; i <= 11; i++) {
	// 	if (graph[i].next == NULL) {
	// 		printf("%d\n", i); 
	// 	}
	// }

	//여기까지는... graph[6]에 NULL 노드가 들어 있는데,
	//왜 DFSsearch 함수를 돌리면 NULL 이 아니라고 뜰까? 
	// if (graph[6].next == NULL) {
	// 	printf("NULL!\n");
	// }

	result = DFSsearch(graph, stack, 10); 
	printf("%d\n", result);

	//free(graph); 
	free(stack); 

}