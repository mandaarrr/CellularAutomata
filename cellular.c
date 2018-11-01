#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void generateUserPattern()
{
	int ruleInInt, width, height;

	printf("\nEnter the Rule: ");
	scanf("%d", &ruleInInt);

	int binaryArray[8];  // The array to store the binary number
	int temp = 0;

	int intForConversion = ruleInInt;

	while(temp<8)
	{
		binaryArray[7-temp] = intForConversion%2;
		intForConversion /= 2;
		temp++;
	}

	printf("\nEnter the length of the generation: ");
	scanf("%d", &width);

	printf("Enter the number of generations: ");
	scanf("%d", &height);

	int numArray[height][width];

	for (int i = 0; i < height; i++)
		for(int j=0; j<width; j++)
			numArray[i][j]=0;

	numArray[0][width/2] = 1;

	printf("\nThis is Rule %d \n",ruleInInt);


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


	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\nDo you want to save this pattern? Press 1 to Save. Any other number to return to Main Menu\nYour Choice: ");
	int saveChoice;
	scanf("%d",&saveChoice);

	switch(saveChoice)
	{

		case 1:

			{

				FILE* fileP = malloc(sizeof(FILE));

				fileP = fopen("output", "w");

				if (fileP == NULL)
				{
					printf("File cannot be accessed.");
					exit(1);
				}

				fprintf(fileP, "Rule %i\n", ruleInInt);

				for (int i=0; i<height; i++)
				{
					for (int j=0; j<width; j++)
					{
						if (numArray[i][j] == 1)
							fprintf(fileP, "\u25A0 ");
						else
							fprintf(fileP, "  ");
					}
					fprintf(fileP, "\n");
				}

				fclose(fileP);
				break;
			}

		default: break;
	}
}

void generateRandomPattern()
{
	int ruleInInt, width, height;

    srand(time(NULL)); //Seeding with current time
    ruleInInt = rand() % 255;
    if(ruleInInt < 1)
    {
        ruleInInt += 1;
    }

	int binaryArray[8];  // The array to store the binary number
	int temp = 0;

	int intForConversion = ruleInInt;

	while(temp<8)
	{
		binaryArray[7-temp] = intForConversion%2;
		intForConversion /= 2;
		temp++;
	}

	printf("\nEnter the length of the generation: ");
	scanf("%d", &width);

	printf("Enter the number of generations: ");
	scanf("%d", &height);

	int numArray[height][width];

	for (int i = 0; i < height; i++)
		for(int j=0; j<width; j++)
			numArray[i][j]=0;

	numArray[0][width/2] = 1;

	printf("\nThis is Rule %d \n",ruleInInt);


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

	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\nDo you want to save this pattern? Press 1 to Save. Any other number to return to Main Menu\nYour Choice: ");
	int saveChoice;
	scanf("%d",&saveChoice);

	switch(saveChoice)
	{

		case 1:

			{

				FILE* fileP = malloc(sizeof(FILE));

				fileP = fopen("output", "w");

				if (fileP == NULL)
				{
					printf("File cannot be accessed.");
					exit(1);
				}

				fprintf(fileP, "Rule %i\n", ruleInInt);

				for (int i=0; i<height; i++)
				{
					for (int j=0; j<width; j++)
					{
						if (numArray[i][j] == 1)
							fprintf(fileP, "\u25A0 ");
						else
							fprintf(fileP, "  ");
					}
					fprintf(fileP, "\n");
				}

				fclose(fileP);
				break;
			}

		default: break;
	}
}

void binaryConverter()
{
	printf("\nEnter A Choice:\n1. Decimal to Binary\n2. Binary to Decimal\nEnter Choice: ");
	int choice;
	scanf("%d",&choice);


}

void main()
{
	int menuChoice;

	menuChoice = 0;
	
	do
	{
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Cellular Automaton");
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		printf("\nEnter A Choice");
		printf("\n1. Generate Pattern by Choosing a rule");
		printf("\n2. Generate Pattern using a random rule");
		printf("\n3. Binary Converter");
		printf("\nPress Any other Number to Exit");
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Your Choice: ");
		scanf("%d", &menuChoice);
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");

		switch(menuChoice)
		{
			case 1:	generateUserPattern();
					break;

			case 2: generateRandomPattern();
					break;

			//case 3: binaryConverter();
			//		break;

			default:
				{
						printf("\nClosing the program...");
						menuChoice = -1;
					}
		}

	}while (menuChoice != -1);
	


}
