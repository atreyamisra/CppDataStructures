#include "assignment-5_stack.h"
#include <stdlib.h>
#include <stdio.h>

/* Your stack implementations here */

Stack* initialize_stk() {
	Stack *pointer = malloc(sizeof(Stack));
	pointer->size = 0;
	pointer->top = NULL;
	return pointer;
}

int size(Stack* stk) {
	int j = 0;
	Node_s *pointer = malloc(sizeof(Node_s));
	while (pointer->next != NULL) {
		j++;
		pointer=pointer->next;
	}
	return j;
}

void push(Stack* stk, double data) {
	Node_s *new_node = malloc(sizeof(Node_s));
	new_node->data = data;
	new_node->next = stk->top;
	stk->top = new_node;
}

double pop(Stack* stk) {
	Node_s *old_top;
	double i;
	if (stk->top == NULL)
		return 0;
	old_top = stk->top;
	i = old_top->data;
	stk->top = old_top->next;
	free(old_top);
	return i;
}

double peek(Stack* stk) {
	Node_s *peeker;
	double i;
	peeker = stk->top;
	i = peeker->data;
	return i;
}

int search(Stack* stk, double data) {
	Node_s *pointer = malloc(sizeof(Node_s));
	pointer = stk->top;
	if (stk->top == NULL)
		return 0;
	while (pointer != NULL) {
		if (pointer->data == data)
			return pointer;
		pointer = pointer->next;
	}
	return 0;
}

void printStack(Stack* stk) {
	Node_s *pointer = malloc(sizeof(Node_s));
	pointer = stk->top;
	int k = 1;
	if (stk->top == NULL)
		return;
	while (pointer != NULL) {
		if (k == 1)
			printf("%lf", pointer->data);
		else
			printf(", %lf", pointer->data);
		k++;
		pointer = pointer->next;
	}
	printf("\n");
	return;
}