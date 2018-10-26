#include<stdio.h>

int returnValue(int ruleInBinary, int index, int threeNum)
{

	int binaryArray[];//convert binary number into binary array here (incomplete)

	switch (threeNum)
	{
		case 000:
		if (binaryArray[index] == 0)
			return 0;
		else if (binaryArray[index] == 1)
			return 1;

		case 001:
		if (binaryArray[index] == 0)
			return 0;
		else if (binaryArray[index] == 1)
			return 1;

		case 010:
		if (binaryArray[index] == 0)
			return 0;
		else if (binaryArray[index] == 1)
			return 1;

		case 011:
		if (binaryArray[index] == 0)
			return 0;
		else if (binaryArray[index] == 1)
			return 1;

		case 100:
		if (binaryArray[index] == 0)
			return 0;
		else if (binaryArray[index] == 1)
			return 1;

		case 101:
		if (binaryArray[index] == 0)
			return 0;
		else if (binaryArray[index] == 1)
			return 1;

		case 110:
		if (binaryArray[index] == 0)
			return 0;
		else if (binaryArray[index] == 1)
			return 1;

		case 111:
		if (binaryArray[index] == 0)
			return 0;
		else if (binaryArray[index] == 1)
			return 1;
	}
}