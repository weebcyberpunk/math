.PHONY : nodeopts

nodeopts : nodeopts.c
	cc -D TEST nodeopts.c tests/testutils.c -o tests/bin/nodeopts
	./tests/bin/nodeopts
