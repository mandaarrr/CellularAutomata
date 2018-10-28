#include<stdio.h>

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