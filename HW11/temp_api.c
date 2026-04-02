#include <stdio.h>
#include <stdint.h>
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

int AddInfo(struct sensor info[])
{
	struct sensor *pinfo = info;
	AddRecord(info++, 2026, 2, 2, 10, 15, -2);
	AddRecord(info++, 2026, 2, 3, 10, 5, -5);
	AddRecord(info++, 2026, 2, 4, 10, 5, -10);
	AddRecord(info++, 2026, 2, 30, 10, 5, 2);
	AddRecord(info++, 2026, 4, 1, 9, 45, 10);
	AddRecord(info++, 2026, 3, 1, 9, 15, 9);
	AddRecord(info++, 2025, 4, 1, 9, 0, 9);
	AddRecord(info++, 2026, 2, 1, 10, 5, -2);
	return info - pinfo;
}

void PrintMonthlyAverageTemp(struct sensor info[], int number, uint8_t month, uint16_t year)
{
	int16_t sum = 0;
	uint8_t count = 0;
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
	uint8_t count = 0;
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
	uint8_t count = 0;
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
	int16_t sum = 0;
	uint16_t count = 0;
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
		printf("%d\n", sum/count);
		printf("%d\n", min);
		printf("%d\n", max);
	}
}