#include <stdio.h>

int main(void)
{
	unsigned int num, curent_num, curent_sum, current_multiply;
	bool first = 1;
	scanf("%d", &num);
	for (int i = 10; i <= num; i++)
	{
		curent_num = i;
		curent_sum = 0;
		current_multiply = 1;
		while (curent_num > 0)
		{
			curent_sum += curent_num%10;
			current_multiply *= curent_num%10;
			curent_num /=10;
		}
		if (curent_sum == current_multiply)
		{
			if (first)
			{
				printf("%d", i);
				first = 0;
			}	
			else
				printf(" %d", i);
		}
	}
	return 0;
}
