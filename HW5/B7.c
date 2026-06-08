#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	
	int dig;
	int n0=0, n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0;  
	
	while(a != 0)
	{
		dig = a%10;
		
		switch(dig)
		{
		case 0: n0++; break;
		case 1: n1++; break;
		case 2: n2++; break;
		case 3: n3++; break;
		case 4: n4++; break;
		case 5: n5++; break;
		case 6: n6++; break;
		case 7: n7++; break;
		case 8: n8++; break;
		case 9: n9++; break;
		}

		a /= 10;
	}

	if(n0>1||n1>1||n2>1||n3>1||n4>1||n5>1||n6>1||n7>1||n8>1||n9>1)
		printf("YES");
	else
		printf("NO");
	
	return 0;
}
