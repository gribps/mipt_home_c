#include <stdio.h>

float power(float, int);
int factorial(int);
float cosinus(float);

int main(void)
{
	int ang;
	scanf("%d", &ang);
	printf("%.3f", cosinus((float)ang));
	return 0;
}


float cosinus(float x)
{
	x = x/180*3.1415927;
	float res = 1 - power(x,2)/factorial(2) + power(x,4)/factorial(4) - 
				power(x,6)/factorial(6); 
	return res;
}

float power(float num, int pow)
{
	if (pow==0)
		return 1;
	
	float res = 1;
	for(; pow>0; pow--)
		res *= num;
	return res;
}

int factorial(int dig)
{
	if (dig == 0)
		return 1;
	
	int res=1;
	for(;dig > 0; dig--)
		res *= dig;
	
	return res;
}

