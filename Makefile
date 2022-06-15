.PHONY : node

node : node.c math.h
	cc -D TEST node.c tests/testutils.c -o tests/bin/node
	./tests/bin/node
