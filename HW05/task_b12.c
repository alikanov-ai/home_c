#include <stdio.h>

int main(void)
{
	unsigned int num, min = 0, max = 0;
	scanf("%d", &num);
	min = num%10;
	max = num%10;
	while (num > 0)
	{
		min = num%10 < min ? num%10 : min;
		max = num%10 > max ? num%10 : max; 
		num /= 10;
	}
	printf("%d %d\n", min, max);
	return 0;
}
