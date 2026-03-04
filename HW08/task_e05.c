#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintSumPositive(int arr[], int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] <= 0)
			continue;
		sum += arr[i];
	}
	printf("%d\n", sum);
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintSumPositive(arr, LEN);
	return 0;
}
