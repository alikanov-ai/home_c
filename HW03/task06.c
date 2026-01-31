#include <stdio.h>

int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	float d = (a + b + c) / 3.0;
	printf("%.2f\n", d);
	return 0;
}

