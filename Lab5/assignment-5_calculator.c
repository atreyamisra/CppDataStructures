#include "assignment-5_calculator.h"
#include <stdlib.h>
#include <stdio.h>

// code for eval should allocate an operand_stack (declared in assignment-5_calculator.h)
// and push operands into the stack, and pop arguments when operator is encountered
// e.g. 2 2 + 3 *
// [] -> [2] -> [2,2] -> [2] - > [] -> [4] -> [4,3] -> [4] -> [] -> [7]
// return the last value in the stack
// if size > 1 when done, assert an error


double eval( char expr[][MAX_EXPR_LENGTH], int N ) {
	Stack *calcStack = initialize_stk();
	double num1=0.0, result=0.0;
	int i = 0, x = 0;
	while (x != -1) {
		if (*expr[i] != '+' && *expr[i] != '-' && *expr[i] != '*' && *expr[i] != '/')
			push(calcStack, atof(expr[i]));
		else
			x = -1;
		i++;
	}
	result = pop(calcStack);
	i--;
	for (i; i < N; i++) {
		num1 = pop(calcStack);
		if (*expr[i] == '+')
			result = num1 + result;
		else {
			if (*expr[i] == '-')
				result = result - num1;
			else {
				if (*expr[i] == '*')
					result = num1 * result;
				else {
					if (*expr[i] == '/')
						result = result / num1;
					else
						push(calcStack, atof(expr[i]));
					}
				}
			}
	}
	return result;

}
