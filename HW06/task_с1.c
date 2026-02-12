#include <stdio.h>

int absolute(int num);

int main(void)
{
	int a;
	scanf("%d", &a);
	printf("%d", absolute(a));
	return 0;
}

int absolute(int num)
{
	return num >= 0 ? num : -num;
}
