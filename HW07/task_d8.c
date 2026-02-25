#include <stdio.h>

void print_num(int a, int b)
{
	printf("%d ", a);
	if (a < b)
		print_num(a + 1, b);
	if (a > b)
		print_num(a - 1, b);
}

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	print_num(a, b);
	return 0;
}
