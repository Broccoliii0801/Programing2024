#include <stdio.h>
#include <stdlib.h>  //랜덤 함수 생성을 위해 필요한 헤더파일
#include <time.h>    //시간에 따른 함수 생성을 위해 필요한 헤더파일
#include <math.h>    //연산과 관련된 함수 사용을 위해 필요한 헤더파일

#define num_flip 10000  //문제에서 제시한 동전을 던지는 횟수 10000회 정의
#define coin_fwd_status 0  //앞면이 나오는 경우 0으로 표현
#define coin_bwd_status 1  //뒷면이 나오는 경우 1로 표현

void gen_rand_seed()   //난수 생성을 위한 랜덤 함수
{
    srand((unsigned int)(time(NULL)));  //초 단위의 시간 변화에 맞춰 난수 샌성
}

unsigned int gen_rand_flipcoin()  //앞, 뒷면에 따라 앞에서 정의한데로 0과 1을 반환하는 함수
{
    return rand() % 2;  //0이나 1 반환
}

int main(void)
{
    gen_rand_seed();

    int sum_fwdflip = 0;
    int sum_bwdflip = 0;     //앞, 뒷면의 횟수의 합 초기화

    for (unsigned int i = 0; i < num_flip; i++)  //동전을 10000번 던질 때 까지 반복문 사용
    {
        unsigned int nstatusflipcoin = gen_rand_flipcoin();  //동전 던진 결과

        if (nstatusflipcoin == coin_fwd_status)  //if-else문으로 결과 계산
        {
            sum_fwdflip++;
        }
        else if (nstatusflipcoin == coin_bwd_status)
        {
            sum_bwdflip++;
        }
        else
        {
            printf("error\n");
        }
    }

    printf("결과: 앞면=%d (%.2lf%%), 뒷면=%d (%.2lf%%)\n", sum_fwdflip, (double)sum_fwdflip / num_flip *100, sum_bwdflip, (double)sum_bwdflip / num_flip * 100);  //결과 출력
    
    return 0;
}
 