#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK_PAPER_SCISSORS 3
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define INITSTATUS 100
#define END_COND 999

#define PLAYER_WIN 11
#define PLAYER_LOSE 12
#define DRAW 13

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

// calculating result
unsigned int CalcRpsGameRes(unsigned int nPlayerRps, unsigned int nComRps)
{
    // calculating draw condition
    if (nPlayerRps == nComRps)
        return DRAW;

    // rock and scissors condition
    if ((nPlayerRps == ROCK) && (nComRps == SCISSORS))
        return PLAYER_WIN;
    else if ((nPlayerRps == SCISSORS) && (nComRps == ROCK))
        return PLAYER_LOSE;
    else
    {
        if (nPlayerRps < nComRps)
            return PLAYER_LOSE;
        else
            return PLAYER_WIN;
    }
}

// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nPlayerRps = INITSTATUS;

    // infinite loop
    while (1)
    {
        // generating the player`s status
        printf("Input Your Status(ROCK:0, PAPER:1, SCISSORS:2):\n");
        printf("if you want to end the loop, please input 999\n");
        scanf_s("%d", &nPlayerRps);

        // exception #1, end condition
        if (nPlayerRps == END_COND)
        {
            printf("end of the infinite while loop RPS game...\n");
            break;
        }

        // exception #2, input condition
        if ((nPlayerRps < 0) || (nPlayerRps >= ROCK_PAPER_SCISSORS))
        {
            printf("check your input condition..\n\n");
            continue;
        }

        // generating the random number, ROCK/PAPER/SCISSORS
        unsigned int nComRps = GenRandNum(ROCK_PAPER_SCISSORS);

        // calculating result
        unsigned int nGameRpsRes = CalcRpsGameRes(nPlayerRps, nComRps);

        // for debugging
        printf("Status(Player, Computer):(%d, %d)\n", nPlayerRps, nComRps);

        // printing result
        switch (nGameRpsRes)
        {
        case PLAYER_WIN:
        {
            printf("Player Win!, Computer Lose..\n\n");
            break;
        }
        case PLAYER_LOSE:
        {
            printf("Player Lose...Computer Win!\n\n");
            break;
        }
        case DRAW:
        {
            printf("DRAW!!\n\n");
            break;
        }
        default:
        {
            printf("please check your result..\n\n");
            break;
        }
        }
    }

    return 0;
}
