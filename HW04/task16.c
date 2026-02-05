#include <stdio.h>

int main(void)
{
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	float k = (float)(y2 - y1)/(float)(x2 - x1);
	float b = y2 - k * x2;
	printf("%.2f %.2f\n", k, b);
	return 0;
}

