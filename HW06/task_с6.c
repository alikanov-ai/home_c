#include <stdio.h>

unsigned long long calcf(unsigned int num)
{
	unsigned long long res = 0;
	if (num > 0)
	{
		res = 1;
		for (unsigned int i = 1; i <= num; i++)
			res *= i > 1 ? 2 : 1;
	}
	return res;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%llu",calcf(n));
	return 0;
}
