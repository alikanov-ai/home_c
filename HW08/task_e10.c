#include <stdio.h>
#define LEN 12

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
		if (i < 4)
			printf("%d ", arr[(len - 4) + i]);
		else
			printf("%d ", arr[i - 4]);
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
