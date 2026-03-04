#include <stdio.h>
#define LEN 12

int Input(int arr[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		scanf("%d", &arr[i]);
	return i;
}

void PrintInversionThird(int arr[], int len)
{
	if (len%3 == 0)
	{
		for (int i = 1; i <= len; i++)
		{
			if (i <= len/3)
				printf("%d ", arr[len/3 - i]);
			else if (i <= (len/3)*2)	
				printf("%d ", arr[len - i]);
			else
				printf("%d ", arr[(2*len - len/3) - i]);
		}
	}
	printf("\n");
}

int main(void)
{
	int arr[LEN];
	Input(arr, LEN);
	PrintInversionThird(arr, LEN);
	return 0;
}
