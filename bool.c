#include <stdio.h>

int power(int num, int pwr)
{
	int ans = 1;
	for (int i = 0; i < pwr; i++)
	{
		ans *= num;
	}

	return ans;
}

void intToBin(int number, int * binary) 
{

	for (int i = 7; i >= 0; i--) 
	{
		if (number > power(2, i))
		{
			binary[i] = 1;
			number -= power(2, i);
		}
		else 
		{
			binary[i] = 0;
		}
	}
}