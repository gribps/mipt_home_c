//Составить функцию, которая преобразует текущий символ цифры в число. 
//Написать программу считающую сумму цифр в тексте. int digit_to_num(char c)

#include <stdio.h>

int digit_to_num(char c)
{
	if( c>= 0x30 && c <= 0x39)
		return c - 0x30;
	else 
		return 0;
}

int main(void)
{
	char c;
	int sum = 0;
	
	while( (c = getchar()) != '\n')
		sum += digit_to_num(c);
		
	printf("%d\n", sum);
	return 0;
}

