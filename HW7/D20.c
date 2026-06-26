//Написать рекурсивную функцию возведения целого числа n в степень p.

#include <stdio.h>

int rec_func(int n, int p)
{
	if( p > 0)
		return n * rec_func(n, p-1);
	else
		return 1;
}


int main(void)
{
	int n, p;
	scanf("%d%d", &n, &p);
	printf("%d\n", rec_func(n, p));
	return 0;
}
