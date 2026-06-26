//Дано целое не отрицательное число N. 
//Выведите все его цифры по одной, в обратном порядке, 
//разделяя их пробелами или новыми строками.

#include <stdio.h>

void rec_func(int N)
{
	if(N > 0)
	{
		printf("%d ", N%10);
		rec_func(N/10);
	}
}


int main(void)
{
	int n;
	scanf("%d", &n);
	
	if(n==0)
		printf("0");
	else
		rec_func(n);
		
	return 0;
}
