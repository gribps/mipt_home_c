#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	
	int m1 = a%10;
	int m2 = a/10%10;
	int m3 = a/100%10;
	
	printf("%d", m1+m2+m3);
	
	return 0;
}
