#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(double arr[], int size, double min, double max)      // 배열 생성 함수 정의
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (max - min) * ((double)rand() / RAND_MAX) + min;       // 랜덤으로 실수 생성
    }
}

void CalcSortArray(double arr[], int size, int Ascending)      // 배열 정렬 함수 정의, Ascending을 매개변수로 하여, 매개변수가 1이면 오름차순, 0이면 내림차순 정렬
{
    for (int i = 0; i < size - 1; i++)        // 배열의 크기에 따라 반복 진행
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if ((Ascending && arr[j] > arr[j + 1]) || (!Ascending && arr[j] < arr[j + 1]))
            {
                double temp = arr[j];    // 두 값의 자리를 바꾸기 위해 사용
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void PrintArray(double arr[], int size)             // 배열 출력 함수 정의
{
    for (int i = 0; i < size; i++)                  // 배열 크기만큼 출력하면 정지
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL)); // 랜덤 시드 초기화

    const int size = 10;                  // 배열 크기 10으로 설정
    double arr[size];
    double min = -100.0, max = 100.0;     // 배열값의 범위 -100.0 ~ +100.0

    GenerateArray(arr, size, min, max);

    printf("생성된 배열:\n");
    PrintArray(arr, size);

    int option;  // 오름차순, 내림차순 선택 입력
    printf("정렬 옵션을 선택하세요 (1: 오름차순, 2: 내림차순): ");
    scanf_s("%d", &option);

    CalcSortArray(arr, size, option == 1);   // 앞에서 선택한 데로 배열 정렬
    
    printf("정렬된 배열:\n");
    PrintArray(arr, size);

    return 0;
}
