#include <stdio.h>
#include <stdint.h>
#include "temp_api.h"
#define SIZE 30

int main(void)
{
	struct sensor info[SIZE];
	int number = AddInfo(info);
	PrintMonthlyAverageTemp(info, number, 2, 2026);
	PrintMonthlyMinTemp(info, number, 2, 2026);
	PrintMonthlyMaxTemp(info, number, 2, 2026);
	PrintStatisticsYear(info, number, 2026);
	return 0;
}
