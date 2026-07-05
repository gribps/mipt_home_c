#include <stdio.h>
#define SIZE 1000

void sort_array(int size, int a[]);

int main(void)
{
	int arr[SIZE] = {0};
	int cnt = 0;
	
	while( scanf("%d", arr+cnt) && arr[cnt]!=0)
		cnt++;
	
	sort_array(cnt, arr);
		
	for(int i=0; i<cnt-1; i++)
		if(arr[i+1]-arr[i] > 1)
		{
			printf("%d\n", arr[i]+1);
			break;
		}
	
	return 0;
}

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
