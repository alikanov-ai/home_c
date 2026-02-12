#include <stdio.h>

unsigned int calcf(unsigned int n, unsigned int p)
{
	unsigned int res = 0, digit = 1;
	while (n > 0)
	{
		res += (n % p) * digit;
		n /= p;
		digit *= 10;
	}
	return res;
}

int main(void)
{
	unsigned int n, p;
	scanf("%d%d", &n, &p);
	printf("%d",calcf(n, p));
	return 0;
}
