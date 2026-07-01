// Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.

#include <stdio.h>
#include <inttypes.h>
#define SIZE 12


int main(void)
{
	int arr[SIZE]={0};
	
	for(int i=0; i<SIZE; i++)
		scanf("%d", arr+i);
	
	for(int i=0; i<4; i++)
	{
		int tmp = arr[SIZE-1];
		for(int j = SIZE-1; j>0; j--)
			arr[j] = arr[j-1];
		arr[0] = tmp;
	}
	
	for(int i=0; i<SIZE; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
