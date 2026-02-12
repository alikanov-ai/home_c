#include <stdio.h>

unsigned int calculationf(unsigned int num)
{
	unsigned int sum = 0;
	for (unsigned int i = 1; i <= num; i++)
		sum += i;
	return sum;
}

int main(void)
{
	unsigned int n = 0;
	scanf("%d", &n);
	printf("%d",calculationf(n));
	return 0;
}
