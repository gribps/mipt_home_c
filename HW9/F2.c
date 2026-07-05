//void sort_even_odd(int n, int a[])

#include <stdio.h>
//#include <stdbool.h>
#define SIZE 100

void sort_even_odd(int size, int a[])
{
	int n_even = 0;
	for(int i=0; i<size;i++)
		if(a[i]%2==0)
			n_even++;
	
	int tmp, cnt=0;
	for(int i=0; i<n_even; i++)
	{
		while(a[i+cnt]%2 != 0 && i<size)
			{
				cnt++;
			}
		if(cnt)
		{
			for(; cnt > 0; cnt--)
			{
				tmp = a[i+cnt];
				a[i+cnt] = a[i+cnt-1];
				a[i+cnt-1] = tmp;
			}
			cnt = 0;
		}
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

	sort_even_odd(n, arr);
	
	printf("%d\n", n);
	for(int i = 0; i<n; i++)
		printf("%d ", arr[i]);
	
	return 0;
}
