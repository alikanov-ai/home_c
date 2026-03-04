#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintInversionHalf(int arr[], int len)
{
	if (len%2 == 0)
		for (int i = 1; i <= len; i++)
			printf("%d ", i <= len/2 ? arr[len/2 - i] : arr[len - (i - len/2)]);
	printf("\n");
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintInversionHalf(arr, LEN);
	return 0;
}
