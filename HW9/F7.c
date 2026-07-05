//  int compression(int a[], int b[], int N)

#include <stdio.h>
#include <string.h>
#define SIZE 1000


int compression(int a[], int b[], int N)
{
	int cnt_change = 0;
	int cnt_repeat = 0;
	
	if(a[0]==1)
		{
			b[0]=0;
			cnt_change++;
		}
	
	for(int i=0; i<N-1; i++)
	{
		if(a[i]!=a[i+1])
		{
			b[cnt_change] = cnt_repeat+1;
			cnt_repeat = 0;
			cnt_change++;
		}
		else
			cnt_repeat++;
			
	}
	b[cnt_change] = cnt_repeat+1;

	return cnt_change+1;
}
	
int main(void)
{
	int arr_1[SIZE] = {0};
	int arr_2[SIZE] = {0};
	int cnt = 0;
	char c;
	
	while(scanf("%d%c", arr_1+cnt, &c))
		{
			cnt++;
			if(c == '\n')
				break;
		}
	
	int size_arr_2 = compression(arr_1, arr_2, cnt);
	
	for(int i=0; i<size_arr_2; i++)
		if(i==0)
			printf("[%d,", arr_2[i]);
		else if(i==size_arr_2-1)
			printf("%d]", arr_2[i]);
		else
			printf("%d,", arr_2[i]);
	
	return 0;
}
