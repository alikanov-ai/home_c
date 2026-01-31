#include <stdio.h>

int main(void)
{
	int n, sum;
	scanf("%d", &n);
	sum = n%10;
	sum += (n/10)%10;
	sum += (n/100)%10;
	printf("%d\n", sum);
	return 0;
}

