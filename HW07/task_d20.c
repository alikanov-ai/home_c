#include <stdio.h>

int recurs_power(int n, int p)
{
	static int res = 1;
	if (n == 0 || p < 0)
		return 0;
	if (p == 0)
		return res;
	res *= n;
	return recurs_power(n, p-1);
}

int main(void)
{
	int n, p;
	scanf("%d%d", &n, &p);
	printf("%d", recurs_power(n, p));
	return 0;
}
