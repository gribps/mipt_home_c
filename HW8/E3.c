//Считать массив из 10 элементов и найти в нем максимальный и минимальный элементы и их номера.

#include <stdio.h>
#include <inttypes.h>
#define SIZE 10

int main(void)
{
	int arr[SIZE]={0};
	int min = INT32_MAX;
	int max = INT32_MIN;
	int max_pos, min_pos;
	
	for(int i=0; i<SIZE; i++)
	{
		scanf("%d", arr+i);
		if(arr[i] < min){
			min = arr[i];
			min_pos = i+1;
		}
		if(arr[i] > max){
			max = arr[i];
			max_pos = i+1;
		}
	}
	
	printf("%d %d %d %d\n", max_pos, max, min_pos, min);
	
	return 0;
}
