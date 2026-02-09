#include <stdio.h>

int main(void)
{
	int num, count = 0;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
			break;
		count++;
	}
	printf("%d\n", count);
	return 0;
}
