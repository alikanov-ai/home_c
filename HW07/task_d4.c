#include <stdio.h>

void print_num(int num)
{
	static int count = 0;
	if (num > 0)
	{
		count++;
		print_num(num/10);
		printf("%d\n", num%10);
	}
	else if (num == 0 && count == 0)
		printf("0\n");
}

int main(void)
{
	int num;
	scanf("%d", &num);
	print_num(num);
	return 0;
}
