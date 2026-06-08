#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	
	int dig;
	int cnt = 0; 
	
	while(a != 0)
	{
		dig = a%10;
		a /= 10;
		
		if(dig%2 != 0)
			cnt++;
	}

	cnt==0? printf("YES") : printf("NO");
	
	return 0;
}
