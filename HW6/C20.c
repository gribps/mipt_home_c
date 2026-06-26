//Проверить строку состоящую из скобок "(" и ")" на корректность.

#include <stdio.h>

int func_5(char c)
{
	if(c == 0x28) 
		return 1;
	else if (c == 0x29)
		return -1;
	else
		return 0;
}

int main(void)
{
	char c;
	int sum = 0;
	while( (c = getchar()) != '\n')
	{
		sum += func_5(c);
		if( sum < 0 )
			break;
	}
	(sum==0)? printf("YES\n") : printf("NO\n");
	
	return 0;
}
