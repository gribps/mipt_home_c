#include <stdio.h>

int power(int, int);

int main(void)
{
	int num, pow;
	scanf("%d%d", &num, &pow);
	printf("%d", power(num, pow));
	return 0;
}

int power(int num, int pow)
{
	if (pow==0)
		return 1;
	
	int res = 1;
	for(; pow>0; pow--)
		res *= num;
	return res;
}
