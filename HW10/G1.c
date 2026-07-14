//В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.

#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp1 = fopen("input.txt", "r");
	
	char c;
	char buff[100];
	int i=0;
	while( (c = fgetc(fp1))!= '\n' )
		buff[i++] = c;
	buff[i]='\0';
	fclose(fp1);
	
	FILE *fp2 = fopen("output.txt", "w");
	fprintf(fp2, "%s, %s, %s %lld", buff, buff, buff, strlen(buff));
	fclose(fp2);
	//puts(buff);
	
	return 0;
}
