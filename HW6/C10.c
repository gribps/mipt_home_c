#include <stdio.h>

void print_simple(int dig)
{
	int mul = 2;
	while(dig/mul > 0)
		if(dig % mul==0)
		{
			dig /= mul;
			printf("%d ", mul);
			mul = 2;
		}
		else
			mul++;
}


int main(void)
{
	int dig;
	scanf("%d", &dig);
	print_simple(dig);
	return 0;
}
