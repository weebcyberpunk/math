#define EVALUATED	128
/*
 * the tree is constructed pointing the operands of an operation to the result
 * of another
 *
 * to store if the result was evaluated, we see the mvb of operation_info and we
 * still have 127 possible operations
 *
 * a root node is a node without parent
 *
 * leafs and nodes that were already evaluated are the same thing, but the
 * parser need to initialize the leafs with the mvb from operation_info setted
 */
typedef struct MathNode {
	struct MathNode *x;
	struct MathNode *y;
	signed long result;
	signed short operation_info;
} MathNode;

MathNode *create_node(MathNode *x, MathNode *y, signed short operation);
MathNode *create_leaf(signed long result);
int evaluate(MathNode *node);
unsigned long calc(unsigned long x, unsigned long y, signed short op);
