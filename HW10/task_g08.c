#include <stdio.h>

int InDegree(int num, int deg)
{
	if (deg == 0)
		return 1;
	int res = num;
	for (int i = 1; i < deg; i++)
		res *= num;
	return res;
}

void ArraySort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				int max = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = max;
			}
		}
	}
}

int main(void)
{
	FILE *f;
	// Получаем строку из файла
	if ((f = fopen("input.txt", "r")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	char str[1001];
	if (fgets(str, sizeof(str), f) == NULL)
	{
		fclose(f);
		return 0;
	}
	fclose(f);
	
	// Убираем из строки все лишнее
	int count = 0, delimiter = 1, i = 0, last_pos = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			str[last_pos++] = str[i];
			if (delimiter)
			{
				count++;
				delimiter = 0;
			}
		}
		else if (!(str[i] >= '0' && str[i] <= '9') && count && !delimiter)
		{
			delimiter = 1;
			str[last_pos++] = ' ';
		}
		i++;
	}
	str[last_pos] = 0;
	
	// Формируем целочисленный массив arr из строки и сортируем его
	int arr[count];
	if (count)
	{
		int start_pos = 0, last_pos_arr = 0;
		i = 0;
		while (i <= last_pos)
		{
			if (str[i] == ' ' || str[i] == '\0')
			{
				int current_num = 0;
				for (int iter = start_pos; iter < i; iter++)
				{
					printf("current_num: %d\n", current_num);
					printf("+ %d\n", str[iter] - 48);
					printf("i: %d\n", i);
					printf("iter: %d\n", iter);
					printf("InDegree: %d\n", InDegree(10, i - 1 - iter));
					current_num = current_num + (str[iter] - 48) * InDegree(10, i - 1 - iter);
				}
				arr[last_pos_arr] = current_num;
				last_pos_arr++;
				start_pos = i + 1;
			}	
			i++;
		}
		ArraySort(arr, count);
	}
	
	// Записываем данные в файл
	if ((f = fopen("output.txt", "w")) == NULL)
	{
		perror("File opening error");
		return 1;
	}
	for (i = 0; i < count; i++)
		fprintf(f, "%d ", arr[i]);
	fclose(f);
	
	return 0;
}
