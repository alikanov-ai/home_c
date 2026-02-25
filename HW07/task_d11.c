#include <stdio.h>

int count_one(int num)
{
	static int sum = 0;
	if (num > 1)
		count_one(num/2);
	if (num%2 == 1)
		sum++;
	return sum;
}

int main(void)
{
	int num;
	scanf("%d", &num);
	printf("%d", count_one(num));
	return 0;
}
