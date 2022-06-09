.PHONY : test-nodeopts

test-nodeopts : nodeopts.c
	cc -D TEST nodeopts.c tests/testutils.c -o tests/bin/nodeopts
	./tests/bin/nodeopts
