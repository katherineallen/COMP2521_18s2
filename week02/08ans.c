#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct _Node {
	int value;
	struct _Node *next;
} Node;

typedef Node *List;  // pointer to first Node

int sumOfListWhile(List list);
int sumOfListFor(List list);
int sumOfListRecursive(List list);

int main (int argc, char*argv[]){
	Node *head = malloc(sizeof(struct _Node));
	head -> value = 1;
	head -> next = malloc(sizeof(struct _Node));
	head -> next -> value = 3;
	head -> next -> next = malloc(sizeof(struct _Node));
	head -> next -> next -> value = 4;
	head -> next -> next -> next = NULL;

	assert(sumOfListWhile(head) == 8);
	assert(sumOfListFor(head) == 8);
	assert(sumOfListRecursive(head) == 8);
	printf("All tests passed. You are awesome!\n");

}

int sumOfListWhile(List list) {
	Node *curr = list;
	int sum = 0;

	while (curr != NULL) {
		sum += curr -> value;
		curr = curr -> next;
	}

	return sum;
}



int sumOfListFor(List list) {
	Node *curr;
	int sum = 0;

	for (curr = list; curr != NULL; curr = curr -> next) {
		sum += curr -> value;
	}

	return sum;
}



int sumOfListRecursive(List list) {

	if (list == NULL) {
		return 0;
	} else {
		return list->value + sumOfListRecursive(list->next);
	}

}