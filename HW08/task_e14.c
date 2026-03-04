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

int FindInArray(int search, int arr[], int len)
{
	int res = 0;
	if (len > 0)
		for (int i = 0; i < len; i++)
			if (search == arr[i]) res = 1;
	return res;
}

int CreateArray(int arr[], int res[], int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
		for (int j = len - 1; j > i; j--)
			if (arr[i] == arr[j] && !FindInArray(arr[i], res, count))
				res[count++] = arr[i];
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
