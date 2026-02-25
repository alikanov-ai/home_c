#include <stdio.h>

void print_num(int k, int iter)
{
	if (k < 1 || iter < 1)
		printf("0 ");
	else
	{
		for (int i = 1; i <= iter; i++)
		{
			printf("%d ", iter);
			k--;
			if (k == 0)
				return;
		}
		print_num(k, iter + 1);
	}
}

int main(void)
{
	int k;
	scanf("%d", &k);
	print_num(k, 1);
	return 0;
}
