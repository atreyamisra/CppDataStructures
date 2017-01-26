#include "assignment-5_queue.h"
#include <stdlib.h>
#include <stdio.h>

/* Your queue implementations here */

Queue* initialize_q() {
	Queue *pointer = malloc(sizeof(Queue));
	pointer->size = 0;
	pointer->head = NULL;
	pointer->tail = NULL;
	return pointer;
}

void enqueue(Queue* my_Q, long elt) {
	Node_q *new_node = malloc(sizeof(Node_q));
	Node_q *old_tail;
	old_tail = my_Q->tail;
	if (my_Q->size == 0)
		my_Q->head = new_node;
	else
		old_tail->next = new_node;
	new_node->next = NULL;
	my_Q->tail = new_node;

	new_node->data = elt;
	my_Q->size++;
}

long dequeue(Queue* my_Q) {
	Node_q *old_head;
	double i;
	if (my_Q->head == NULL)
		return 0;
	old_head = my_Q->head;
	i = old_head->data;
	my_Q->head = old_head->next;
	free(old_head);
	my_Q->size--;
	return i;
}

void insert(Queue* my_Q, long elt, int index) {
	Node_q *old_node;
	Node_q *new_node = malloc(sizeof(Node_q));
	old_node = my_Q->head;
	if (index == my_Q->size) 
		enqueue(my_Q, elt);
	else {
		if (index == 0) {
			new_node->data = elt;
			new_node->next = my_Q->head;
			my_Q->head = new_node;
		}
		else {
			for (int i = 0; i < index; i++) {
				old_node = old_node->next;
			}
			new_node->data = elt;
			new_node->next = old_node;
			old_node = my_Q->head;
			for (int i = 1; i < index; i++) {
				old_node = old_node->next;
			}
			old_node->next = new_node;
		}
	}
}

void printQueue(Queue* my_Q) {
	Node_q *pointer;
	pointer = my_Q->head;
	int k = 1;
	if (my_Q->head == NULL)
		return;
	while (pointer != NULL) {
		if (k == 1)
			printf("%ld", pointer->data);
		else
			printf(", %ld", pointer->data);
		k++;
		pointer = pointer->next;
	}
	printf("\n");
	return;
}
