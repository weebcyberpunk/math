.PHONY : node calc eval

node : node.c
	cc -D TESTNODE node.c calc.c default_operations.c tests/testutils.c -o tests/bin/node
	./tests/bin/node

calc : calc.c
	cc -D TESTCALC calc.c default_operations.c tests/testutils.c -o tests/bin/calc
	./tests/bin/calc

eval : node.c calc.c default_operations.c
	cc -D TESTEVAL node.c calc.c default_operations.c tests/testutils.c -o tests/bin/eval
	./tests/bin/eval
