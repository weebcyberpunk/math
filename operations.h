/*
 * adding more operations is easy: add them here
 */
#define OP_NULL      	0
#define OP_SUM      	1 
#define OP_SUBTRACT 	2 
#define OP_DIVIDE   	3 
#define OP_MULTIPLY 	4 
#define OP_ROOT     	5 
unsigned long root(unsigned long x, unsigned long y);
#define OP_POWER    	6 
unsigned long power(unsigned long x, unsigned long y);
#define OP_FACTORIAL	7 
unsigned long factorial(unsigned long x);
