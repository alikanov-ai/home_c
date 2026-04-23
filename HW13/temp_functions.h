#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

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
	struct sensor* next;
};

/* === Управление списком === */
struct sensor* CreateNode(uint16_t, uint8_t, uint8_t, uint8_t, uint8_t, int8_t);
void AddNodeToList(struct sensor**, struct sensor*);
void FreeList(struct sensor**);
int CountList(struct sensor*);

/* === Работа с файлом === */
int AddInfo(struct sensor**, const char*);

/* === Статистика === */
void PrintStatisticsMonth(struct sensor*, uint8_t, uint16_t);
void PrintStatisticsYear(struct sensor*, uint16_t);

/* === Вспомогательные функции === */
void PrintHelp(void);
uint8_t MonthToInt(const char*);
uint16_t YearToInt(const char*);
int Compare(const void*, const void*); // Для qsort при сортировке
void PrintAll(struct sensor*, uint8_t, uint16_t);
struct sensor* SortList(struct sensor*);

#endif