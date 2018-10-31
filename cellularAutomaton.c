#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>

//some values to initialise PG
tyoedef struct PG PG;
struct PG
{
	char* cells;
	char* next_state;
	int noofcells;
	unsigned char rule;
	char binaryRule[9];
	void(*onchange)(PG* 2D);
};
//Functions that create and start the PG and frees the memory
PG* PG_init(int cellcount, char* init_pattern, unsigned char rule, void(*onchange)(PG* 2D));
void PG_start(PG * 2D);
void PG_free(PG * 2D);





static void calculate_next_state(PG* 2D);

PG* PG_init(int noofcells, char* init_pattern, unsigned char rule, void(*onchange)(PG* 2D))
//Used malloc to get memory from the structure and set it's member values
{
	PG* 2D = malloc(sizeof(PG));

	if (2D != NULL)
	{
		*2D = (PG) {
			.cells = malloc(noofcells * sizeof(int)),
				.next_state = malloc(noofcells * sizeof(int)),
				.noofcells = noofcells,
				.rule = rule,
				.binaryRule = "",
				.onchange = onchange
		};

		void calculate_next_state(PG* 2D)
		{
			int leftIndicator;
			int rightIndicator;
			int neighbourhood[4];
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
\**
*=======================================
*\

int number     // The number you want to convert
int binary[8]  // The array to store the binary number

	for (int i = 7; i >= 0; i--)
	{
		if (number > pow(2, i))
		{
			binary[i] = 1;
			number -= pow(2, i);
		}
		else
		{
			binary[i] = 0;
		}
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
