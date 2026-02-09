#include <stdio.h>

int main(void)
{
	unsigned int num, min = 0, max = 0, a = 0, b = 0;
	scanf("%d", &num);
	while (num / 10 > 0)
	{
		a = num % 10;
		b = (num / 10) % 10;
		max = a > b && a > max ? a : (b > max ? b : max);
		if (min == 0)
			min = a == max ? b : a;
		else
			min = a < b && a < min ? a : (b < min ? b : min);
		num /= 10;
	}
	printf("%d %d\n", min, max);
	return 0;
}
