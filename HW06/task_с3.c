#include <stdio.h>

int middle(int a, int b)
{
	return (a + b)/2;
}

int main(void)
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("%d", middle(a, b));
	return 0;
}
