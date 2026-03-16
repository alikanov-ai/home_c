//#include <stdio.h>

int is_two_same(int size, int a[])
{
	for (int i = 0; i < size; i++)
		for (int j = size - 1; j > i; j--)
			if (a[i] == a[j])
				return 1;
	return 0;
}
/*
int main(void)
{
	int a[5] = {1, 2, 5, 7, -1};
	printf("%s\n", is_two_same(5, a) ? "YES" : "NO");
	return 0;
}
*/
