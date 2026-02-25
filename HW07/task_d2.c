#include <stdio.h>

int sumf(int num)
{
	return num > 0 ? num + sumf(num - 1) : num;
}

int main(void)
{
	int a;
	scanf("%d", &a);
	printf("%d", sumf(a));
	return 0;
}
