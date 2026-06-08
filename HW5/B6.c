#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	
	int dig = 10;
	while(a != 0)
	{
		int cur_dig = a%10;
		
		if(dig==cur_dig)
		{
			dig = 100;
			break;
		}
		
		a /= 10;
		dig = cur_dig;
	}

	dig==100? printf("YES") : printf("NO"); 
	
	return 0;
}
