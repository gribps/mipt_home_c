//Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.

#include <stdio.h>
#include <inttypes.h>
#define SIZE 5

int main(void)
{
	int arr[SIZE]={0};
	int min = INT32_MAX;
	
	for(int i=0; i<5; i++)
	{
		scanf("%d", arr+i);
		min = (arr[i]<min)? arr[i] : min;
	}
	
	printf("%d\n", min);
	
	return 0;
}
