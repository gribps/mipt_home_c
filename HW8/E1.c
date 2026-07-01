//Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

#include <stdio.h>
#define SIZE_ARR 5

int main(void)
{
	float arr[SIZE_ARR]={0};
	float sum = 0;
	
	for(int i=0; i<5; i++)
	{
		scanf("%f", arr+i);
		sum += arr[i];
	}
	
	printf("%.3f\n", sum/SIZE_ARR);
	
	return 0;
}
