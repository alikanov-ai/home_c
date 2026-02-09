#include <stdio.h>

int main(void)
{
	int num, rev = 0;
	scanf("%d", &num);
	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	printf("%d\n", rev);
	return 0;
}
