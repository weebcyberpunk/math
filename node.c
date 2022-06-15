#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include"math.h"

/*
 * author GG weebcyberpunk@gmail.com
 * version 0.0.0
 * since Jun 09, 2022
 */
MathNode *create_node(MathNode *x, MathNode *y, signed short operation) {

	MathNode *new_node = (MathNode*) malloc(sizeof(MathNode));

	new_node->x = x;
	new_node->y = y;
	new_node->operation_info = operation;

	return(new_node);
}

MathNode *create_leaf(signed long num) {

	MathNode *new_node = (MathNode*) malloc(sizeof(MathNode));
	new_node->result = num;
	new_node->x = NULL;
	new_node->y = NULL;
	new_node->operation_info = OP_NULL;

	return(new_node);
}

#ifdef TEST
#include"tests/testutils.h"
int main() {
	MathNode *new_node = create_node(create_leaf(2), create_leaf(42), OP_SUM);

	extern short testresults;

	if ((new_node->x->result == 2) && (new_node->y->result == 42))
		printtest("leaf", 1);
	else
		printtest("leaf", 0);

	if (new_node->operation_info == OP_SUM)
		printtest("new node", 1);
	else
		printtest("new node", 0);

	return(testresults);
}
#endif
