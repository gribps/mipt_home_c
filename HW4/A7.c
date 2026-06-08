#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int a, b;
	scanf("%d%d", &a, &b);
	
	if(a < b)
		printf("%d %d", a, b);
	else
		printf("%d %d", b, a);
	
	return 0;
}
