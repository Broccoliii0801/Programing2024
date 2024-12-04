#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(float* arr, int size) // �����ͷ� �迭 ����
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = (rand() % 2001 - 1000) / 10.0; // �����ͷ� �迭 ��� ����
    }
}

void PrintArray(float* arr, int size) // �����ͷ� �迭 ���
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1f ", *(arr + i)); // �����ͷ� �迭 ��� ���
    }
    printf("\n");
}

void CalcInverseArray(float* arr, int size) // �����ͷ� �迭 ���� ��ȯ
{
    for (int i = 0; i < size / 2; i++)
    {
        float temp = *(arr + i); // �����ͷ� ��� ����
        *(arr + i) = *(arr + size - 1 - i);
        *(arr + size - 1 - i) = temp;
    }
}

int main()
{
    float arr[10]; // �迭 ����
    srand(time(0)); // ���� �ʱ�ȭ

    GenerateArray(arr, 10); // �迭 ���� (������ ���)

    printf("������ �迭:\n");
    PrintArray(arr, 10); // ������ �迭 ��� (������ ���)

    CalcInverseArray(arr, 10); // �迭 ���� ��ȯ (������ ���)

    printf("���� �迭:\n");
    PrintArray(arr, 10); // ���� �迭 ��� (������ ���)

    return 0;
}