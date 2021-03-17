#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LEN 1001

void handle(FILE *);
void get_first_word(char *);
void get_second_word(char *str);
char get_last_character(char *, int);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [file_name]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char temp[LEN] = {'\0'};
	FILE *fp;

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	handle(fp);
	fclose(fp);
	return 0;
}

void handle(FILE *fp)
{
	char space[LEN] = {'\0'};
	char str[LEN] = {'\0'};
	char fs[LEN] = {'\0'};
	char sd[LEN] = {'\0'};
	char source[LEN] = {'\0'};
	char el[LEN] = {'\0'};
	char lch = 0;

	while ((fgets(str, LEN, fp)) != NULL)
	{
		strcpy(source, str);
		int k = 0;
		int l1 = strlen(str);
		for (int i = 0, j = 0; i < l1; i++)
		{
			if (isspace(str[i]))
			{
				space[j] = str[i];
				j++;
			}
			else
			{
				space[j + 1] = '\0';
				break;
			}
		}

		for (int i = l1 - 1; i >= 0; i--)
		{
			if (str[i] == '{')
			{
				for (int j = i - 1; j >= 0; j--)
					if (str[j] == ')')
					{
						str[j + 1] = '\0';
						break;
					}
				break;
			}
		}

		strcpy(fs, str);
		get_first_word(fs);
		if (strcmp(fs, "while") == 0 || strcmp(fs, "if") == 0 || strcmp(fs, "for") == 0 || strcmp(fs, "switch") == 0 || strcmp(fs, "else") == 0)
		{
			if ((lch = get_last_character(source, strlen(source))) == '{')
			{
				printf("%s\n", str);
				printf("%s{\n", space);
				lch = 0;
			}
			else
				printf("%s", source);
		}
		else if (strcmp(fs, "}") == 0)
		{
			strcpy(sd, source);
			get_second_word(sd);
			if (strcmp(sd, "else") == 0)
			{
				for (int i = 0; isspace(*(str + i)) || *(str + i) == '}' || i < l1; i++);
					for (int i = 0; *(str + i) != '\n'; i++)
						el[i] = *(str + i);
				int l2 = strlen(el);
				for (int i = l2 - 1; i >= 0; i--)
				{
					if (el[i] == '{')
					{
						for (int j = i - 1; j >= 0; j--)
							if (!isspace(el[j]))
							{
								el[j + 1] = '\0';
								break;
							}
						break;
					}
				}
				for (k = 0; el[k] == '}' || isspace(el[k]); k++);
				printf("%s}\n", space);
				printf("%s%s\n",space, el + k);
				printf("%s{\n", space);
			}
			else
				printf("%s", str);
		}
		else
		{
			if (strcmp(source, "") == 0)
				printf("\n");
			printf("%s", source);
		}

		memset(space, 0, sizeof(space));
		memset(fs, 0, sizeof(fs));
		memset(sd, 0, sizeof(sd));
		memset(str, 0, sizeof(str));
		memset(source, 0, sizeof(source));
		memset(el, 0, sizeof(el));
	}
}

void get_first_word(char *str)
{
	int begin, end;
	int len = strlen(str);
	for (begin = 0; isspace(*(str + begin)) && begin < len; begin++);
	for (end = begin; !isspace(*(str + end)) && end < len; end++);
	*(str + end) = '\0';
	for (; *(str + begin) != '\0'; str++)
		*str = *(str + begin);
	*str = '\0';
}

void get_second_word(char *str)
{
	int begin =  0;
	int end = 0;
	int middle1 = 0;
	int middle2 = 0;
	int len = strlen(str);

	for (begin = 0; isspace(*(str + begin)) && begin < len; begin++);
	for (middle1 = begin; !isspace(*(str + middle1)) && middle1 < len;  middle1++);
	for (middle2 = middle1; isspace(*(str + middle2)) && middle2 < len; middle2++);
	for (end = middle2; !isspace(*(str + end)) && end < len; end++);
	*(str + end) = '\0';
	for (; *(str + middle2) != '\0'; str++)
		*str = *(str + middle2);
	*str = '\0';
}

char get_last_character(char *str, int len)
{
	char ch;

	for (int i = len - 1; i >= 0; i--)
	{
		if (!isspace(str[i]))
		{
			ch = str[i];
			break;
		}
	}
	return ch;
}
