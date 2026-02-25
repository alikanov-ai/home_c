#include <stdio.h>

int sum_digits(int n)
{
	static int sum = 0;
	if (n > 0)
	{
		sum += n%10;
		n /= 10;
		sum_digits(n);
	}
	return sum;
}

int main(void)
{
	int num;
	scanf("%d", &num);
	printf("%d", sum_digits(num));
	return 0;
}
