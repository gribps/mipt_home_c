//В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. 
//Результат записать в output.txt.

#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *in = fopen("input.txt","r");
	FILE *out = fopen("output.txt","w");
	
	char c;
	while( (c = fgetc(in)) != EOF ){
		if(c == 'a' || c == 'A')
			fputc(c+1, out);
		else if( c == 'b' || c == 'B')
			fputc(c-1, out);
		else
			fputc(c, out);
	}
	
	fclose(in);
	fclose(out);
	return 0;
}
