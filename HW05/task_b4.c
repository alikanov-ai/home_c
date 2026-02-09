#include <stdio.h>

int main(void)
{
	int num, count = 0;
	scanf("%d", &num);
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	if (count == 3)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

