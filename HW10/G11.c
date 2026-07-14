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
	
	int cnt = 0;
	ptr = buff;
	while( (ptr=strchr(ptr, 'a'))!=NULL )
	{
		if(*(ptr+1) == ' ' || *(ptr+1) == '\0')
			cnt++;
		ptr++;
	}

	fprintf(out, "%d", cnt);
	
	fclose(in);
	fclose(out);
	
	return 0;
} 
