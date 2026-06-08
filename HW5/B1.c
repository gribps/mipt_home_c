#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	
	for(int i=1; i<=num; i++)
	{
		printf("%d %d %d\n", i, i*i, i*i*i);
	}
	return 0;
}
