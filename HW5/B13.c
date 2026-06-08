#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);


	int cnt_1 = 0;
	int cnt_2 = 0;
	
	while(a != 0)
	{
		int dig = a%10;
		a /= 10;
		
		if(dig%2 == 0)
			cnt_1++;
		else
			cnt_2++;
	}
	
	printf("%d %d", cnt_1, cnt_2);
	return 0;
}
