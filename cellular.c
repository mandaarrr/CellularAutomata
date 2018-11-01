#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{
	int ruleInInt, width, height;

	printf("Cellular Automaton");

	printf("Enter the Rule: ");
	scanf("%d", &ruleInInt);

	int binaryArray[8];  // The array to store the binary number
	int temp = 0;

	while(temp<8)
	{
		binaryArray[7-temp] = ruleInInt%2;
		ruleInInt /= 2;
		temp++;
	}

	printf("Enter the width of the grid: ");
	scanf("%d", &width);

	printf("Enter the height of the grid: ");
	scanf("%d", &height);

	int numArray[height][width];

	for (int i = 0; i < height; i++)
		for(int j=0; j<width; j++)
			numArray[i][j]=0;

	numArray[0][width/2] = 1;


//Looping and skipping the edge cells
for (int i = 1; i < height; i++)
  {
  	for (int j = 0; j < width; j++)
 	 {
	//Add up all the neighbor states to calculate the number of neighbors.

			int patternInt = 0;

			if (j==width)
			{
				if (numArray[i-1][j-1] == 0)
					patternInt += 4;
				if (numArray[i-1][j] == 0)
					patternInt += 2;

				patternInt += 1;
			}
			else if (j==0)
			{
				patternInt += 4;

				if (numArray[i-1][j] == 0)
					patternInt += 2;
				if (numArray[i-1][j+1] == 0)
					patternInt += 1;
			}
			else
			{
				if (numArray[i-1][j-1] == 0)
					patternInt += 4;
				if (numArray[i-1][j] == 0)
					patternInt += 2;
				if (numArray[i-1][j+1] == 0)
					patternInt += 1;
				}

			if (binaryArray[patternInt] == 0)
				numArray[i][j] = 0;
			else if (binaryArray[patternInt] == 1)
				numArray[i][j] = 1;
		}
	}

	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if (numArray[i][j] == 1)
				printf("\u25A0 ");
			else if (numArray[i][j] == 0)
				printf("  ");
		}
		printf("\n");
	}



}
