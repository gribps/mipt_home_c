//Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.

#include <stdio.h>
#include <inttypes.h>
#define SIZE 10

void buble_sort(int *arr, int size)
{
	int tmp;
	for(int i=0; i<size; i++)
		for(int j = size-1; j>i; j--)
			if(arr[j-1] > arr[j]){
				tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
}

int main(void)
{
	int arr[SIZE]={0};
	
	for(int i=0; i<SIZE; i++)
		scanf("%d", arr+i);
	buble_sort(arr, SIZE);
	
	//for(int i=0; i<SIZE; i++)	
	//	printf("%d ", *(arr+i));
		
	printf("%d\n", arr[SIZE-1] + arr[SIZE-2] );
	
	return 0;
}
