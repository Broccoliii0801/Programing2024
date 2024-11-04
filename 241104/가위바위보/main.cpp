#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Rock_Paper_Scissors 3
#define Rock 0
#define Paper 1
#define Scissors 2
#define Initstatus 100
#define END_COND 999

#define Player_Win 11
#define Player_Lose 12
#define Player_Draw 13

// generating the seed number using the time clock information
void GenRandSeed()
{
	// generating the random number using the time seed
	srand((unsigned int)(time(NULL)));
	return;
}

// generating the random number
unsigned int GenRandNum(unsigned int nRange)
{
	unsigned int nRes = 0;
	unsigned int nNum = rand();
	nRes = ((unsigned int)(nNum) % (nRange));
	return nRes;
}

int main(void)
{
	// assigning seed
	GenRandSeed();

	// initializing variables
	unsigned int nComRps = Initstatus;
	unsigned int nPlayerRps = Initstatus;
}


//infiniti loop
while (1)
{
	// generating the input information
	printf(format"Input your status(Rock:0, Paper:1, Scissors:2):\n");
	printf(format"if you want to end the loop, please input 999\n");
	scanf_s(format"%d", &nPlayerRps);

	//exception #1, Input condition
	if (nPlayerRps == END_COND)
	{
		printf(format"end of the infinite while loop RPS game...\n");
		break;
	}

	//exception #2, input condition
	if ((nPlayerRps < 0) || (nPlayerRps >= Rock_Paper_Scissors))
	{
		printf(format"check your input condition..\n");
	    continue;
	}

	//generating the random number, ROCK/PAPER/SCISSORS
	unsigned int nComRps = GenRandNum(nRange:Rock_Paper_Scissors);

	//for debugging
	printf(format"(Player, Computor):(%d, %d)\n\n", nPlayerRps, nComRps);

	//result
	unsigned int CalRpsGameRes(unsigned int nPlayerRps, unsigned int nComRps);
	{
		//draw
		if ((nPlayerRps == Rock)&&(nComRps)


	
}

return 0;
}