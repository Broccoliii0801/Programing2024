#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(float arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 2001 - 1000) / 10.0; // -100.0 ~ +100.0 범위의 랜덤 값 생성
    }
}

void PrintArray(float arr[], int size)          // 배열 출력 함수
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

void CalcInverseArray(float arr[], int size)       // 배열을 역순으로 바꿔주는 함수
{
    for (int i = 0; i < size / 2; i++)
    {
        float temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main()
{
    float arr[10];
    srand(time(0)); // 배열 생성 초기화

    GenerateArray(arr, 10);  // 배열 생성

    printf("생성된 배열:\n");    // 생성된 배열 출력
    PrintArray(arr, 10);

    CalcInverseArray(arr, 10);   // 배열 역순 변환

    printf("역순 배열:\n");     // 역순 배열 출력
    PrintArray(arr, 10);

    return 0;
}