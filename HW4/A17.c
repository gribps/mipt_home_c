#include <stdio.h>

int main(void)
{
	int num;
	scanf("%d", &num);
	
	if(num >=9 && num <=11)
		printf("autumn");
	else if (num >= 3 && num <= 5)
		printf("spring");
	else if (num >= 6 && num <= 8)
		printf("summer");
	else
		printf("winter");
	return 0;
}
