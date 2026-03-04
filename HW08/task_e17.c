#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

int FindInArray(int search, int arr[], int len)
{
	int count = 0;
	if (len > 0)
		for (int i = 0; i < len; i++)
			if (search == arr[i]) count++;
	return count;
}

void PrintOnlyOne(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		if (FindInArray(arr[i], arr, len) == 1)
			printf("%d ",  arr[i]);
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintOnlyOne(arr, LEN);
	return 0;
}
