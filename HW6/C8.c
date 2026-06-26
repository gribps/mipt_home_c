#include <stdio.h>

int main(void)
{
	char c;
	while( (c=getchar()) != '.')
	{
		if(c>=0x61 && c<=0x7A)
			putchar(c - 0x20);
		else
			putchar(c);
	}
		
	return 0;
}
