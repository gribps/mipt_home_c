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
		
		if(dig == 9)
			cnt++;
	}

	cnt==1? printf("YES") : printf("NO");
	
	return 0;
}
