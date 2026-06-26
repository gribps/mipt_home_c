#include <stdio.h>

float power(float, int);
int factorial(int);
float sinus(float);

int main(void)
{
	int ang;
	scanf("%d", &ang);
	printf("%.3f", sinus((float)ang));
	return 0;
}


float sinus(float x)
{
	x = x/180*3.1415927;
	float res = x - power(x,3)/factorial(3) + power(x,5)/factorial(5) - 
				power(x,7)/factorial(7); 
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
