#include <stdio.h>

void print_reverse(int num)
{
	static int count = 0;
	if (num > 0)
	{
		printf("%d\n", num%10);
		count++;
		print_reverse(num/10);
	}
	else if (num == 0 && count == 0)
		printf("0\n");
}

int main(void)
{
	int num;
	scanf("%d", &num);
	print_reverse(num);
	return 0;
}
