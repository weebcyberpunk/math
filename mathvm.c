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

#ifdef DEBUG
int stack_dump() {

	for (signed long *pt = stack; pt <= dp; pt++)
		printf("%lu ", *pt);

	printf("\n");

	return(errno);
}
#endif

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
		stack = realloc(stack, stack_size);

		if (stack == NULL) {
			int errv = errno;
			fprintf(stderr, "ERROR: cannot increase stack\n");
			exit(errv);
		}

		dp = &stack[stack_size - STACK_INIT_SIZE + 1];
	}
	*dp = num;

	return(errno);
}

signed long run() {
#ifdef DEBUG
	printf("REACHED RUN:\n");
	printf("text: %p\n", text);
	printf("ip: %p\n", ip);
	printf("stack: %p\n", stack);
	printf("dp: %p\n", dp);
	printf("\n");
#endif

	signed long x, y;
	while (*ip != $EXIT) {
		switch (*ip) {
			case $ADD:
				x = pop();
				y = pop();
				push(y + x);
#ifdef DEBUG
				printf("Pushing on sum: %lu\n", x + y);
				stack_dump();
#endif
				break;
			case $SUB:
				x = pop();
				y = pop();
				push(y - x);
#ifdef DEBUG
				printf("Pushing on sub: %lu\n", y - x);
				stack_dump();
#endif
				break;
			case $MUL:
				x = pop();
				y = pop();
				push(y * x);
#ifdef DEBUG
				printf("Pushing on mul: %lu\n", y * x);
				stack_dump();
#endif
				break;
			case $DIV:
				x = pop();
				y = pop();
				push(y / x);
#ifdef DEBUG
				printf("Pushing on div: %lu\n", y / x);
				stack_dump();
#endif
				break;
			case $PUSH:
				ip++;
				push(*ip);
#ifdef DEBUG
				printf("Pushing: %lu\n", *ip);
				stack_dump();
#endif
				break;
			default:
				fprintf(stderr, "ERROR: Invalid instruction %lux\n", *ip);
				exit(ENOTSUP);
		}

		ip++;
	}

	return(*dp);
}

// inits the machine. text needs to be ONLY code, get rid of the file
// identificator before calling it.
signed long init(signed long *_text) {

	stack = (signed long*) malloc(STACK_INIT_SIZE * sizeof(signed long));

	if (stack == NULL) {
		int errv = errno;
		fprintf(stderr, "ERROR: Cannot init computation.\n");
		exit(errv);
	}

	dp = stack - 1;
	text = _text;
	ip = text;

	return(run());
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
	printf("%lu\n", init(text));
}
#endif
