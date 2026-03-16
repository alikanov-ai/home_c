//#include <stdio.h>

void swap_negmax_last(int size, int a[])		
{
	if (size > 0)
	{
		int max = 0;
		for (int i = 0; i < size; i++)
		{
			if (a[i] >= 0)
				continue;
			max = a[max] >= a[i] && a[max] < 0 ? max : i;
		}
		if (a[max] < 0)
		{
			int temp = a[max];
			a[max] = a[size - 1];
			a[size - 1] = temp;
		}
	}
}
/*
int main(void)
{
	int a[10] = {1, -2, -3, -4, 5, 6, 7, 8, 9, 10};
	swap_negmax_last(10, a);
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
	return 0;
}
*/
