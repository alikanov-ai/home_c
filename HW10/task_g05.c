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
	char str[1001];
	if (fgets(str, sizeof(str), f) == NULL)
	{
		fclose(f);
		return 0;
	}
	fclose(f);
	
	if ((f = fopen("output.txt", "w")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
    for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == 'a' || str[i] == 'A')
			fprintf(f, "%c", str[i] + 1);
		else if (str[i] == 'b' || str[i] == 'B')
			fprintf(f, "%c", str[i] - 1);
		else
			fprintf(f, "%c", str[i]);
	fclose(f);
    
	return 0;
}
