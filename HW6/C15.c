//Составить функцию логическую функцию, которая определяет,
// верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу. int grow_up(int n)

#include <stdio.h>

void func_3(int dig)
{
	int res = 9, flag = 0;
	
	while(dig > 0 )
		{
			int tmp = dig%10;
			
			if(tmp < res)
				res = tmp;
			else
				flag = 1;
				
			dig /= 10;
		}
		
	(flag==0)? printf("YES\n") : printf("NO\n");
}

int main(void)
{
	int dig;
	scanf("%d", &dig);
	func_3(dig);
	return 0;
}

