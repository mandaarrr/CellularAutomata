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
for (int i = 1; i < height-1; i++)
  {
  	for (int j = 1; j < width-1; j++)
 	 {
	//Add up all the neighbor states to calculate the number of neighbors.
    	int pattern[3];
    	pattern[0] = numArray[i-1][j-1];
    	pattern[1] = numArray[i-1][j];
    	pattern[2] = numArray[i-1][j+1];

    	int patternInt = (pattern[0]*100 + pattern[1]*10 + pattern[2]);

    	switch(patternInt)
    	{
			case 000:
			if (binaryArray[7] == 0)
				numArray[i][j] = 1;
			else if (binaryArray[7] == 1)
				numArray[i][j] = 1;

			case 001:
			if (binaryArray[6] == 0)
				numArray[i][j] =  0;
			else if (binaryArray[6] == 1)
				numArray[i][j] =  1;

			case 010:
			if (binaryArray[5] == 0)
				numArray[i][j] =  0;
			else if (binaryArray[5] ==1)
				numArray[i][j] =  1;

			case 011:
			if (binaryArray[4] == 0)
				numArray[i][j] =  0;
			else if (binaryArray[4] == 1)
				numArray[i][j] =  1;

			case 100:
			if (binaryArray[3] == 0)
				numArray[i][j] =  0;
			else if (binaryArray[3] == 1)
				numArray[i][j] =  1;

			case 101:
			if (binaryArray[2] == 0)
				numArray[i][j] =  0;
			else if (binaryArray[2] == 1)
				numArray[i][j] =  1;

			case 110:
			if (binaryArray[1] == 0)
				numArray[i][j] =  0;
			else if (binaryArray[1] == 1)
				numArray[i][j] =  1;

			case 111:
			if (binaryArray[0] == 0)
				numArray[i][j] =  0;
			else if (binaryArray[0] == 1)
				numArray[i][j] =  1;
		}
	}
}





	
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			printf("%d ",numArray[i][j]);
		}
		printf("\n");
	}








	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			if (numArray[i][j] == 1)
				printf("\u25A0 ");
			else if (numArray[i][j] == 0)
				printf("\u25A1 ");
		}
		printf("\n");
	}



}