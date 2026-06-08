#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);


	int max = -1;
	int min = 99999;
	
	while(a != 0)
	{
		int dig = a%10;
		a /= 10;
		
		if(dig >= max)
			max = dig;
		if(dig <= min)
			min = dig;
	}
	
	printf("%d %d", min, max);
	return 0;
}
