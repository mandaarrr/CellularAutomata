/*
*Cellular Automaton - Group 12
*Name:		Archie Rutherford		Mandar Tamhane		Stanislav Turcanu
*Matric:	170010226			170021792		170011034
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void generateUserPattern() //generate pattern using rule entered by user
{
	int ruleInInt, width, height;


	printf("\nEnter the Rule (between 0 and 255): ");
	scanf("%d", &ruleInInt);
	if (ruleInInt<0 || ruleInInt>255) //checking if rule is 8 bit convertable
	{
		printf("\nInvalid Input. Returning to Main Menu...\n");
		return;
	}


	int binaryArray[8];  // The array to store the binary number
	int temp = 0;

	int intForConversion = ruleInInt; //copying the value of the rule

	while(temp<8) //converting rule to binary
	{
		binaryArray[7-temp] = intForConversion%2;
		intForConversion /= 2;
		temp++;
	}


	printf("Enter the length of the generation: ");
	scanf("%d", &width);
	if (width<0 || width>999)
	{
		printf("\nInvalid Input. Returning to Main Menu...\n");
		return;
	}

	printf("Enter the number of generations: ");
	scanf("%d", &height);
	if (height<0 || height>999)
	{
		printf("\nInvalid Input. Returning to Main Menu...\n");
		return;
	}


	int numArray[height][width]; //creating number array

	for (int i = 0; i < height; i++)
		for(int j=0; j<width; j++)
			numArray[i][j]=0;

	numArray[0][width/2] = 1;


	printf("\nThis is Rule %d \n",ruleInInt);


	for (int i = 1; i < height; i++)
  	{
  		for (int j = 0; j < width; j++)
 		 {
	//Add up all the neighbor states to calculate the number of neighbors.

			int patternInt = 0;

			if (j==width) //populating rightmost edge
			{
				if (numArray[i-1][j-1] == 0)
					patternInt += 4;
				if (numArray[i-1][j] == 0)
					patternInt += 2;
				if (numArray[i-1][0] == 0)
					patternInt += 1;
			}
			else if (j==0) //populating leftmost edge
			{
				if (numArray[i-1][width] == 0)
					patternInt += 4;
				if (numArray[i-1][j] == 0)
					patternInt += 2;
				if (numArray[i-1][j+1] == 0)
					patternInt += 1;
			}
			else //pattern matching and finding value in next state
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


	for(int i=0; i<height; i++) //converting number array into graphic pattern
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
	printf("\nDo you want to save this pattern?\nPress 1 to Save. Any other number to return to Main Menu\nYour Choice: "); //asking user to save file
	int saveChoice;
	scanf("%d",&saveChoice);

	switch(saveChoice)
	{

		case 1:

			{

				FILE* fileP = malloc(sizeof(FILE)); // file pointer and allocating memory for file

				fileP = fopen("output", "w"); //open file at pointer in write mode

				if (fileP == NULL)
				{
					printf("File cannot be accessed.");
					exit(1);
				}

				fprintf(fileP, "Rule %i\n", ruleInInt);

				for (int i=0; i<height; i++) //writing the pattern in the file
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
				printf("Pattern Saved.");
				break;
			}

		default: printf("\nReturning to Menu...\n");
					break;
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
	if (width<0 || width>999)
	{
		printf("\nInvalid Input. Returning to Main Menu...\n");
		return;
	}

	printf("Enter the number of generations: ");
	scanf("%d", &height);
	if (height<0 || height>999)
	{
		printf("\nInvalid Input. Returning to Main Menu...\n");
		return;
	}


	int numArray[height][width];

	for (int i = 0; i < height; i++)
		for(int j=0; j<width; j++)
			numArray[i][j]=0;

	numArray[0][width/2] = 1;


	printf("\nThis is Rule %d \n",ruleInInt);

	for (int i = 1; i < height; i++)
 	 {
  		for (int j = 0; j < width; j++)
 	 	{
			int patternInt = 0;

			if (j==width)
			{
				if (numArray[i-1][j-1] == 0)
					patternInt += 4;
				if (numArray[i-1][j] == 0)
					patternInt += 2;
				if (numArray[i-1][0] == 0)
					patternInt += 1;
			}
			else if (j==0)
			{
				if (numArray[i-1][width] == 0)
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


	for(int i=0; i<height; i++) //printing graphic array
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
				printf("Pattern Saved.");
				break;
			}

		default: printf("\nReturning to Menu...\n");
				break;
	}
}

void decimalToBinary()
{
	int binaryArray[8]; // The array to store the binary number
	int numInDecimal = 0;
	int temp = 0;

	printf("\nEnter decimal number between 0 and 255: ");
	scanf("%d",&numInDecimal);
	if (numInDecimal<0 || numInDecimal>255)
	{
		printf("\nInvalid Input. Returning to Menu...\n");
		return;
	}

	int numInDecimal_copy = numInDecimal;

	while(temp<8)
	{
		binaryArray[7-temp] = numInDecimal%2;
		numInDecimal /= 2;
		temp++;
	}

	printf("\nThe Binary conversion for %d is ", numInDecimal_copy);

	for(int i=0; i<8; i++)
		printf("%d", binaryArray[i]);

	printf("\nReturning to Menu...\n");
	return;
}

void gameOfLife()
{
  int width = 5;
  int height = 5;

  int board[height][width];

  srand(time(NULL));
  int rNum;

  for (int i=0; i<height; i++) {
    for (int o=0; o<width; o++) {
      rNum = rand()%2;
      printf("%i", rNum);
      board[i][o] = rNum;
    }
  }

  int count = 0;

  while (count++ < 10) {

    printf("\n\n");
    for (int i=0; i<height; i++) {
      printf("\n");
      for (int o=0; o<width; o++) {
        if (board[i][o] == 1)
          printf("\u25A0 ");
        else
          printf("\u25A1 ");
      }
    }

    for (int i=0; i<height; i++) {
      for (int o=0; o<width; o++) {

        int counter = 0;
        for (int y=-1; y<2; y++) {
          for (int x=-1; x<2; x++) {

            if (board[i+y][o+x] == 1 && !(y==0 && x==0) && !(o+x<0 || i+y<0))
              counter++;
          }
        }

        if (board[i][o]==1 && counter<2)
          board[i][o] = 0;
        else if (board[i][o]==1 && counter>3)
          board[i][o] = 0;
        else if (board[i][o]==0 && counter==3)
          board[i][o] = 1;
      }
    }
  }
}

void main()
{
	int menuChoice;

	menuChoice = 0;

	do
	{
		printf("\n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Cellular Automaton");
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
		printf("\nEnter A Choice");
		printf("\n1. Generate Pattern by Choosing a rule");
		printf("\n2. Generate Pattern using a random rule");
		printf("\n3. Binary Converter");
		printf("\n4. Conway's Game of Life");
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

			case 3: decimalToBinary();
					break;
			
			case 4: gameOfLife();
				break;

			default:
				{
						printf("\nClosing the program...\n\n");
						menuChoice = -1;
					}
		}

	}while (menuChoice != -1);
}
