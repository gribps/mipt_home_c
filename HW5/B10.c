#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	
	int dig=10;
	int cnt = 0; 
	
	while(a != 0)
	{
		int cur_dig = a%10;
		a /= 10;
		
		if(cur_dig < dig)
			dig = cur_dig;
		else 
			cnt++;
	}

	cnt==0? printf("YES") : printf("NO");
	
	return 0;
}
