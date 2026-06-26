#include <stdio.h>

int get_abs (int);

int main(void)
{
	int num;
	scanf("%d", &num);
	printf("%d\n",get_abs(num));
	return 0;
}

int get_abs (int num)
{
	return num>0? num : -num;
}
