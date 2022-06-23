math-debug : mathvm.c mathvm.h
	cc -D DEBUG mathvm.c -o math-debug

.PHONY : debug

debug : math-debug
	./math-debug
