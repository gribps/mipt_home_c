//В файле input.txt дано предложение. 
//Необходимо определить, сколько слов заканчиваются на букву 'а'. 
//Ответ записать в файл output.txt.

#include <stdio.h>
#include <string.h>

enum {len = 1001};

int main(void)
{
	FILE *in = fopen("input.txt", "r");
		if(in == NULL)
			return 1;
	FILE *out = fopen("output.txt", "w");
		if(out == NULL)
			return 1;
			
	char buff[len] = "";
	fgets(buff, sizeof(buff), in);
	
	char *ptr;
	if( (ptr=strchr(buff, '\n'))!=NULL)
		*ptr = '\0';
	
	int flag = 0;
	for(int i=0; buff[i]; i++)
	{
		if(buff[i] == ' ')
			flag = 0;
		else if(flag == 0)
		{
			flag = 1;
			int word_len = 0;
			
			while(buff[i+word_len] != '\0' && buff[i+word_len] != ' ')
				word_len++;
			 
			fprintf(out, "%.*s\n", word_len, &buff[i]);
		}
	}
	
	fclose(in);
	fclose(out);
	
	return 0;
} 

