#include <stdio.h>

int main(void)
{
	int a;
	int cnt=0;
	
	scanf("%d", &a);
	while(a!=0)
	{
		cnt++;
		scanf("%d", &a);
	}

	printf("%d", cnt);

	return 0;
}
