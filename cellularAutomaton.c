#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

static void calculate_next_state(PG* 2D);
		
void calculate_next_state(PG* 2D)
		{
			int leftIndicator;
			int rightIndicator;
			int neighbourhood[3];
			//Setting the left and right index so that the neibourhood is set to 3 cells
			for (int i = 0; i < 2D->noofcells; i++)
			{
				if (i == 0)		
					leftIndicator = 2D->noofcells - 1;
				else
					leftIndicator = i - 1;
				if (i == (2D->noofcells - 1))		
					rightIndicator = 0;
				else
					rightIndicator = i + 1;

				neighbourhood[0] = 2D->cells[leftIndicator];
				neighbourhood[1] = 2D->cells[i];
				neighbourhood[2] = 2D->cells[rightIndicator];
			}
\**
*=======================================
*\

int intToBin(int number) 
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

\**
*=======================================
*\


int returnValue(int ruleInBinary, int threeNum)
{

	int binaryArray[8];

	switch (threeNum)
	{
		case 000:
		if (binaryArray[7] == 0)
			return 0;
		else if (binaryArray[7] == 1)
			return 1;

		case 001:
		if (binaryArray[6] == 0)
			return 0;
		else if (binaryArray[6] == 1)
			return 1;

		case 010:
		if (binaryArray[5] == 0)
			return 0;
		else if (binaryArray[5] == 1)
			return 1;

		case 011:
		if (binaryArray[4] == 0)
			return 0;
		else if (binaryArray[4] == 1)
			return 1;

		case 100:
		if (binaryArray[3] == 0)
			return 0;
		else if (binaryArray[3] == 1)
			return 1;

		case 101:
		if (binaryArray[2] == 0)
			return 0;
		else if (binaryArray[2] == 1)
			return 1;

		case 110:
		if (binaryArray[1] == 0)
			return 0;
		else if (binaryArray[1] == 1)
			return 1;

		case 111:
		if (binaryArray[0] == 0)
			return 0;
		else if (binaryArray[0] == 1)
			return 1;
	}
}

====================
	
	
void main()
{
	int ruleInInt, width, height;
	
	printf("Cellular Automaton");
	
	printf("Enter the Rule: ");
	scanf("%d", &ruleInInt);
	
	printf("Enter the width of the grid: ");
	scanf("%d", &width);
	
	printf("Enter the height of the grid: ");
	scanf("%d", &height);
	
	int numArray[width][height];
	
	for(int i=0; i<width; i++)
		for(int j=0; j<height; j++)
			numArray[i][j]=0;
	
	numArray[width/2] = 1;
	
	for(int i=0; i<width; i++)
	{
		for(int j=0; j<height; j++)
		{
			printf("%d ",&numArray[i][j]);
		}
		printf("\n");
	}
}
	
	
	
