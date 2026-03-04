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
}

int FindInArray(int search, int arr[], int len)
{
	int res = 0;
	if (len > 0)
		for (int i = 0; i < len; i++)
			if (search == arr[i]) res = 1;
	return res;
}

int CreateArray(int arr[], int res[], int len, int negative)
{
	int count = 0;
	for (int i = 0; i < len; i++)
		if ((!negative && arr[i] > 0) || (negative && arr[i] < 0))
			res[count++] = arr[i];
	return count;
}

int main(void)
{
	int arr[LEN], res_positive[LEN], res_negative[LEN];
	Input(arr, LEN);
	int count_positive = CreateArray(arr, res_positive, LEN, 0);
	Print(res_positive, count_positive);
	int count_negative = CreateArray(arr, res_negative, LEN, 1);
	Print(res_negative, count_negative);
	return 0;
}
