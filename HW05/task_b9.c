#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	while (num > 0)
	{
		if ((num % 10) % 2 != 0)
		{
			printf("NO\n");
			return 0;
		}
		num /= 10;
	}
	printf("YES\n");
	return 0;
}
