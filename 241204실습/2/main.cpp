#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(float* arr, int size) // 배열 생성
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (rand() % 2001 - 1000) / 10.0; 
    }
}

void PrintArray(float* arr, int size) // 배열 출력
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1f ", *(arr + i)); 
    }
    printf("\n");
}

void CalcInverseArray(float* arr, int size) 
{
    for (int i = 0; i < size / 2; i++)
    {
        float temp = *(arr + i); 
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }
}

int main()
{
    float arr[10]; // 배열 선언
    srand(time(0)); // 랜덤 초기화

    GenerateArray(arr, 10); // 배열 생성

    printf("생성된 배열:\n");
    PrintArray(arr, 10); // 생성된 배열 출력 

    CalcInverseArray(arr, 10); // 배열 역순 변환 

    printf("역순 배열:\n");
    PrintArray(arr, 10); // 역순 배열 출력 

    return 0;
}