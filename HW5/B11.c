#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);

	if(a==0)
		printf("0");
	
	while(a != 0)
	{
		int dig = a%10;
		a /= 10;
		printf("%d", dig);
	}
	
	return 0;
}
