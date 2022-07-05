#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"stack.h"
#include"mathvm.h"
#include"ast.h"

#define syntaxerr(msg) fprintf(stderr, "Syntax error: %s.\n", msg); exit(ENOTSUP);

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
	
	unsigned long brackets_lvl = 0;
	signed long pos = -1;
	ASTNode *root = NULL;
	
	char c;
	while ((c = exp[pos++]) != EOF) {

		if (c == '(') {
			brackets_lvl++;

		} else if (c == ')') {
			if (brackets_lvl > 0)
				brackets_lvl--;
			else
				syntaxerr("Closing bracket without opening one before");

		}
	}

	if (brackets_lvl > 0)
		syntaxerr("Unclosed brackets");

	if (root == NULL)
		syntaxerr("No operation at all");

	return(root);
}

#ifdef DEBUG_PARSE
int tree_view(ASTNode *node, int pad);
int main() {
	ASTNode *root = parse("2*(20-5)/(2+1)");
	tree_view(root, 0);
	
	return(errno);
}
#endif
