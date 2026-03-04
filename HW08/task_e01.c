#include <stdio.h>
#define LEN 5

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintCalc(int arr[], int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	printf("%.3f\n", (float)sum/len);
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintCalc(arr, LEN);
	return 0;
}
