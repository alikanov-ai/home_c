#include <stdio.h>

void print_num(int num)
{
	if (num > 1)
		print_num(num - 1);
	printf("%d ", num);
}

int main(void)
{
	int a;
	scanf("%d", &a);
	print_num(a);
	return 0;
}
