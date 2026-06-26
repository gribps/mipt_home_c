#include <stdio.h>

int factorial(int dig)
{
	if (dig == 0)
		return 1;
	
	int res=1;
	for(;dig > 0; dig--)
		res *= dig;
	
	return res;
}

int main(void)
{
	int dig;
	scanf("%d", &dig);
	printf("%d\n", factorial(dig));
}
