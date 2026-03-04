#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintSumTwoMax(int arr[], int len)
{
	int max1 = 0, max2 = 1;
	for (int i = 1; i < len; i++)
	{
		if (arr[i] > arr[max1])
		{
			max2 = max1;
			max1 = i;
		}
		else if (arr[i] > arr[max2])
			max2 = i;
	}
	printf("%d\n", arr[max1] + arr[max2]);
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintSumTwoMax(arr, LEN);
	return 0;
}
