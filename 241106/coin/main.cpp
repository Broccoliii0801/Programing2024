#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define num_flip 10000
#define coin_fwd_bwd 3
#define coin_fwd_status 0
#define coin_bwd_status 1

#define INITSTATUS 100
#define END_COND 999

void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
}

// 랜덤 숫자 생성
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    while (1)
    {
        nRes = rand();
        nRes = nRes % 2;
        if (nRes == coin_fwd_status || nRes == coin_bwd_status)
        {
            break;
        }
    }
    return nRes;
}

// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int num_sum_fwdflip = 0;
    int num_sum_bwdflip = 0;
    double mean_fwd_flip;
    double mean_bwd_flip;
    double dvar_fwd_flip = 0.0;
    double dvar_bwd_flip = 0.0;
    double dstdev_fwd_flip = 0.0;
    double dstdev_bwd_flip = 0.0;

    // finite loop
    for (unsigned int i = 0; i < num_flip; i++)
    {
        // generating the random number, flip coin, 0: fwd, 1: bwd
        unsigned int nstatusflipcoin = GenRandFlipCoin(coin_fwd_bwd);

        if (nstatusflipcoin == coin_fwd_status)
        {
            num_sum_fwdflip++;
        }
        else if (nstatusflipcoin == coin_bwd_status)
        {
            num_sum_bwdflip++;
        }
    }

    // 확률 계산
    double probability_fwd = (double)num_sum_fwdflip / num_flip * 100.0;
    double probability_bwd = (double)num_sum_bwdflip / num_flip * 100.0;

    // 평균 계산
    mean_fwd_flip = (double)num_sum_fwdflip / num_flip;
    mean_bwd_flip = (double)num_sum_bwdflip / num_flip;

    // 분산 계산
    dvar_fwd_flip = mean_fwd_flip * (1 - mean_fwd_flip);
    dvar_bwd_flip = mean_bwd_flip * (1 - mean_bwd_flip);

    // 표준 편차 계산
    dstdev_fwd_flip = sqrt(dvar_fwd_flip);
    dstdev_bwd_flip = sqrt(dvar_bwd_flip);

    // 결과 출력
    printf("앞면이 나온 횟수: %d, 확률: %.2f%%\n", num_sum_fwdflip, probability_fwd);
    printf("뒷면이 나온 횟수: %d, 확률: %.2f%%\n", num_sum_bwdflip, probability_bwd);
    printf("앞면의 분산: %.4f, 표준 편차: %.4f\n", dvar_fwd_flip, dstdev_fwd_flip);
    printf("뒷면의 분산: %.4f, 표준 편차: %.4f\n", dvar_bwd_flip, dstdev_bwd_flip);

    return 0;
}
