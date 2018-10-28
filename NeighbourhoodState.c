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
			.cells = malloc(noofcells * sizeof(char)),
				.next_state = malloc(noofcells * sizeof(char)),
				.noofcells = noofcells,
				.rule = rule,
				.binaryRule = "",
				.onchange = onchange
		};
		
		void calculate_next_state(PG* 2D)
		{
			int leftIndicator;
			int rightIndicator;
			char neighbourhood[4];
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
				neighbourhood[3] = '\0';
				//And than the if/else statements to check in which state the neibourhood is in
				if (strcmp(neighbourhood, "111") == 0)
					2D->next_state[i] = 2D->binaryRule[0];
				else if (strcmp(neighbourhood, "110") == 0)
					2D->next_state[i] = 2D->binaryRule[1];
				else if (strcmp(neighbourhood, "101") == 0)
					2D->next_state[i] = 2D->binaryRule[2];
				else if (strcmp(neighbourhood, "100") == 0)
					2D->next_state[i] = 2D->binaryRule[3];
				else if (strcmp(neighbourhood, "011") == 0)
					2D->next_state[i] = 2D->binaryRule[4];
				else if (strcmp(neighbourhood, "010") == 0)
					2D->next_state[i] = 2D->binaryRule[5];
				else if (strcmp(neighbourhood, "001") == 0)
					2D->next_state[i] = 2D->binaryRule[6];
				else if (strcmp(neighbourhood, "000") == 0)
					2D->next_state[i] = 2D->binaryRule[7];
			}

			// Then we copy the next state to the current one
			for (int i = 0; i < 2D->noofcells; 2D->cells[i] = 2D->next_state[i], i++);
		};