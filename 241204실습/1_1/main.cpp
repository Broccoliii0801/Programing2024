#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(double arr[], int size, double min, double max)
{
    int i = 0;
    while (i < size)
    {
        arr[i] = (max - min) * ((double)rand() / RAND_MAX) + min; // 랜덤 실수 생성, RAND_MAX는 <stdlib.h> 라이브러리에 정의된 함수로 rand() 함수가 생성하는 난수의 최대값 의미
        i++;
    }
}

void CalcSortArray(double arr[], int size, int Ascending)   // 오름/내림차순 정렬 함수, Ascending == 1 이면 오름차순으로, 0이면 내림차순으로
{
    int i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - 1 - i)
        {
            if ((Ascending && arr[j] > arr[j + 1]) || (!Ascending && arr[j] < arr[j + 1]))
            {
                double temp = arr[j];   // 정렬 시 자리 교환
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void PrintArray(double arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%.2f ", arr[i]);
        i++;
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // 랜덤 함수 초기화

    const int size = 10; // 배열 크기 10으로 설정
    double arr[size];
    double min = -100.0, max = 100.0; // 값의 범위

    GenerateArray(arr, size, min, max);  // 배열 생성

    printf("생성된 배열:\n");
    PrintArray(arr, size);

    int option;   // 오름차순/내림차순 여부 선택
    printf("정렬 옵션을 선택하세요 (1: 오름차순, 2: 내림차순): ");
    scanf_s("%d", &option);

    CalcSortArray(arr, size, option == 1);

    printf("정렬된 배열:\n");
    PrintArray(arr, size);

    return 0;
}