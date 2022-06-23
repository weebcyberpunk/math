#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"mathvm.h"

/*
 * LICENSE {{{
 * Copyright 2022 © GG
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software and associated documentation files (the “Software”), to deal 
 * in the Software without restriction, including without limitation the rights to 
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies 
 * of the Software, and to permit persons to whom the Software is furnished to do 
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE 
 * SOFTWARE.
 * }}}
 */

/*
 * Stack-based machine to perform arithmetic operations
 */

// stack should only be touched by push() and pop() so it can increase properly
// easily, but NO WAY SOMEONE WILL NEED MORE THAN 1 FUCKING KILOBYTE
signed long *text;
signed long *ip;
signed long *stack;
signed long stack_size = STACK_INIT_SIZE;
signed long *dp;

/*
 * author GG weebcyberpunk@gmail.com
 * version 0.0.0
 * since Jun 22, 2022
 */

// pops something from stack. crashes the program if empty stack (for security
// reasons)
signed long pop() {

	signed long num = 0;
	if (dp >= stack) {
		num = *dp;
		dp--;
	} else {
		fprintf(stderr, "ERROR: Cannot pop from empty stack.\n");
		exit(EADDRNOTAVAIL);
	}

	return(num);
}

// pushes something to stack
int push(signed long num) {

	dp++;
	if ((dp - stack) > stack_size) {
		stack_size += STACK_INIT_SIZE;
		printf("stack size: %lu\n", stack_size);
		stack = realloc(stack, stack_size);
		dp = &stack[stack_size - STACK_INIT_SIZE + 1];
		printf("realloced\n");
	}
	*dp = num;

	return(errno);
}

int run() {
#ifdef DEBUG
	printf("REACHED RUN:\n");
	printf("text: %p\n", text);
	printf("ip: %p\n", ip);
	printf("stack: %p\n", stack);
	printf("dp: %p\n", dp);
	printf("\n");
#endif

	return(errno);
}

// inits the machine. text needs to be ONLY code, get rid of the file
// identificator before calling it.
int init(signed long *_text) {

	stack = (signed long*) malloc(STACK_INIT_SIZE * sizeof(signed long));

	if (stack == NULL) {
		int errv = errno;
		fprintf(stderr, "ERROR: Cannot init computation.\n");
		exit(errv);
	}

	dp = stack - 1;
	text = _text;
	ip = text;

	run();

	return(errno);
}

#ifdef DEBUG
int main() {
	// 2 . (20 - 5) / (2 + 1)
	signed long text[] = {
		'<', 2, '<', 20, '<', 5,
		'-',
		'*',
		'<', 2, '<', 1,
		'+',
		'/',
		EOF
	};
	init(text);
}
#endif
