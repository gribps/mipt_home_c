//Дано натуральное число N. 
//Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. 
//Необходимо реализовать рекурсивную функцию.
//void print_num(int num)

#include <stdio.h>

void rec_func(int N)
{
	if(N/10 > 0)
		rec_func(N/10);
	printf("%d ", N%10);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	rec_func(n);
		
	return 0;
	
}

