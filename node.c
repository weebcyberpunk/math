#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include"mathtree.h"
#include"operations.h"

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
	new_node->operation_info = OP_NULL | EVALUATED;

	return(new_node);
}

/*
 * to evaluate theese shit we recursively searches the tree, evaluating each
 * node alone
 */
int evaluate(MathNode *node) {

	if (node->x != NULL) {
		evaluate(node->x);

	} 
	if (node->y != NULL) {
		evaluate(node->y);

	}

	/*
	 * to work we MUST be CERTAIN that evaluate() ensures a valid number
	 * exists at *node->x->result and *node->y->result
	 */
	if (node->operation_info & EVALUATED)
		return(errno);

	printf("opinfo is not eval: %x\n", node->operation_info);

	node->result = calc(
			node->x->result, 
			node->y->result,
			node->operation_info
			);

	node->operation_info = node->operation_info | EVALUATED;

	return(errno);
}

#ifdef TESTNODE
#include"tests/testutils.h"
int main() {
	MathNode *new_node = create_node(create_leaf(2), create_leaf(42), OP_SUM);

	extern short testresults;

	if ((new_node->x->result == 2) && (new_node->y->result == 42) && (new_node->y->operation_info & EVALUATED))
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

#ifdef TESTEVAL
#include"tests/testutils.h"
int main() {
	extern short testresults;

	printf("%x\n", EVALUATED);

	MathNode *singlenode = create_leaf(42);
	evaluate(singlenode);
	if (singlenode->result == 42)
		printtest("single eval", 1);
	else
		printtest("single eval", 0);

	MathNode *doublenode = create_node(create_leaf(2), create_leaf(42), OP_SUM);
	evaluate(doublenode);
	if (doublenode->result == 44)
		printtest("double eval", 1);
	else
		printtest("double eval", 0);

	// x is 2 + 8
	MathNode *x = create_node(create_leaf(2), create_leaf(8), OP_SUM);
	// y is 42 - 2
	MathNode *y = create_node(create_leaf(42), create_leaf(2), OP_SUBTRACT);
	// the expression is (2 + 8)(42 - 2) so 400
	MathNode *root = create_node(x, y, OP_MULTIPLY);
	evaluate(root);
	if (root->result == 400)
		printtest("complex eval", 1);
	else
		printtest("complex eval", 0);

	return(testresults);
}
#endif
