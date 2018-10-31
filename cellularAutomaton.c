#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>


int[][] next = new int[heights][widths];
 
//Looping and skipping the edge cells
for (int x = 1; x < columns-1; x++) {
  for (int y = 1; y < rows-1; y++) {

 
//Add up all the neighbor states to calculate the number of neighbors.
    int neighbors = 0;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        neighbors += board[x+i][y+j];
      }
    }
 
 //subtracting the cell state itself.
    neighbors -= board[x][y];
 
    if      ((board[x][y] == 1) && (neighbors <  2)) next[x][y] = 0;
    else if ((board[x][y] == 1) && (neighbors >  3)) next[x][y] = 0;
    else if ((board[x][y] == 0) && (neighbors == 3)) next[x][y] = 1;
    else next[x][y] = board[x][y];
	
	
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
	
	
	
