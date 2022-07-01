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

// parses the expression into an ast and them calls compiler function to compile
// it into an *text
//
// returns the *text
signed long *parse(char *exp) {
	
	ASTNode *root = create_node(0, 0);

	return(compile(root));
}

#ifdef DEBUG_PARSE
int main() {
	parse("2*(20-5)/(2+1)");
}
#endif
