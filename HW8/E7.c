//Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. 

#include <stdio.h>
#include <inttypes.h>
#define SIZE 10


int main(void)
{
	int arr[SIZE]={0};
	
	for(int i=0; i<SIZE; i++)
		scanf("%d", arr+i);
		
	for(int i=0; i<SIZE; i++)
		if(i<SIZE/2)
			printf("%d ", arr[SIZE/2 - 1 - i]);
		else
			printf("%d ", arr[SIZE + SIZE/2 - 1 - i]);
	
	return 0;
}
