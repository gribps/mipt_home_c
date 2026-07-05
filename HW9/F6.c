// int is_two_same(int size, int a[]);

#include <stdio.h>
#include <string.h>
#define SIZE 1000

int is_two_same(int size, int a[])
{
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
			if(a[i]==a[j])
				return 1;
	}
	
	return 0;
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
		
	(is_two_same(cnt, arr))? printf("YES\n") : printf("NO\n");
	
	return 0;
}
