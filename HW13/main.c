#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"

int main(int argc, char *argv[])
{
	int opt;
	uint8_t month = 0, sort = 0, print = 0;
	uint16_t year = 0;
	char *file_path = NULL;
	
	while ((opt = getopt(argc,argv,"hf:m:y:sp")) != -1)
	{
		switch (opt)
		{
			case 'h':
				PrintHelp();
				return 0;
			case 'f':
				file_path = optarg;
				break;
			case 'm':
				month = MonthToInt(optarg);
				if (!month)
				{
					fprintf(stderr, "Error: the month is specified incorrectly.\n");
					return 1;
				}
				break;
			case 'y':
				year = YearToInt(optarg);
				if (!year)
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
				printf("Unknown argument: %s. Use -h for help.\n", argv[optind]);
				return 1;
 		}
	}

	if (!file_path)
	{
		fprintf(stderr, "Error: requires specifying the value of the -f parameter.\n");
		return 1;
	}

	struct sensor* head = NULL;
	if (!AddInfo(&head, file_path))
	{
		fprintf(stderr, "Error: no valid data found in file.\n");
		FreeList(&head);
		return 1;
	}
	if (sort)
		head = SortList(head);
	if (!year)
		year = head->year;
	if (print)
		PrintAll(head, month, year);
	if (month)
		PrintStatisticsMonth(head, month, year);
	else
		for (uint8_t m = 1; m <= 12; m++)
			PrintStatisticsMonth(head, m, year);
	PrintStatisticsYear(head, year);
	
	FreeList(&head);
	return 0;
}