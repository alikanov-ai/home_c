//#include <stdio.h>

int compression(int a[], int b[], int N)
{
	if (N == 0)
		return 0;
	int pos = 0, curr_num = 0, prev = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] != curr_num)
		{
			b[pos++] = i - prev;
			curr_num = a[i];
			prev = i;
		}
		if (i == N - 1)
			b[pos++] = i - prev + 1;
	}
	return pos;
}
/*
int main(void)
{
	int a[17] = {1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1}, b[4];
	int count = compression(a, b, 17);
	for (int i = 0; i < count; i++)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}
*/
