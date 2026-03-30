#include <stdio.h>

int main(void)
{
	FILE *f;
	if ((f = fopen("input.txt", "r")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	int pos, n = 0;
	fscanf(f, "%d", &n);
	char str_result[n + 2], ch = 'A', num = '2';
	for (pos = 0; pos < n; pos++)
	{
		if (pos%2 == 0)
			str_result[pos] = ch++;
		else
		{
			str_result[pos] = num;
			if (num == '8')
				num = '2';
			else
				num += 2;
		}
	}
	str_result[pos] = '\0';
	fclose(f);
	
	if ((f = fopen("output.txt", "w")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	fprintf(f, "%s", str_result);
	fclose(f);
	return 0;
}
