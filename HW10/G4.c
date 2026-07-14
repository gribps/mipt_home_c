//В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. 
//Найдите только те символы слов, которые встречаются в обоих словах только один раз. 
//Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[100]="", str2[100]=""; 
	FILE *in = fopen("input.txt","r");
	FILE *out = fopen("output.txt","w");
	
	fscanf(in, "%s %s", str1, str2);
	
	int cnt1[256]={0};
	int cnt2[256]={0};
	
	for(int i=0; str1[i]!='\0'; i++)
	{
		unsigned char c = str1[i];
		cnt1[c]++;
	}
	
	for(int i=0; str2[i]!='\0'; i++)
	{
		unsigned char c = str2[i];
		cnt2[c]++;
	}
	
	for(int i=0; i<256; i++)
	{
		if(cnt1[i]==1 && cnt2[i]==1)
			fprintf(out, "%c ", i);
	}
	
	fclose(in);
	fclose(out);
	
	return 0;
}
