#include <stdio.h>

int main()
{
	float f = 4.5;
	
//	int i = f;
	
	float *fp = &f;
	
	int i;
	int *ip;
	
	ip = (int *)fp;
	
	i = *ip;
	
	printf("%032b\n", i);
	
	/*------------------------------*/
	i = 0b0'10000101'000'0110'0001'1000'0000'0000;

	ip = &i;
	
	fp = (float *)ip;

	f = *fp;
	
	printf("%f\n", f);
}
