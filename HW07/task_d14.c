#include <stdio.h>

void print_odd(void)
{
	int input;
	scanf("%d", &input);
	if (input == 0)
		return;
	if (input%2 != 0)
		printf("%d ", input);
	print_odd();
}

int main(void)
{
	print_odd();
	return 0;
}
