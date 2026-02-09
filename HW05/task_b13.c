#include <stdio.h>

int main(void)
{
	unsigned int num, count_even = 0, count_odd = 0;
	scanf("%d", &num);
	while (num > 0)
	{
		if ((num % 10) % 2 == 0)
			count_even++;
		else
			count_odd++;
		num /= 10;
	}
	printf("%d %d\n", count_even, count_odd);
	return 0;
}
