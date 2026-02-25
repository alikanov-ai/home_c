#include <stdio.h>

int acounter(void)
{
	char c;
	static int sum = 0;
	c = getchar();
	if (c == '.')
		return sum;
	if (c == 'a')
		sum++;
	return acounter();
}

int main(void)
{
	printf("%d", acounter());
	return 0;
}
