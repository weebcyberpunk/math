CFLAGS = -pedantic -Wall

vm-debug : mathvm.c mathvm.h stack.c stack.h
	$(CC) $(CFLAGS) -D DEBUG_VM mathvm.c stack.c -o vm-debug

tree-debug : ast.c mathvm.h ast.h
	$(CC) $(CFLAGS) -D DEBUG_TREE ast.c -o tree-debug

parse-debug : compile.c compiler.h ast.c ast.h
	$(CC) $(CFLAGS) -D DEBUG_PARSE compile.c ast.c -o parse-debug

.PHONY : debug-vm debug-tree debug-parse

debug-vm : vm-debug
	./vm-debug

debug-tree : tree-debug
	./tree-debug

debug-parse : parse-debug
	./parse-debug
