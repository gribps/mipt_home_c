//В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. 
//Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. 
//Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. 
//Вывести массив по возрастанию в файл output.txt.

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
	
	// чтение в цифр из файла в строку через пробел
	char c;
	int flag = 0;
	char str[1000]="";;
	char *ptr_s = str;
	while( (c=fgetc(in))!= '\n')
	{
		if(c>='0' && c<='9')
		{
			*ptr_s++ = c;
			flag = 1;
		}
		else if(flag==1)
		{
			*ptr_s++ = ' ';
			flag = 0;
		}
	}

	// преобразование строки в массив int
	int dig[1000]={0};
	int cnt = 0;
	int n_byte = 0;
	ptr_s = str;
	while(sscanf(ptr_s, "%d%n", &dig[cnt], &n_byte)==1)
	{
		ptr_s += n_byte;
		cnt++;
	}
	
	// сортировка и запись в файл
	for(int i=0; i<cnt; i++)
	{
		for(int j=cnt-1; j>i; j--)
			if(dig[j-1] > dig[j])
				{
					int tmp = dig[j-1];
					dig[j-1] = dig[j];
					dig[j] = tmp;
				}
		fprintf(out, "%d ", dig[i]);
	}
	
	
	fclose(in);
	fclose(out);
	return 0;
}
