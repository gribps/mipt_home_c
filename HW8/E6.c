//Считать массив из 12 элементов и посчитать среднее арифметическое элементов массива.

#include <stdio.h>
#include <inttypes.h>
#define SIZE 12


int main(void)
{
	int arr[SIZE]={0};
	float sum = 0;
	
	for(int i=0; i<SIZE; i++){
		scanf("%d", arr+i);
		sum += arr[i];
	}
		
	printf("%.2f\n", sum/(sizeof(arr)/sizeof(arr[0])));
	
	return 0;
}
