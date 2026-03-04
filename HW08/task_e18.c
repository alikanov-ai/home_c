#include <stdio.h>

void PrintMultipleCount(int start_num, int end_num, int arr_multiple[], int arr_multiple_len)
{
	for (int i = 0; i < arr_multiple_len; i++)
	{
		int count = 0;
		for (int j = start_num; j <= end_num; j++)
			if (j%arr_multiple[i] == 0) count++;
		printf("%d %d\n",  arr_multiple[i], count);
	}
}

int main(void)
{
	int N, arr_multiple[8] = {2, 3, 4, 5, 6, 7, 8, 9};
	scanf("%d", &N);
	PrintMultipleCount(2, N, arr_multiple, 8);
	return 0;
}
