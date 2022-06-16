/*
 * adding more operations is easy: add them here
 */
#define OP_NULL      	(unsigned short) 0
#define OP_SUM      	(unsigned short) 1 
#define OP_SUBTRACT 	(unsigned short) 2 
#define OP_DIVIDE   	(unsigned short) 3 
#define OP_MULTIPLY 	(unsigned short) 4 
#define OP_ROOT     	(unsigned short) 5 
signed long root(signed long x, signed long y);
#define OP_POWER    	(unsigned short) 6 
signed long power(signed long x, signed long y);
#define OP_FACTORIAL	(unsigned short) 7 
signed long factorial(signed long x);
