//#include <stdio.h>

void sort_array(int size, int a[])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int max = a[j - 1];
				a[j - 1] = a[j];
				a[j] = max;
			}
		}
	}
}
/*
int main(void)
{
	int arr[20] = {20, 19, 4, 3, 2, 1, 18, 17, 13, 12, 11, 16, 15, 14, 10, 9, 8, 7, 6, 5};
	sort_array(20, arr);
	for (int i = 0; i < 20; i++)
		printf("%d ",  arr[i]);
	return 0;
}
*/
