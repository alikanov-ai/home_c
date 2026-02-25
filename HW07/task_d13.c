#include <stdio.h>

void print_multipliers(int num, int divisor)
{
	if (num < 2 || divisor < 2)
		return;
	else
	{
		while (num > 1)
		{
			if (num%divisor != 0)
				divisor++;
			else
			{
				printf("%d ", divisor);
				print_multipliers(num/divisor, divisor);
				return;
			}
		}
	}
}

int main(void)
{
	int num;
	scanf("%d", &num);
	print_multipliers(num, 2);
	return 0;
}
