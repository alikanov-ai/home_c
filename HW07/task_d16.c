#include <stdio.h>

int is2pow(unsigned int n)
{
	if (n == 2 || n == 1)
		return 1;
	if (n%2 == 0)
		return is2pow(n/2);
	else
		return 0;	
}

int main(void)
{
	unsigned int num;
	scanf("%d", &num);
	printf("%s", is2pow(num) ? "YES" : "NO");
	return 0;
}
