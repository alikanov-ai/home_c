#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintSort(int arr[], int len, int desc)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j] && !desc)
			{
				int max = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = max;
			}
			if (arr[j - 1] < arr[j] && desc)
			{
				int max = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = max;
			}
		}
		printf("%d ",  arr[i]);
	}
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintSort(arr, LEN/2, 0);
	PrintSort(&arr[LEN/2], LEN/2, 1);
	return 0;
}
