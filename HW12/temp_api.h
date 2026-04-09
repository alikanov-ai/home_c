#ifndef TEMP_API_H
#define TEMP_API_H
#include <stdio.h> 
#include <stdint.h>
#include <stdlib.h>

struct sensor
{
	uint16_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hours;
	uint8_t minutes;
	int8_t temperature;	
};

void AddRecord(struct sensor* info, uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, int8_t);
int AddInfo(struct sensor info[], const char*);
void PrintMonthlyAverageTemp(struct sensor info[], int, uint8_t, uint16_t);
void PrintMonthlyMinTemp(struct sensor info[], int, uint8_t, uint16_t);
void PrintMonthlyMaxTemp(struct sensor info[], int, uint8_t, uint16_t);
void PrintStatisticsYear(struct sensor info[], int, uint16_t);
void PrintHelp(void);
uint8_t MonthToInt(const char*);
uint16_t YearToInt(const char*);
int Compare(const void*, const void*);
void PrintAll(struct sensor info[], int);

#endif