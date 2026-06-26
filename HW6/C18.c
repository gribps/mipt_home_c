//Составить логическую функцию, которая определяет, 
//что текущий символ это цифра. 
//Написать программу считающую количество цифр в тексте. int is_digit(char c)

#include <stdio.h>

int is_digit(char c)
{
	if( c>= 0x30 && c <= 0x39)
		return 1;
	else 
		return 0;
}

int main(void)
{
	char c;
	int cnt = 0;
	
	while( (c = getchar()) != '\n')
		cnt += is_digit(c);
		
	printf("%d\n", cnt);
	return 0;
}
