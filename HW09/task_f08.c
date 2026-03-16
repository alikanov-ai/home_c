#include <stdio.h>

int FindInArray(int search, int arr[], int len)
{
	if (len > 0)
		for (int i = 0; i < len; i++)
			if (search == arr[i])
				return 1;
	return 0;
}

void PrintMissingNum(int arr[], int len)		
{
	if (len > 0)
	{
		int min = arr[0], max = arr[0];
		for (int i = 1; i < len; i++)
		{
			max = max >= arr[i] ? max : arr[i];
			min = min <= arr[i] ? min : arr[i];
		}
		for (int j = min; j <= max; j++)
			if (!FindInArray(j, arr, len))
				printf("%d ", j);
	}
	printf("\n");
}

int main(void)
{
	int arr[1000], i = 0;
	scanf("%d", &arr[i]);
	while (arr[i] > 0)
		scanf("%d", &arr[++i]);
	PrintMissingNum(arr, i);
	return 0;
}
