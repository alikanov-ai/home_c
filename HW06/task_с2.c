#include <stdio.h>

int power(int n, unsigned int p)
{
	int result = p == 0 ? 1 : (n == 0 ? 0 : n);
	for (unsigned int i = 1; i < p; i++)
		result *= n;
	return result;
}

int main(void)
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("%d", power(a, b));
	return 0;
}
