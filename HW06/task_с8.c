#include <stdio.h>

char upperf(char letter)
{
	return letter >= 'a' && letter <= 'z' ? letter - 0x20 : letter;
}

int main(void)
{
	char letter;
	while ((letter = getchar()) != '.')
		putchar(upperf(letter));
	return 0;
}
