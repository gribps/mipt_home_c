//Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу.

#include <stdio.h>

void func_3(int dig)
{
	int res = 0;
	
	while(dig > 0 )
		{
			res += dig%10;
			dig /= 10;
		}
	(res%2==0)? printf("YES\n") : printf("NO\n");
}

int main(void)
{
	int dig;
	scanf("%d", &dig);
	func_3(dig);
	return 0;
}
