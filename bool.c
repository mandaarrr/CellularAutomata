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

int intToBin(int number) 
{
	for (int i = 7; i >= 0; i--) 
	{
		if (number > power(2, i))
		{
			printf("1");
			number -= power(2, i);
		}
		else 
		{
			printf("0");
		}
	}

	return 1;
}

void printBlock(int data) 
{
	if (data==1)
		printf("\u25A0 ");
	else
		printf("  ");
}

int main() 
{
/*
	int test[8];

	intToBin(64);

	for (int i=0; i<8; i++) 
	{
		printf("%i ", test[i]);
	}*/
	
	for (int u=0; u<16; u++)
	{
		for (int i=0; i<u; i++)
		{
			printBlock(i%2);
		}
		printf("\n");
	}
	
}





