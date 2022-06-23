math-debug : main.c mathvm.h
	cc -D DEBUG main.c -o math-debug

.PHONY : debug

debug : math-debug
	./math-debug
