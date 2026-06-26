#include <stdio.h>

int sum_n (int dig)
{
	int sum = 0;
	for(int i = 1; i<=dig; i++)
		sum += i;
	return sum;
} 

int main(void)
{
	int dig;
	scanf("%d", &dig);
	printf("%d\n", sum_n(dig));
	return 0;
}
