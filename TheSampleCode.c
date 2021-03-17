#include <stdio.h>
#include <string.h>
int
main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s [string]\n", argv[0]);
	} else {
		if (strcmp("aini", argv[1]) == 0)
			printf("foo\n");
		else
			printf("bar\n");
	}
	return 0;
}
