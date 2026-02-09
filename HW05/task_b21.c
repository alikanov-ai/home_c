#include <stdio.h>

int main(void)
{
	char letter = ' ';
	for (scanf("%c", &letter); letter != '.'; scanf("%c", &letter))
	{
		if (letter >= 'A' && letter <= 'Z')
			letter += 0x20;
		printf("%c", letter);
	}
	return 0;
}
