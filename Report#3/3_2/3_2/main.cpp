#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define gen_num 10  //생성할 정수의 개수 10개 정의

void gen_rand_seed()  //시간에 따른 난수생성
{
    srand((unsigned int)(time(NULL)));
}

int generate_random_number(int min, int max)  //특정 범위 내에서 무작위로 정수를 생성하는 함수
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    gen_rand_seed();               //총합, 분산, 표준편차를 구하기 위해 생성된 정수들의 제곱의 합 계산 필요
    int min_range, max_range;
    int sum = 0;
    int sum_squares = 0;

    printf("범위의 최소값 입력: ");
    scanf_s("%d", &min_range);
    printf("범위의 최대값 입력: ");
    scanf_s("%d", &max_range);

    if (min_range > max_range)     //범위의 최소값이 최대값보다 크면 안 됨
    {
        printf("범위가 잘못되었습니다.\n");
        return 1;
    }
    else
    {
        printf("정수 생성\n");
    }

    for (int i = 0; i < gen_num; i++)         //10개의 정수 생성과 함께 합과 제곱의 합 계산
    {
        int num = generate_random_number(min_range, max_range);
        printf("생성된 숫자 %d: %d\n", i + 1, num);   //생성된 숫자들 차례대로 출력
        sum += num;
        sum_squares += num * num;
    }

    double mean = (double)sum / gen_num;                                  //평균
    double variance = ((double)sum_squares / gen_num) - (mean * mean);    //분산
    double std_dev = sqrt(variance);                                      //표준편차

    printf("합계: %d, 평균: %.2lf, 분산: %2lf, 표준편차: %.2lf\n", sum, mean, variance, std_dev);

    return 0;
}