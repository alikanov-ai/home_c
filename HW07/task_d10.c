#include <stdio.h>

int is_prime(int n, int delitel)
{
	if (n == delitel)
		return 1;
	else if (n > 1 && n%delitel != 0)
		return is_prime(n, delitel + 1);
	else
		return 0;
}

int main(void)
{
	int num;
	scanf("%d", &num);
	printf("%s", is_prime(num, 2) ? "YES" : "NO");
	return 0;
}
