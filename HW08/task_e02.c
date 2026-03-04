#include <stdio.h>
#define LEN 5

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintMin(int arr[], int len)
{
	int min = arr[0];
	for (int i = 1; i < len; i++)
		min = min > arr[i] ? arr[i] : min;
	printf("%d\n", min);
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintMin(arr, LEN);
	return 0;
}
