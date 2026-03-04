#include <stdio.h>

void PrintArray(int arr[], int len)
{
	for (int i = len - 1; i >= 0; i--)
		printf("%d ",  arr[i]);
	printf("\n");
}

int CreateArray(int num, int arr[])
{
	int i = 0;
	while (num > 0)
	{
		arr[i] = num%10;
		i++;
		num /= 10;
	}
	return i;
}

int main(void)
{
	int num, arr[10];
	scanf("%d", &num);
	int count = CreateArray(num, arr);
	PrintArray(arr, count);
	return 0;
}
