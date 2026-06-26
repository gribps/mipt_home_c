#include <stdio.h>

void func_2 (int dig, int p)
{
	if(dig/p > 0)
		func_2(dig/p, p);
	printf("%d", dig%p);	
}

int main(void)
{
	int dig, p;
	scanf("%d%d", &dig, &p);
	
	func_2(dig, p);
	
	return 0;
	
}

