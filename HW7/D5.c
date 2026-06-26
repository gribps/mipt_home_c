//Перевести натуральное число в двоичную систему счисления. 
//Необходимо реализовать рекурсивную функцию.

#include <stdio.h>

void rec_func(int N)
{
	if(N/2 > 0)
		rec_func(N/2);
	printf("%d", N%2);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	rec_func(n);
		
	return 0;
	
}

