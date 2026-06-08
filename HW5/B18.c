#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	
	int prev = 1, curr = 1;
	int fib = prev + curr;
	if(a>1)
		printf("%d %d ", 1, 1);
	else
		printf("1");
	
	while(--a > 1)
	{
		printf("%d ", fib);
		prev = curr;
		curr = fib;
		fib = prev + curr; 
	} 
	
	return 0;
}
