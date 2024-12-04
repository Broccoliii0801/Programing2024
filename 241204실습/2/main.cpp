#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(float* arr, int size) // �迭 ����
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (rand() % 2001 - 1000) / 10.0; 
    }
}

void PrintArray(float* arr, int size) // �迭 ���
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
    float arr[10]; // �迭 ����
    srand(time(0)); // ���� �ʱ�ȭ

    GenerateArray(arr, 10); // �迭 ����

    printf("������ �迭:\n");
    PrintArray(arr, 10); // ������ �迭 ��� 

    CalcInverseArray(arr, 10); // �迭 ���� ��ȯ 

    printf("���� �迭:\n");
    PrintArray(arr, 10); // ���� �迭 ��� 

    return 0;
}