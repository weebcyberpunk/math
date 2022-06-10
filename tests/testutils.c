#include<stdio.h>

short testresults = 0;

int printtest(char *testname, short passed) {
	if (passed)
		printf("%s test: PASSED\n", testname);

	else {
		testresults = 1;
		printf("%s test: REPROVED\n", testname);
	}

	return(passed);
}
