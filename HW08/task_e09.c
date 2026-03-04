#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintСyclicShift(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
			printf("%d ", arr[len - 1]);
		else
			printf("%d ", arr[i - 1]);
	}
	printf("\n");
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintСyclicShift(arr, LEN);
	return 0;
}
