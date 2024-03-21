#include <stdio.h>
int main(void)
{
	int a = 5;
	int b;
	printf("Please input a positive integer number: \n");
	scanf("%d", &b);

	if ( a > b) {
		printf("a is larger than b\n");
	}
	else {
		printf("b is not less than a\n");
	}
	if (a == b) {
		printf("b equal a\n");
	}
	return 0;
}
