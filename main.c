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
char *text;
char *ip;
signed long *stack;
signed long stack_size = STACK_INIT_SIZE;
signed long *dp;

/*
 * author GG weebcyberpunk@gmail.com
 * version 0.0.0
 * since Jun 22, 2022
 */

// pops something from stack
signed long pop() {

	signed long num = *dp;
	dp--;

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

// inits the machine
int init() {
	stack = (signed long*) malloc(STACK_INIT_SIZE * sizeof(signed long));
	dp = stack - 1;

	return(errno);
}

// run the compiled program if the file starts with the file indicator, or call
// the compiler to compile it and return a text pointer
int main(int argv, char *argc[]) {

	init();

	return(errno);
}
