//В файле input.txt символьная строка не более 1000 символов. 
//Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). 
//Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.

#include <stdio.h>
#include <string.h>

int is_palindrom(char *str)
{
	int len = strlen(str);
	for(int i=0; i<len/2; i++)
		if(str[i] != str[len-1-i])
			return 0;
	return 1;
}

int main(void)
{
	FILE *in = fopen("input.txt","r");
	if(in==NULL)
		return 1;
	FILE *out = fopen("output.txt","w");
	
	char str[1000] = "";
	fscanf(in, "%s", str);
	
	
	char *res = (is_palindrom(str))? "YES" : "NO";
	fprintf(out, "%s", res);
	
	fclose(in);
	fclose(out);
	
	return 0;
}
