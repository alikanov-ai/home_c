#include <stdio.h>

int main(void)
{
	int num, count = 0;
	scanf("%d", &num);
	while (num > 0)
	{
		if (num % 10 == 9)
			count++;
		num /= 10;
	}
	if (count == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
