//В файле input.txt дана строка слов, разделенных пробелами. 
//Найти самое длинное слово и вывести его в файл output.txt. 
//Случай, когда самых длинных слов может быть несколько, не обрабатывать.

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
		
	// чтение строки
	char str[1002] = "";
	fgets(str, sizeof(str), in);
	// пробел в конец строки на случай одного слова
	str[strlen(str)] = ' ';
	
	// вычисление длины слова через адресную арифметику
	char buff[1002]="";
	
	char *ptr = str;
	char *tmp = str;
	int max_len = 0;
	while( (ptr=strchr(ptr,' ')) != NULL )
	{
		if(ptr-tmp > max_len)
		{
			max_len = ptr-tmp;
			
			for(int i=0; i<max_len;i++)
				buff[i] = *(tmp+i);
			
			tmp = ++ptr;
		}
		/*
		if(ptr-tmp == max_len)
		{
			fclose(in);
			fclose(out);
			return 0;
		}
		*/
		ptr++;
	}
	//запись
	fprintf(out, "%s", buff);
		
	fclose(in);
	fclose(out);
	return 0;
}
