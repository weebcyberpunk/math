#include<stdio.h>

int printtest(char *testname, short passed) {
	if (passed)
		printf("%s test: \033[32m PASSED\033[m\n", testname);

	else
		printf("%s test: \033[31m REPROVED\033[m\n", testname);

	return(passed);
}
