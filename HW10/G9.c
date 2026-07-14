//В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов. 
//Требуется удалить из нее повторяющиеся символы и все пробелы. 
//Результат записать в файл output.txt.

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
	char str[1000] = "";
	fgets(str, sizeof(str), in);
	
	char *ptr = str;
	
	// удалить пробелы
	char *tmp;
	while( (ptr = strchr(ptr, ' ')) !=NULL )
	{
		tmp = ptr;
		while(*tmp != '\0')
		{
			*tmp = *(tmp+1);
			tmp++;
		}
	}
	
	// удалить повторы
	int len = strlen(str);
	for(int i=0; i<len; i++)
	{
		ptr = &str[i+1];
		while( (ptr = strchr(ptr, str[i])) != NULL )
		{
			tmp = ptr;
			while(*tmp != '\0')
			{
				*tmp = *(tmp+1);
				tmp++;
			}
			len--;
		}
	}
	
	//запись
	fprintf(out, "%s", str);
	
		
	fclose(in);
	fclose(out);
	return 0;
}
