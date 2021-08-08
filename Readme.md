**C language code style transfer tools**


# How to compile:

```
[root@gg:/git/clcstt]# ls
a2kr.c  kr2a.c  Makefile  TheSampleCode.c
[root@gg:/git/clcstt]# make
gcc a2kr.c -o a2kr
gcc kr2a.c -o kr2a
[root@gg:/git/clcstt]# ls
a2kr  a2kr.c  kr2a  kr2a.c  Makefile  TheSampleCode.c
[root@gg:/git/clcstt]# kr2a TheSampleCode.c

==slide over==
```

# kr2a can transform C Language code of K&R style to Allman style.


## TheSampleCode.c
### From:

```
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
```

### To:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [string]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (strcmp("woaini", argv[1]) == 0)
			printf("foo\n");
		else
			printf("bar\n");
	}
	return 0;
}
```

# a2kr can transform C Language code of Allman style to  K&R style.

### From:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [string]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (strcmp("woaini", argv[1]) == 0)
			printf("foo\n");
		else
			printf("bar\n");
	}
	return 0;
}
```

### To:

```
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
```
