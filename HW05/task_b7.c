#include <stdio.h>

int main(void)
{
	int num, next_num;
	scanf("%d", &num);
	while (num > 0)
	{
		next_num = num / 10;
		while (next_num > 0)
		{
			if (num % 10 == next_num % 10)
			{
				printf("YES\n");
				return 0;
			}
			next_num /= 10;
		}
		num /= 10;
	}
	printf("NO\n");
	return 0;
}
