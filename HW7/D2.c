//Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N

#include <stdio.h>

int rec_func(int N)
{
	if(N>1)
		return N + rec_func(N-1);
	else 
		return 1;
}

int main(void)
{
	int dig;
	scanf("%d", &dig);
	printf("%d\n", rec_func(dig));
	return 0;
}


