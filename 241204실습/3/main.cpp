#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(double* arr, int size, double min, double max)
{
    int i = 0;
    while (i < size)
    {
        *(arr + i) = (max - min) * ((double)rand() / RAND_MAX) + min; 
        i++;
    }
}

void CalcSortArray(double* arr, int size, int Ascending)   // 오름/내림차순 정렬 함수
{
    int i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - 1 - i)
        {
            if ((Ascending && *(arr + j) > *(arr + j + 1)) || (!Ascending && *(arr + j) < *(arr + j + 1)))
            {
                double temp = *(arr + j);   // 포인터로 자리 교환
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
            j++;
        }
        i++;
    }
}

void PrintArray(double* arr, int size)
{
    int i = 0;
    while (i < size)
    {
        printf("%.2f ", *(arr + i)); 
        i++;
    }
    printf("\n");
}

int main()
{
    srand(time(NULL)); // 랜덤 함수 초기화

    const int size = 10; // 배열 크기
    double arr[size];
    double min = -100.0, max = 100.0; // 값의 범위 설정

    GenerateArray(arr, size, min, max);  // 배열 생성

    printf("생성된 배열:\n");
    PrintArray(arr, size);  // 생성된 배열 출력

    int option;   // 정렬 옵션 선택
    printf("정렬 옵션을 선택하세요 (1: 오름차순, 2: 내림차순): ");
    scanf_s("%d", &option);

    CalcSortArray(arr, size, option == 1); // 정렬 실행

    printf("정렬된 배열:\n");
    PrintArray(arr, size); // 정렬된 배열 출력

    return 0;
}
