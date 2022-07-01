typedef struct ASTNode {
	struct ASTNode *left;
	struct ASTNode *right;
	signed long num;
	signed long operation;
} ASTNode;

ASTNode *create_node(signed long operation, signed long num, ASTNode *left, ASTNode *right);
int discard_tree(ASTNode *node);
