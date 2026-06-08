#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	
	
	int cnt = 0;
	while(a != 0 && cnt <=3)
	{
		a /= 10;
		cnt++;
	}

	cnt == 3? printf("YES") : printf("NO"); 
	
	return 0;
}
