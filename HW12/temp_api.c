#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "temp_api.h"

void AddRecord(struct sensor* info, uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature)
{
	info->year = year;
	info->month = month;
	info->day = day;
	info->hours = hours;
	info->minutes = minutes;
	info->temperature = temperature;
}

int AddInfo(struct sensor info[], const char* file_path)
{
	if (!file_path) return 0;
	FILE *fp = fopen(file_path, "r");
	if (!fp)
	{
		fprintf(stderr, "Error: file opening error.\n");
    	return 0;
	}
	char line[256];
	unsigned int count = 0, line_num = 0;
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		line_num++;
		uint16_t y;
		uint8_t m, d, h, min;
		int8_t temp;
		// Пытаемся прочитать ровно 6 целых чисел, разделенных ';'
		// Если строка некорректна (например, "-xx" или пустая), sscanf вернет < 6
		if (sscanf(line, "%u;%hhu;%hhu;%hhu;%hhu;%hhd", &y, &m, &d, &h, &min, &temp) == 6)
		{
			// Валидация диапазонов
			if (m < 1 || m > 12 || d < 1 || d > 31 || temp < -99 || temp > 99)
			{
				fprintf(stderr, "Warning: invalid data on line %u, skipped\n", line_num);
				continue;
			}
			if (count >= 525600) break;
			AddRecord(&info[count], y, m, d, h, min, temp);
			count++;
		}
		else
			fprintf(stderr, "Warning: format error on line %u, skipped\n", line_num);
	}
	fclose(fp);
	return count;
}

void PrintMonthlyAverageTemp(struct sensor info[], int number, uint8_t month, uint16_t year)
{
	int sum = 0, count = 0;
	for (int i = 0; i < number; i++)
	{
		if (info[i].month != month || info[i].year != year)
			continue;
		sum += info[i].temperature;
		count++;
	}
	if(count)
		printf("%d\n", sum/count);
}

void PrintMonthlyMinTemp(struct sensor info[], int number, uint8_t month, uint16_t year)
{
	int8_t min = 100;
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		if (info[i].month != month || info[i].year != year)
			continue;
		if (info[i].temperature < min)
			min = info[i].temperature;
		count++;
	}
	if(count)
		printf("%d\n", min);
}

void PrintMonthlyMaxTemp(struct sensor info[], int number, uint8_t month, uint16_t year)
{
	int8_t max = -100;
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		if (info[i].month != month || info[i].year != year)
			continue;
		if (info[i].temperature > max)
			max = info[i].temperature;
		count++;
	}
	if(count)
		printf("%d\n", max);
}

void PrintStatisticsYear(struct sensor info[], int number, uint16_t year)
{
	int sum = 0, count = 0;
	int8_t max = -100, min = 100;
	for (int i = 0; i < number; i++)
	{
		if (info[i].year != year)
			continue;
		if (info[i].temperature < min)
			min = info[i].temperature;
		if (info[i].temperature > max)
			max = info[i].temperature;
		sum += info[i].temperature;
		count++;
	}
	if(count)
	{
		printf("Statistics for the %04u\n", year);
		printf("  average temperature: %d\n", sum/count);
		printf("  minimum temperature: %d\n", min);
		printf("  maximum temperature: %d\n", max);
	}
}

void PrintAll(struct sensor info[], int number)
{
	for (int i = 0; i < number; i++)
		printf("%u-%hhu-%hhu %hhu:%hhu t=%hhd\n", info[i].year, info[i].month, info[i].day, info[i].hours, info[i].minutes, info[i].temperature);
}

void PrintHelp(void)
{
	printf("This program is designed to output temperature statistics from a data file.\n"
    "-h - is used to output help.\n"
    "-f - is used to specify the path to the data file.\n"
    "-y - is used to indicate the year for which statistics are required (four digits).\n"
    "-m - is used to indicate the month for which statistics are required (1 - 12).\n"
	"-s - is used to sort data by date and time.\n"
	"-p - is used for data output.\n");
}

uint8_t MonthToInt(const char* month_str)
{
	if (!month_str) return 0;
	char* endptr;
	long int val = strtol(month_str, &endptr, 10);
	if (*endptr != '\0') return 0;// после числа есть лишние символы
	if (val < 1 || val > 12) return 0;// проверка допустимого диапазона
	return (uint8_t) val;
}

uint16_t YearToInt(const char* year_str)
{
	if (!year_str) return 0;
	char* endptr;
	long int val = strtol(year_str, &endptr, 10);
	if (*endptr != '\0') return 0;// после числа есть лишние символы
	if (val < 1000 || val > 9999) return 0;// проверка допустимого диапазона
	return (uint16_t) val;
}

int Compare(const void* pa, const void* pb)
{
	struct sensor* a = (struct sensor*) pa;
	struct sensor* b = (struct sensor*) pb;
	if (a->year != b->year)
		return (a->year > b->year) ? 1 : -1;
	else if (a->month != b->month)
		return (a->month > b->month) ? 1 : -1;
	else if (a->day != b->day)
		return (a->day > b->day) ? 1 : -1;
	else if (a->hours != b->hours)
		return (a->hours > b->hours) ? 1 : -1;
	else
		return (a->minutes > b->minutes) ? 1 : -1;
}