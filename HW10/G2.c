#include <stdio.h>

int main(void)
{
	FILE *f1 = fopen("input.txt","r");
	int num; 
	fscanf(f1, "%d", &num);
	fclose(f1);
	//printf("%d\n", num);
	
	FILE *f2 = fopen("output.txt","w");
	char c;
	char buff[] = "2468"; int j=0;
	for(int i=1; i<num+1; i++){
		if(i%2==0)
			c = buff[j++%4];
		else
			c = (i+1)/2 + 0x40;
			
		fputc(c, f2);
	}
	fclose(f2);
	
	printf("%c %c %c %c\n", buff[0], buff[1], buff[2], buff[3]);
	return 0;
}
