#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(float* arr, int size) // 포인터로 배열 생성
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (rand() % 2001 - 1000) / 10.0; // 포인터로 배열 요소 접근
    }
}

void PrintArray(float* arr, int size) // 포인터로 배열 출력
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1f ", *(arr + i)); // 포인터로 배열 요소 출력
    }
    printf("\n");
}

void CalcInverseArray(float* arr, int size) // 포인터로 배열 역순 변환
{
    for (int i = 0; i < size / 2; i++)
    {
        float temp = *(arr + i); // 포인터로 요소 접근
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }
}

int main()
{
    float arr[10]; // 배열 선언
    srand(time(0)); // 랜덤 초기화

    GenerateArray(arr, 10); // 배열 생성 (포인터 사용)

    printf("생성된 배열:\n");
    PrintArray(arr, 10); // 생성된 배열 출력 (포인터 사용)

    CalcInverseArray(arr, 10); // 배열 역순 변환 (포인터 사용)

    printf("역순 배열:\n");
    PrintArray(arr, 10); // 역순 배열 출력 (포인터 사용)

    return 0;
}