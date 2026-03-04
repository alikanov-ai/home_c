#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (arr[j - 1]%10 > arr[j]%10)
			{
				int max = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = max;
			}
		}
		printf("%d ",  arr[i]);
	}
	printf("\n");
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintSort(arr, LEN);
	return 0;
}
