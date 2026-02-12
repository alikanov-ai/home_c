#include <stdio.h>

int calculationf(int x)
{
	if (x < -2)
		return 4;
	else if (x >= -2 && x < 2)
		return x*x;
	else
		return x*x+4*x+5;
}

int main(void)
{
	int num, res = 0, max = 0;
	for (scanf("%d", &num); num != 0; scanf("%d", &num))
	{
		res = calculationf(num);
		max = max < res ? res : max;
	}
	printf("%d", max);
	return 0;
}
