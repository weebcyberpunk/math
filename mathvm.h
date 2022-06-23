#define STACK_INIT_SIZE 	0x80
#define FILE_INDICATOR_UINT  	0x4D415448 // ascii for math

// machine instructions
#define $ADD 	'+'
#define $SUB 	'-'
#define $MUL 	'*'
#define $DIV 	'/'
#define $PUSH 	'<'
#define $EXIT 	EOF

int init(signed long *text);
