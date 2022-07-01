vm-debug : mathvm.c mathvm.h stack.c stack.h
	cc -D DEBUG_VM mathvm.c stack.c -o vm-debug

tree-debug : ast.c mathvm.h ast.h
	cc -D DEBUG_TREE ast.c -o tree-debug

.PHONY : debug-vm debug-tree

debug-vm : vm-debug
	./vm-debug

debug-tree : tree-debug
	./tree-debug
