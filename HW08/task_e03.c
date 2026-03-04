#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintMaxMin(int arr[], int len)
{
	int min = 0, max = 0;
	for (int i = 1; i < len; i++)
	{
		max = arr[max] >= arr[i] ? max : i;
		min = arr[min] <= arr[i] ? min : i;
	}
	printf("%d %d %d %d\n", max+1, arr[max], min+1, arr[min]);
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintMaxMin(arr, LEN);
	return 0;
}
