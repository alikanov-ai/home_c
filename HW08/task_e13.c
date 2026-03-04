#include <stdio.h>
#define LEN 10

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void Print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ",  arr[i]);
	printf("\n");
}

int CreateArray(int arr[], int res[], int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
		if ((arr[i]/10)%10 == 0) res[count++] = arr[i];
	return count;
}

int main(void)
{
	int arr[LEN], res[LEN];
	Input(arr, LEN);
	int count = CreateArray(arr, res, LEN);
	Print(res, count);
	return 0;
}
