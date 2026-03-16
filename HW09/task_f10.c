#include <stdio.h>

void PrintCharCount(char s[], int len)		
{
	if (len > 0)
	{
		int pos = 0, prev = 0;
		char curr_char = s[0];
		for (int i = 0; i < len; i++)
		{
			if (s[i] != curr_char)
			{
				printf("%c", curr_char);
				printf("%d", i - prev);
				pos++;
				curr_char = s[i];
				prev = i;
			}
			if (i == len - 1)
			{
				printf("%c", curr_char);
				printf("%d", i - prev + 1);
			}
		}
	}
	printf("\n");
}

int main(void)
{
	char s[1000], c;
	int i = 0;
	while ((c = getchar()) != '.')
		s[i++] = c;
	s[i] = '\0';
	PrintCharCount(s, i);
	return 0;
}
