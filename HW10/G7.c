#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *in = fopen("input.txt","r");
	if(in==NULL)
		return 1;
	FILE *out = fopen("output.txt","w");
	if(out==NULL)
		return 1;
		
	char str[10001] = "";
	fgets(str, sizeof(str), in);
	
	int cnt1=0;
	int cnt2=0;
	for(int i=0; i<strlen(str); i++)
	{
		if(str[i]>=0x61 && str[i] <=0x7A)
			cnt1++;
		if(str[i]>=0x41 && str[i] <=0x5A)
			cnt2++;
	}
	
	fprintf(out, "%d %d", cnt1, cnt2);
	
	fclose(in);
	fclose(out);
	return 0;
}
	
