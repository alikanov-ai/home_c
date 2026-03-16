//#include <stdio.h>

void print_digit(char s[])
{
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; s[i] != 0; i++)
		if (s[i] >= 48 && s[i] <= 57)
			arr[s[i] - '0']++;
	for (int j = 0; j < 10; j++)
		if (arr[j] > 0)
			printf("%d %d\n", j, arr[j]);
}
/*
int main(void)
{
	print_digit("Hello123 world77.");
	return 0;
}
*/
