//Считать массив из 10 элементов и посчитать сумму положительных элементов массива.

#include <stdio.h>
#include <inttypes.h>
#define SIZE 10


int main(void)
{
	int arr[SIZE]={0};
	int sum = 0;
	
	for(int i=0; i<SIZE; i++){
		scanf("%d", arr+i);
		sum += (arr[i]>0)? arr[i] : 0;
	}
		
		
	printf("%d\n", sum );
	
	return 0;
}
