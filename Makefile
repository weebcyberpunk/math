.PHONY : node calc

node : node.c
	cc -D TEST node.c calc.c default_operations.c tests/testutils.c -o tests/bin/node
	./tests/bin/node

calc : calc.c
	cc -D TEST calc.c default_operations.c tests/testutils.c -o tests/bin/calc
	./tests/bin/calc
