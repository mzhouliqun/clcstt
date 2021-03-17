#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LEN 1001

void handle(FILE *);
void get_first_word(char *);
void get_second_word(char *str);
char get_last_character(char *, int);
void replace_lf(char *str);
void bp(void);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s [file_name]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

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
	char str2[LEN] = {'\0'};
	char str3[LEN] = {'\0'};
	char fs[LEN] = {'\0'};
	char sd[LEN] = {'\0'};
	char th[LEN] = {'\0'};

	while (fgets(str, LEN, fp) != NULL)
	{
		int index = 0;

		memset(fs, 0, sizeof(fs));
		strcpy(fs, str);
		get_first_word(fs);
		if (strcmp(fs, "while") == 0 || strcmp(fs, "if") == 0 || strcmp(fs, "for") == 0 || strcmp(fs, "switch") == 0 || strcmp(fs, "else") == 0)
		{
			if (get_last_character(str, (int)strlen(str)) == ')')
			{
				memset(str2, 0, sizeof(str2));
				if (fgets(str2, LEN, fp) != NULL)
				{
					memset(fs, 0, sizeof(fs));
					strcpy(fs, str2);
					get_first_word(fs);
					if (strcmp(fs, "{") == 0)
					{
						int i2;
						replace_lf(str);
						printf("%s", str);
						for (i2 = 0; isspace(str2[i2]); i2++);
						printf("%s", str2 + i2);
						continue;
					}
					else
						fseek(fp, -1 * (long)strlen(str2), SEEK_CUR);
				}
				else
				{
					fprintf(stderr, "Error reading file!\n");
					exit(EXIT_FAILURE);
				}
			}
		}
		else if (strcmp(fs, "}") == 0)
		{
			int i, j, k, l;
			memset(sd, 0, sizeof(sd));
			strcpy(sd, str);
			get_second_word(sd);
			if (strcmp(sd, "") == 0)
			{
				memset(str2, 0, sizeof(str2));
				if (fgets(str2, LEN, fp) != NULL)
				{
					memset(fs, 0, sizeof(fs));
					strcpy(fs, str2);
					get_first_word(fs);
					if (strcmp(fs, "else") == 0 && get_last_character(str2, (int)strlen(str2)) != '{')
					{
						memset(str3, 0, sizeof(str3));
						if (fgets(str3, LEN, fp) != NULL)
						{
							memset(fs, 0, sizeof(fs));
							strcpy(fs, str3);
							get_first_word(fs);
							if (strcmp(fs, "{") == 0)
							{
								for (i = 0; i >= 0; i++)
								{
									if (str[i] == '}')
										break;
								}
								str[i + 1] = ' ';
								str[i + 2] = '\0';
								for (j = 0; j < strlen(str2); j++)
								{
									if (!isspace(str2[j]))
										break;
								}
								for (k = strlen(str2); k >= 0; k--)
								{
									if (str2[k] == '\n')
										break;
								}
								str2[k] = ' ';
								str2[k + 1] = '\0';
								for (l = 0; l < strlen(str3); l++)
								{
									if (!isspace(str3[l]))
										break;
								}
								printf("%s", str);
								printf("%s", str2 + j);
								printf("%s", str3 + l);
								continue;
							}
							else
							{
								printf("%s", str);
								printf("%s", str2);
								fseek(fp, -1 * (long)strlen(str3), SEEK_CUR);
								continue;
							}
						}
					}
					else
					{
						printf("%s", str);
						fseek(fp, -1 * (long)strlen(str2), SEEK_CUR);
						continue;
					}
				}
			}
		}
		printf("%s", str);
		memset(str, 0, sizeof(str));
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
	char ch = 0;

	for (int i = len; i >= 0; i--)
	{
		if (!isspace(str[i]) && str[i] != '\0' && str[i] != '\n')
		{
			ch = str[i];
			break;
		}
	}
	return ch;
}

void replace_lf(char *str)
{
	int len = (int)strlen(str);

	if (len > 0)
	{
		for (int i = len - 1; i >= 0; i--)
		{
			if (str[i] == '\n')
			{
				str[i] = ' ';
				str[i + 1] = '\0';
				break;
			}
		}
	}
}
