#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"stack.h"
#include"mathvm.h"
#include"ast.h"

/*
 * author GG weebcyberpunk@gmail.com
 * version 0.0.0
 * since Jun 27, 2022
 */

// compiles the ast and returns an *text
signed long *compile(ASTNode *root) {

	signed long *text;

	return(text);
}

// parses the exp into an ast and returns a *ASTNode
ASTNode *parse(char *exp) {
	
	ASTNode *root = create_node(0, 0, NULL, NULL);

	return(root);
}

#ifdef DEBUG_PARSE
int tree_view(ASTNode *node, int pad);
int main() {
	ASTNode *root = parse("3*(20-5)/(2+1)");
	tree_view(root, 0);
	
	return(errno);
}
#endif
