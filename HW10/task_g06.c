#include <stdio.h>
#include <string.h>

int is_palindrom(char *str)
{
	if (str == NULL)
        return 0;
	int len = strlen(str);
	for (int i = 0; i < len / 2; i++)
		if (str[i] != str[len - i - 1])
			return 0;
	return 1;
}

int main(void)
{
	FILE *f;
	
	if ((f = fopen("input.txt", "r")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	char str[1001];
	if (fgets(str, sizeof(str), f) == NULL)
	{
		fclose(f);
		return 0;
	}
	fclose(f);
	
	str[strcspn(str, "\n")] = 0;// убираем перенос строки, если он есть
		
	if ((f = fopen("output.txt", "w")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
    fprintf(f, "%s", is_palindrom(str) ? "YES" : "NO");
	fclose(f);
	
	return 0;
}
