#include <stdio.h>
#include <stdbool.h>


int main(void)
{
	int a;
	scanf("%d", &a);
	
	_Bool flag = true;
	
	if(a == 1)
		flag = false;
	else if(a == 2)
		flag = true;
	else if(a%2 == 0)
		flag = false;
	
	int d = 3;
	while(d*d <= a)
	{
		if(a%d == 0)
			flag = false;
	d += 2;
	}
	
	flag? printf("YES") : printf("NO");
	
	return 0;
}
