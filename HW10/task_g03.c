#include <stdio.h>

int main(void)
{
	FILE *f;
	if ((f = fopen("input.txt", "r")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	char ch, str[1000];
	int count = 0;
	while (((ch = getc(f)) != EOF) && (ch != '\n'))
		str[count++] = ch;
	str[count] = '\0';
	fclose(f);
	
	if (count)
	{
		if ((f = fopen("output.txt", "w")) == NULL)
		{
			perror("File opening error");
			return 1;
		}
		for (int i = 0; i < count - 1; i++)
			if (str[i] == str[count - 1])
				fprintf(f, "%d ", i);
		fclose(f);
	}
	return 0;
}
