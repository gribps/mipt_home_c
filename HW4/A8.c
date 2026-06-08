#include <stdio.h>
#include <inttypes.h>

int main(void)
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	
	int max = a>b? a : b;
	max = max>c? max : c;
	printf("%d\n", max);
	
	return 0;
}
