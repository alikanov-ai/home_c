#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "temp_functions.h"

/* Создание нового узла */
struct sensor* CreateNode(uint16_t year, uint8_t month, uint8_t day, uint8_t hours, uint8_t minutes, int8_t temperature)
{
	struct sensor* node = malloc(sizeof(struct sensor));
	if (!node) return NULL;
	node->year = year;
	node->month = month;
	node->day = day;
	node->hours = hours;
	node->minutes = minutes;
	node->temperature = temperature;
	node->next = NULL;
	return node;
}

/* Добавление узла в начало списка (LIFO) */
void AddNodeToList(struct sensor** head, struct sensor* new_node)
{
	if (!new_node) return;
	new_node->next = *head;
	*head = new_node;
}

/* Освобождение памяти списка */
void FreeList(struct sensor** head)
{
	struct sensor* curr = *head;
	while (curr)
	{
		struct sensor* next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

/* Подсчёт элементов в списке */
int CountList(struct sensor* head)
{
	int count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

/* Чтение файла и заполнение списка */
int AddInfo(struct sensor** head, const char* file_path)
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
		if (sscanf(line, "%hu;%hhu;%hhu;%hhu;%hhu;%hhd", &y, &m, &d, &h, &min, &temp) == 6)
		{
			// Валидация диапазонов
			if (m < 1 || m > 12 || d < 1 || d > 31 || temp < -99 || temp > 99 || h > 23 || min > 59)
			{
				fprintf(stderr, "Warning: invalid data on line %u, skipped\n", line_num);
				continue;
			}
			struct sensor* node = CreateNode(y, m, d, h, min, temp);
			if (node)
			{
				AddNodeToList(head, node);
				count++;
			}
		}
		else
			fprintf(stderr, "Warning: format error on line %u, skipped\n", line_num);
	}
	fclose(fp);
	return count;
}

/* Статистические функции */
void PrintStatisticsMonth(struct sensor* head, uint8_t month, uint16_t year)
{
	int sum = 0, count = 0;
	int8_t max = -100, min = 100;
	for (struct sensor* curr = head; curr; curr = curr->next)
	{
		if (curr->year != year || curr->month != month)
			continue;
		if (curr->temperature < min)
			min = curr->temperature;
		if (curr->temperature > max)
			max = curr->temperature;
		sum += curr->temperature;
		count++;
	}
	if (count == 0)
	{
		printf("No data for %04u-%02u\n", year, month);
		return;
	}
	printf("Statistics for %04u-%02u\n", year, month);
	printf("  average temperature: %.1f\n", (float)sum/count);
	printf("  minimum temperature: %d\n", min);
	printf("  maximum temperature: %d\n", max);
}

void PrintStatisticsYear(struct sensor* head, uint16_t year)
{
	int sum = 0, count = 0;
	int8_t max = -100, min = 100;
	for (struct sensor* curr = head; curr; curr = curr->next)
	{
		if (curr->year != year)
			continue;
		if (curr->temperature < min)
			min = curr->temperature;
		if (curr->temperature > max)
			max = curr->temperature;
		sum += curr->temperature;
		count++;
	}
	if (count == 0)
	{
		printf("No data\n");
		return;
	}
	printf("Statistics for the %04u\n", year);
	printf("  average temperature: %.1f\n", (float)sum/count);
	printf("  minimum temperature: %d\n", min);
	printf("  maximum temperature: %d\n", max);
}

/* Вывод записей из файла */
void PrintAll(struct sensor* head, uint8_t month, uint16_t year)
{
	for (struct sensor* curr = head; curr; curr = curr->next)
	{
		if ((year && curr->year != year) || (month && curr->month != month))
			continue;
		printf("%04u-%02hhu-%02hhu %02hhu:%02hhu t=%hhd\n", curr->year, curr->month, curr->day, curr->hours, curr->minutes, curr->temperature);
	}
}

/* Вывод справки */
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

/* Вспомогательные функции */
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
	struct sensor* a = *(struct sensor**)pa;
	struct sensor* b = *(struct sensor**)pb;
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

/* Сортировка списка через конвертацию в массив */
struct sensor* SortList(struct sensor* head)
{
	int n = CountList(head);
	if (n <= 1) return head;

	struct sensor** arr = malloc(n * sizeof(struct sensor*));
	if (!arr)
	{
		fprintf(stderr, "Error: memory allocation failed during sorting.\n");
		return head;
	}

	struct sensor* curr = head;
	for (int i = 0; i < n; i++)
	{
		arr[i] = curr;
		curr = curr->next;
	}

	qsort(arr, n, sizeof(struct sensor*), Compare);

	for (int i = 0; i < n - 1; i++)
		arr[i]->next = arr[i + 1];
	arr[n - 1]->next = NULL;

	struct sensor* new_head = arr[0];
	free(arr);
	return new_head;
}