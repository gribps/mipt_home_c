//Дана строка заканчивающаяся символом точка '.' 
//Напечатать строку наоборот. 
//Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.

#include <stdio.h>

void rec_func()
{
	char c;
	if( (c = getchar()) == '.' )
		return;
	rec_func();
	printf("%c", c);
	
}

int main(void)
{
//	int n;
//	scanf("%d", &n);
	rec_func();
		
	return 0;	
}
