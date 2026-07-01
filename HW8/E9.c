//Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.

#include <stdio.h>
#include <inttypes.h>
#define SIZE 10


int main(void)
{
	int arr[SIZE]={0};
	
	for(int i=0; i<SIZE; i++)
		scanf("%d", arr+i);
	
	int tmp = arr[SIZE-1];
	for(int i = SIZE-1; i>0; i--)
		arr[i] = arr[i-1];
	arr[0] = tmp;
				
	for(int i=0; i<SIZE; i++)
		printf("%d ", arr[i]);

	return 0;
}
