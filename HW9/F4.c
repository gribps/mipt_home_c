//void print_digit(char s[])

#include <stdio.h>
#include <string.h>
#define SIZE 1000

void print_digit(char s[])
{
	int cnt;
	char *ptr;
	
	for(int i=0; i<=9; i++)
	{
		cnt = 0;
		ptr = s;
	
		while( (ptr=strchr(ptr, i+0x30)) != NULL)
		{
			cnt++;
			ptr++;
		}
		
		if(cnt)
			printf("%d %d\n", i, cnt);
	}	
}

int main(void)
{
	char s[SIZE] = "";
	scanf("%s", s);
	
	print_digit(s);
	
	return 0;
}
