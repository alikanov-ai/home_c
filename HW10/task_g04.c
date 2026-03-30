#include <stdio.h>

int main(void)
{
	FILE *f;
	if ((f = fopen("input.txt", "r")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
	
	char str1[101], str2[101];
	if (fscanf(f, "%100s %100s", str1, str2) != 2)
	{
		fclose(f);
		return 0;
	}
	fclose(f);

    // Подсчёт частоты встречаемости символов. Маленькие (строчные) английские буквы соответствуют кодам 97–122.
    int count1[26] = {0}, count2[26] = {0}, i;
    
    // Подсчёт в первом слове с пропуском посторонних символов
    for (i = 0; str1[i] != '\0'; i++) {
		if (str1[i] < 'a' || str1[i] > 'z')
			continue;
        count1[str1[i] - 'a']++;
    }
    
    // Подсчёт во втором слове с пропуском посторонних символов
    for (i = 0; str2[i] != '\0'; i++) {
		if (str2[i] < 'a' || str2[i] > 'z')
			continue;
        count2[str2[i] - 'a']++;
    }
    
    // Поиск и вывод символов, встречающихся по 1 разу в обоих словах
	if ((f = fopen("output.txt", "w")) == NULL)
	{
        perror("File opening error");
        return 1;
	}
    for (i = 0; i < 26; i++)
    {
		if (count1[i] == 1 && count2[i] == 1)
			fprintf(f, "%c ", 'a' + i);
	}
	fclose(f);		
    
	return 0;
}
