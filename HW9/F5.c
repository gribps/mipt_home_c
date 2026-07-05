// int find_max_array(int size, int a[])

#include <stdio.h>
#include <string.h>
#define SIZE 1000

int find_max_array(int size, int a[])
{
	int max = a[0];
	for(int i=1; i<size; i++)
		if(a[i] > max)
			max = a[i];
	return max;
}

int main(void)
{
	int arr[SIZE] = {0};
	int cnt = 0;
	char c;
	
	while(scanf("%d%c", arr+cnt, &c))
		{
			cnt++;
			if(c == '\n')
				break;
		}
		
	printf("%d\n", find_max_array(cnt, arr));
	
	return 0;
}
