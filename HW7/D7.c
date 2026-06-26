//Составить рекурсивную функцию, печать всех чисел от N до 1

#include <stdio.h>

void rec_func(int N)
{
	if(N>0)
	{
		printf("%d ", N);
		rec_func(N-1);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	rec_func(N);
	return 0;
}
