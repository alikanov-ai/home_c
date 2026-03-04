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

void PrintMostCommon(int arr[], int len)
{
	int res = arr[0], max_count = 0;
	for (int i = 0; i < len; i++)
	{
		int count = FindInArray(arr[i], arr, len);
		if (count > max_count)
		{
			max_count = count;
			res = arr[i] ;
		}
	}
	printf("%d\n",  res);
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintMostCommon(arr, LEN);
	return 0;
}
