// Laba 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() //Задание: Ввести строку, вывести на экран только слова начинающиеся с гласной буквы.

{
	char temp_string[500];
	char string[500];
	char result[500];
	char alphabet[6] = "aoeiu";
	int counter, counter_2, counter_3, counter_4, counter_6, space, length_word, flag, counter_7, counter_8,counter_9;
	int length = 0;
	int length_result = 0;
	counter_3 = 0;
	length_word = 0;


	printf("Enter your text:\n");

	fgets(temp_string, sizeof(temp_string), stdin);

	counter_6 = 0;
	length = 0;
	while (temp_string[counter_6] != (NULL)) { //рассчет длины строки
		length = length + 1;
		counter_6 = counter_6 + 1;
	}

	string[0] = ' ';


	for (counter_2 = 0; counter_2 < length; (counter_2++)) //копирование строки с пробелом в начале
	{
		string[counter_2 + 1] = temp_string[counter_2];

	}
	string[length + 1] = ' ';
	//puts(string);

	for (counter_8 = 0; counter_8 <= length; counter_8++) { //перевод из заглавной в строчную
		if ('A' <= string[counter_8] && string[counter_8] <= 'Z') {
			string[counter_8] -= 'A' - 'a';
		}
	}

	for (counter_9 = 0; counter_9 <= length; counter_9++) { // замена табов на пробелы
		if (string[counter_9] == '	') {
			string[counter_9] = ' ';
		}
	}
	flag = 0;
	//puts(string);
	for (counter = 1; counter < length + 1; (counter++)) //пробег по строке
	{
		for (counter_7 = 0; counter_7 < 6; counter_7++) { //проверка на гласность
			if (string[counter] == alphabet[counter_7]) {
				flag = 1;
			}
		}

		if (flag == 1)
		{
			flag = 0;
			if ((string[counter - 1] == ' ') or (string[counter - 1] == '	'))
			{

				space = (counter - 1); //номер пробела

				counter_3 = space + 1;
				while ((string[counter_3] != (' ')) and (string[counter_3] != ('	')))
				{

					length_word = length_word + 1; //длина слова
					counter_3 = counter_3 + 1;

				}

				for (counter_4 = space; counter_4 < space + length_word + 1; counter_4++) {
					if ((string[counter_4] != (' ')) and (string[counter_4] != ('	')))
					{
						result[length_result + 1] = string[counter_4];
						//printf("%c\n", string[counter_4]);
						length_result = length_result + 1;
					}
				}
				length_result = length_result + 1;
				result[length_result] = ' '; //добавление пробела в результат

				length_word = 0;


			}
		}
		flag = 0;
	}
	printf("Words starting with vowel letter:\n");
	//puts(result);
	for (counter = 1; counter < length_result; counter++) {
		printf("%c", result[counter]);
	}
	return 0;
}