#include <stdio.h>

int f_func(int);

int main(void)
{
	int max = -999;
	int num = 1;
	while(num!=0)
	{
		scanf("%d", &num);
		max = (max > f_func(num))? max : f_func(num);
	}
		
	printf("%d\n", max);
	return 0;
}

int f_func(int x)
{
	if (x >= 2)
		return x*x + 4*x + 5;
	else if (x>=-2 && x<2)
		return x*x;
	else
		return 4;
}
