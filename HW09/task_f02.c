//#include <stdio.h>

void sort_even_odd(int n, int a[])
{
	int res[n], i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i]%2 == 0)
		{
			res[j] = a[i];
			j++;
		}
	}
	for (i = 0; i < n; i++)
	{
		if (a[i]%2 != 0)
		{
			res[j] = a[i];
			j++;
		}
	}
	for (i = 0; i < n; i++)
		a[i] = res[i];
}
/*
int main(void)
{
	int arr[5] = {1, 0, 1, 0, 1};
	sort_even_odd(5, arr);
	for (int i = 0; i < 5; i++)
		printf("%d ",  arr[i]);
	return 0;
}
*/
