#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
   int data;
   struct _node *next;
} node, *nodeP;

nodeP recursiveReverseList(nodeP first){
	if(first == NULL) return NULL;
	if(first->next == NULL) return first;

	nodeP rest = recursiveReverseList(first->next);
	// rest->next = first;
	first->next->next = first;
	
	first->next = NULL;

	// return first;
	return rest;
}

nodeP createNode(int val) {
	nodeP newNode = malloc(sizeof(node));
	newNode->data = val;
	return newNode;
}

void printList(nodeP head) {
	while (head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	nodeP head = createNode(1);
	head->next = createNode(2);
	head->next->next= createNode(3);
	head->next->next->next = createNode(4);

	printf("Elements in first list: ");
	printList(head);
	nodeP newHead = recursiveReverseList(head);
	printf("Elements in first list after reverse: ");
	printList(newHead);

	/* Now testing with an empty list */
	nodeP secondListHead = NULL;
	printf("Elements in second list: ");
	printList(secondListHead);
	nodeP newSecondListHead = recursiveReverseList(secondListHead);
	printf("Elements in second list after reverse: ");
	printList(newSecondListHead);
}