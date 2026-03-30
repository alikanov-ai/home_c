#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *f;
	
	if ((f = fopen("input.txt", "r")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	char str[10001];
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
	int len = strlen(str), countLower = 0, countUpper = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			countLower++;
		if (str[i] >= 'A' && str[i] <= 'Z')
			countUpper++;
	}
    fprintf(f, "%d %d", countLower, countUpper);
	fclose(f);
	
	return 0;
}
