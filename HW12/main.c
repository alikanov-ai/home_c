#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_api.h"
#define SIZE 30

int main(int argc, char *argv[])
{
	int result = 0;
	uint8_t month = 0, sort = 0, print = 0;
	uint16_t year = 0;
	char *file_path = NULL;
	while ((result = getopt(argc,argv,"hf:m:y:sp")) != -1)
	{
		switch (result)
		{
			case 'h':
				PrintHelp();
				return 0;
			case 'f':
				file_path = optarg;
				break;
			case 'm':
				month = MonthToInt(optarg);
				if (month == 0)
				{
					fprintf(stderr, "Error: the month is specified incorrectly.\n");
					return 1;
				}
				break;
			case 'y':
				year = YearToInt(optarg);
				if (year == 0)
				{
					fprintf(stderr, "Error: the year is specified incorrectly.\n");
					return 1;
				}
				break;
			case 's':
				sort = 1;
				break;
			case 'p':
				print = 1;
				break;
			case '?':
				printf("Unknown argument: %s. Try -h for help\n", argv[optind]);
				return 1;
 		}
	}
	if (file_path == NULL)
	{
		fprintf(stderr, "Error: requires specifying the value of the -f parameter.\n");
		return 1;
	}
	else
	{
		struct sensor info[SIZE];
		int number = AddInfo(info, file_path);
		if (number)
		{
			if (sort)
				qsort(info, number, sizeof(struct sensor), Compare);
			if (print)
				PrintAll(info, number);
			if (year == 0)
				year = info[0].year;
			if (month)
			{
				printf("Statistics for %04u-%02u\n", year, month);
				printf("  average temperature: ");
				PrintMonthlyAverageTemp(info, number, month, year);
				printf("  minimum temperature: ");
				PrintMonthlyMinTemp(info, number, month, year);
				printf("  maximum temperature: ");
				PrintMonthlyMaxTemp(info, number, month, year);
				printf("\n");
			}
			else
				PrintStatisticsYear(info, number, year);
		}
	}
	return 0;
}