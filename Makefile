vm-debug : mathvm.c mathvm.h stack.c stack.h
	cc -D DEBUG_VM mathvm.c stack.c -o vm-debug

.PHONY : debug-vm

debug-vm : vm-debug
	./vm-debug
