#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main(void)
{
	char s_in[SIZE]="", s_out[SIZE]="";
	
	scanf("%s", s_in);
	char *ptr_in = strchr(s_in, '.');
	*ptr_in = 0;
	
	int cnt=0;
	char *ptr_out = s_out;
	
	for(int len = 0; len < strlen(s_in);)
	{
		ptr_in = s_in;
		cnt = 0;
		
		while( (ptr_in = strchr(ptr_in, s_in[len])) != NULL)
		{
			cnt++;
			ptr_in++;
		}

	*ptr_out++ = s_in[len];
	sprintf(ptr_out, "%d", cnt);
	ptr_out = strchr(ptr_out, 0);
	len+=cnt;
	}


	printf("%s\n", s_out);
	
	return 0;
}
