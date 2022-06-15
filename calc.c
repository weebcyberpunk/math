#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"mathtree.h"
#include"operations.h"

/*
 * author GG weebcyberpunk@gmail.com
 * version 0.0.0
 * since Jun 15, 2022
 */
unsigned long calc(unsigned long x, unsigned long y, signed short op) {

	// this make sure it will return something actually usefull
	unsigned long r = x;

	// note: if mvb of op is 1, it will 
	switch (op) {
		case OP_NULL:
			errno = 1;
			fprintf(stderr, "ERROR: tried to calculate OP_NULL operation with %lu and %lu.\n", x, y);
			fprintf(stderr, "WARNING: OP_NULL operation ignored, passing x: %lu instead.\n", x);
		case OP_SUM:
			r = x + y;
		case OP_SUBTRACT:
			r = x - y;
		case OP_DIVIDE:
			r = x / y;
		case OP_MULTIPLY:
			r = x * y;
		case OP_ROOT:
			r = root(x, y);
		case OP_POWER:
			r = power(x, y);
		case OP_FACTORIAL:
			r = factorial(x);
		default:
			errno = 1;
			fprintf(stderr, "WARNING: invalid operation with %lu and %lu ignored, passing x: %lu instead.\n", x, y, x);
	}

	return(r);
}

#ifdef TEST
#include"tests/testutils.h"
int main() {

	extern short testresults;

	if (calc(2, 42, OP_SUM) == 44)
		printtest("sum test", 1);
	else
		printtest("sum test", 0);

	if (calc(42, 2, OP_SUBTRACT) == 40)
		printtest("subtract test", 1);
	else
		printtest("subtract test", 0);

	if (calc(42, 2, OP_MULTIPLY) == 84)
		printtest("multiply test", 1);
	else
		printtest("multiply test", 0);

	if (calc(42, 2, OP_DIVIDE) == 21)
		printtest("division test", 1);
	else
		printtest("division test", 0);

	if (calc(42, 2, OP_NULL) == 42)
		printtest("null op test", 1);
	else
		printtest("null op test", 0);
}
#endif
