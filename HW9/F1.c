//void sort_array(int size, int a[])

#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

void sort_array(int size, int a[])
{
	int tmp;
	int flag = 1;
	
	for(int i=0; i<size; i++)
	{
		for(int j=size-1; j>i; j--)
			if(a[j-1] > a[j])
				{
					tmp = a[j-1];
					a[j-1] = a[j];
					a[j] = tmp;
					flag = 0;
				}
		if(flag)
			break;
	}
}

int main(void)
{
	int arr[100]={0};
	//int *ptr_arr = arr;
	char c;
	int n = 0;
	
	while(scanf("%d%c", arr+n, &c))
	{
		n++;
		if( c == '\n')
			break;
	}

	sort_array(n, arr);
	
	printf("%d\n", n);
	for(int i = 0; i<n; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
