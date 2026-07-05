#include <stdio.h>
#define SIZE 1000

void swap_negmax_last(int size, int a[])
{
	int negmax = 1 << (sizeof(int)*8 -1);
	int pos = -1;
	
	for(int i=0; i<size; i++)
	{
		if( a[i]>=negmax && a[i]<0)
		{
			negmax = a[i];
			pos = i;
		}			
	}
	
	int tmp;
	if(pos!=-1)
	{
		tmp = a[pos];
		a[pos] = a[size-1];
		a[size-1] = tmp;
	}
}


int main(void)
{
	int arr[SIZE] = {0};
	int cnt = 0;
	char c;
	
	while( scanf("%d%c", arr+cnt, &c))
	{
		cnt++;
		if(c=='\n')
			break;
	}
	
	swap_negmax_last(cnt, arr);

	
	//printf("%llu\n", sizeof(int));	
	for(int i=0; i<cnt; i++)
		printf("%d ", arr[i]);
	
	
	
	return 0;
}
