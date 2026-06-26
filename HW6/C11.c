#include <stdio.h>

int nod(int n1, int n2)
{
	while(n2 != 0)
	{
		int tmp = n2;
		n2 = n1 % n2;
		n1 = tmp;
	}
	return n1;
}


int main(void)
{
	int n1, n2;
	scanf("%d%d", &n1, &n2);
	printf("%d", nod(n1, n2));
	return 0;
}

