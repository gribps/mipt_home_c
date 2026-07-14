//В файле input.txt дана строка из не более 1000 символов. Показать номера символов, совпадающих с последним символом строки.
//Результат записать в файл output.txt

#include <stdio.h>
#include <string.h>

int main(void)
{
	char c_end;
	FILE *f1 = fopen("input.txt", "r");
	if(f1 == NULL)
		return 1;
		
	fseek(f1, -2, SEEK_END);
	c_end = fgetc(f1);
	int len = ftell(f1);
	//putchar(c_end);
	//printf("\n%d", len);
	
	FILE *f2 = fopen("output.txt","w");
		if(f2 == NULL)
			return 1;
	
	char c;
	fseek(f1, 0, SEEK_SET);
	for(int i = 0; i < len-1; i++){
		c = fgetc(f1);
		if(c == c_end){
			//printf("%d ", i);
			fprintf(f2, "%d ", i);
		}
	}

	fclose(f1);
	fclose(f2);
	return 0;
}
