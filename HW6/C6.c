#include <stdio.h>
#include <math.h>

unsigned long long int func_1 (int dig)
{	//геометр прогрессия
	unsigned long long int res = pow(2, dig-1);
	return res;
}

int main(void)
{
	int dig;
	scanf("%d", &dig);
	printf("%llu\n", func_1(dig));
	return 0;
}
