#include <stdio.h>

int main(void)
{
	int n, a, b, c, max;
	scanf("%d", &n);
	n = n<0 ? -n : n;
	a = n%10;
	b = (n/10)%10;
	c = (n/100)%10;
	max = a>b ? a : b;
	max = max>c ? max : c;
	printf("%d\n", max);
	return 0;
}

