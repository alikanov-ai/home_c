#include <stdio.h>
#define SIZE 1000

void PrintDigitsAsc(char ch[], int arr[], int len)
{
	for (int i = 0; ch[i] != 0; i++)
		arr[ch[i] - '0']++;
	for (int j = 0; j < len; j++)
		if (arr[j] > 0)
			printf("%d %d\n", j, arr[j]);
}

int main(void)
{
	char ch[SIZE];
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	scanf("%999s", ch);
	PrintDigitsAsc(ch, arr, 10);
	return 0;
}
