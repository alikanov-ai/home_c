#include <stdio.h>

int main(void)
{
	FILE *f;
	if ((f = fopen("input.txt", "r")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	char ch, str[100];
	int count = 0;
	while (((ch = getc(f)) != EOF) && (ch != '\n'))
		str[count++] = ch;
	str[count] = '\0';
	fclose(f);
	
	if ((f = fopen("output.txt", "w")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	for (int i = 0; i < 3; i++)
	{
		if (i)
			fprintf(f, ", ");
		fprintf(f, "%s", str);
	}
	fprintf(f, " %d", count);
	fclose(f);
	return 0;
}
