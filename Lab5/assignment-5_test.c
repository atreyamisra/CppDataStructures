
#include "assignment-5_calculator.h"
#include "assignment-5_logMgr.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void logMgr_tests();
void calculator_tests();
void stack_tests();
void queue_tests();

int main() {
	calculator_tests();
	logMgr_tests();
	stack_tests();
	queue_tests();
	return 0;
}

void queue_tests() {
	Queue *testQueue = initialize_q();
	enqueue(testQueue, 1);
	enqueue(testQueue, 2);
	enqueue(testQueue, 4);
	insert(testQueue, 5, 3);
	printQueue(testQueue);
	getchar();
}


void stack_tests() {
	Stack *testStack = initialize_stk();
	push(testStack, 10);
	double x = peek(testStack);
	printf("%lf", x);
	printf("SHOULD BE 10\n");
	push(testStack, 20);
	x = pop(testStack);
	printf("%lf\n", x);
	push(testStack, 20.5);
	push(testStack, 1.4);
	push(testStack, 5);
	push(testStack, 90);
	printStack(testStack);
	printf("SHOULD BE 10, 20.5, 1.4, 5, 90 ");
	int position = search(testStack, 2);
	printf("%d should be 0 ", position);

}

void calculator_tests() {
    char expr1[][MAX_EXPR_LENGTH] = {"2", "2", "+"};
    char expr2[][MAX_EXPR_LENGTH] = {"2", "2", "+", "3", "*"};
	char expr3[][MAX_EXPR_LENGTH] = {"4.876555", "7", "3", "+", "*"};
	
	printf("expr1 = %lf \n", eval( expr1, sizeof(expr1)/sizeof(expr1[0]) ) );
    	assert( eval( expr1, sizeof(expr1)/sizeof(expr1[0]) ) == 4 );
	
	printf("expr2 = %lf \n", eval( expr2, sizeof(expr2)/sizeof(expr2[0]) ) );
    	assert( eval( expr2, sizeof(expr2)/sizeof(expr2[0]) ) == 12 );

	printf("expr3 = %lf \n", eval( expr3, sizeof(expr3)/sizeof(expr3[0]) ) );
    	assert( eval( expr3, sizeof(expr3)/sizeof(expr3[0]) ) == 48.76555 );
    
	printf("All tests passed successfully :-) \n");
}


#define WINDOW_SIZE 2

void logMgr_tests() {
    log_manager *log = createLogMgr( WINDOW_SIZE );
    assert( add_to_log( log, 1 ) == 1 );
    assert( add_to_log( log, 2 ) == 2 );
    assert( add_to_log( log, 3 ) == 3 );
    assert( add_to_log( log, 4 ) == 3 );
    assert( add_to_log( log, 4 ) == 4 );
    assert( add_to_log( log, 10 ) == 1 );
    
	printf("All tests passed successfully :-) \n");
	getchar();
}