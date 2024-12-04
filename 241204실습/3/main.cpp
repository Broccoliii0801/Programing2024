#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(int arr[], int size)   //배열 생성
{
    int i = 0;
    while (i < size)
    {
        arr[i] = rand() % 101;      // 0~100 사이의 랜덤 정수 생성
        i++;
    }
}

void PrintArray(int arr[], int size)    //배열 출력
{
    int i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void CalcEvenOddArray(int arr[], int size, int even[], int* evenCount, int odd[], int* oddCount)    // 짝수/홀수를 분리하는 함수
{
    *evenCount = 0; // 짝수 개수 초기화
    *oddCount = 0;  // 홀수 개수 초기화

    int i = 0;
    while (i < size)
    {
        if (arr[i] % 2 == 0)  // 짝수 검사
        { 
            even[*evenCount] = arr[i];
            (*evenCount)++;
        }
        else  // 홀수 검사
        { 
            odd[*oddCount] = arr[i];
            (*oddCount)++;
        }
        i++;
    }
}

int main()
{
    int arr[10], even[10], odd[10];
    int evenCount, oddCount;

    srand(time(0));        // 배열값 초기화

    GenerateArray(arr, 10);

    printf("출력 배열:\n");
    PrintArray(arr, 10);

    CalcEvenOddArray(arr, 10, even, &evenCount, odd, &oddCount);    // 짝수/홀수 분리

    printf("짝수 :\n");             // 짝수 출력
    PrintArray(even, evenCount);

    printf("홀수 :\n");             // 홀수 출력
    PrintArray(odd, oddCount);

    return 0;
}
