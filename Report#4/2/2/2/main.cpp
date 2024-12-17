#include <stdio.h>
#include <stdlib.h>    // srand, rand 함수가 포함되어 있는 헤더파일
#include <time.h>      // time 함수가 포함되어 있는 헤더파일
#include <math.h>      // pow함수가 포함되어 있는 헤더파일

int Duplicate(int* arr, int size, int num)   // 중복 확인 함수
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num) return 1;         // 중복이면 1 반환
    }
    return 0;                                // 중복되지 않을 경우 0 반환
}

void genRandNum(int* arr, int size, int min, int max)   // 고유한 랜덤 정수 생성 함수
{
    int count = 0;
    while (count < size)
    {
        int num = rand() % (max - min + 1) + min;  // min ~ max 범위의 랜덤 값 생성
        if (!Duplicate(arr, count, num))           // 중복 검사
        {     
            arr[count++] = num;                    // 배열에 추가
        }
    }
}

void calculateStats(int* arr, int size)                                // 통계 계산 및 출력
{
    int sum = 0;
    double mean, variance = 0.0;
    for (int i = 0; i < size; i++) sum += arr[i];
    mean = (double)sum / size;
    for (int i = 0; i < size; i++) variance += pow(arr[i] - mean, 2);  // 제곱근을 구하는 pow함수 사용
    printf("총합: %d\n평균: %.2f\n분산: %.2f\n표준편차: %.2f\n", sum, mean, variance / size, sqrt(variance / size));
}

int main()
{
    srand(time(NULL));
    int numbers[100], choice[10], min, max;

    printf("최소값과 최대값을 입력하세요 (예: 1 100): ");
    scanf_s("%d %d", &min, &max);
    if (min > max) return printf("최소값은 최대값보다 작아야 합니다.\n");
    return 1;

    int range = max - min + 1;
    if (range < 100) return printf("범위가 너무 작아 100개의 정수를 생성할 수 없습니다.\n");
    return 1;

    genRandNum(numbers, 100, min, max);

    for (int i = 0; i < 10; i++) choice[i] = numbers[i];       // 10개의 정수 추출

    printf("추출된 정수: ");
    for (int i = 0; i < 10; i++) printf("%d ", choice[i]);
    printf("\n");

    calculateStats(choice, 10);
    return 0;
}
