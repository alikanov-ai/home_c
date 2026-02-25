#include <stdio.h>

void print_binary(int num)
{
	if (num > 1)
		print_binary(num/2);
	printf("%d", num%2);
}

int main(void)
{
	int a;
	scanf("%d", &a);
	print_binary(a);
	return 0;
}
