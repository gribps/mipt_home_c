//Составить рекурсивную функцию, печать всех чисел от 1 до N

#include <stdio.h>

void rec_func_1(int N)
{
	if(N>1)
		rec_func_1(N-1);
	printf("%d ", N);
}

int main(void)
{
	int dig;
	scanf("%d", &dig);
	rec_func_1(dig);
	return 0;
}
