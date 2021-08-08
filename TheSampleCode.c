#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s [string]\n", argv[0]);
		exit(EXIT_FAILURE);
	} else {
		if (strcmp("woaini", argv[1]) == 0)
			printf("foo\n");
		else
			printf("bar\n");
	}
	return 0;
}
