#include <stdio.h>

int main(void)
{
	unsigned int count, num1 = 0, num2 = 1, fib = 0;
	scanf("%d", &count);
	if (count < 1)
		return 0;
	else if(count < 2)
		printf("1");
	else
	{
		printf("%d ", num1 + num2);
		for (int i = 1; i <= count - 1; i++)
		{
			fib = num1 + num2;
			if (i == count - 1)
				printf("%d", fib);
			else
				printf("%d ", fib);
			num1 = num2;
			num2 = fib;
		}	
	}
	return 0;
}
