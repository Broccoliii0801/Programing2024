#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(int arr[], int size)   //�迭 ����
{
    int i = 0;
    while (i < size)
    {
        arr[i] = rand() % 101;      // 0~100 ������ ���� ���� ����
        i++;
    }
}

void PrintArray(int arr[], int size)    //�迭 ���
{
    int i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void CalcEvenOddArray(int arr[], int size, int even[], int* evenCount, int odd[], int* oddCount)    // ¦��/Ȧ���� �и��ϴ� �Լ�
{
    *evenCount = 0; // ¦�� ���� �ʱ�ȭ
    *oddCount = 0;  // Ȧ�� ���� �ʱ�ȭ

    int i = 0;
    while (i < size)
    {
        if (arr[i] % 2 == 0)  // ¦�� �˻�
        { 
            even[*evenCount] = arr[i];
            (*evenCount)++;
        }
        else  // Ȧ�� �˻�
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

    srand(time(0));        // �迭�� �ʱ�ȭ

    GenerateArray(arr, 10);

    printf("��� �迭:\n");
    PrintArray(arr, 10);

    CalcEvenOddArray(arr, 10, even, &evenCount, odd, &oddCount);    // ¦��/Ȧ�� �и�

    printf("¦�� :\n");             // ¦�� ���
    PrintArray(even, evenCount);

    printf("Ȧ�� :\n");             // Ȧ�� ���
    PrintArray(odd, oddCount);

    return 0;
}
