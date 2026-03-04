#include <stdio.h>

void PrintSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (arr[j - 1] < arr[j])
			{
				int max = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = max;
			}
		}
		printf("%d",  arr[i]);
	}
	printf("\n");
}

int CreateArray(int num, int arr[])
{
	int i = 0;
	while (num > 0)
	{
		arr[i] = num%10;
		i++;
		num /= 10;
	}
	return i;
}

int main(void)
{
	int num, arr[10];
	scanf("%d", &num);
	int count = CreateArray(num, arr);
	PrintSort(arr, count);
	return 0;
}
