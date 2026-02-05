#include <stdio.h>

int main(void)
{
	int m;
	scanf("%d", &m);
	if(m>=1 && m<=12)
	{
		if(m<=2 || m==12)
			printf("winter\n");
		else if(m>=3 && m<=5)
			printf("spring\n");
		else if(m>=6 && m<=8)
			printf("summer\n");
		else
			printf("autumn\n");
	}
	return 0;
}
