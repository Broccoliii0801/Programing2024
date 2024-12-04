#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(double arr[], int size, double min, double max)      // �迭 ���� �Լ� ����
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (max - min) * ((double)rand() / RAND_MAX) + min;       // �������� �Ǽ� ����
    }
}

void CalcSortArray(double arr[], int size, int Ascending)      // �迭 ���� �Լ� ����, Ascending�� �Ű������� �Ͽ�, �Ű������� 1�̸� ��������, 0�̸� �������� ����
{
    for (int i = 0; i < size - 1; i++)        // �迭�� ũ�⿡ ���� �ݺ� ����
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if ((Ascending && arr[j] > arr[j + 1]) || (!Ascending && arr[j] < arr[j + 1]))
            {
                double temp = arr[j];    // �� ���� �ڸ��� �ٲٱ� ���� ���
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void PrintArray(double arr[], int size)             // �迭 ��� �Լ� ����
{
    for (int i = 0; i < size; i++)                  // �迭 ũ�⸸ŭ ����ϸ� ����
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL)); // ���� �õ� �ʱ�ȭ

    const int size = 10;                  // �迭 ũ�� 10���� ����
    double arr[size];
    double min = -100.0, max = 100.0;     // �迭���� ���� -100.0 ~ +100.0

    GenerateArray(arr, size, min, max);

    printf("������ �迭:\n");
    PrintArray(arr, size);

    int option;  // ��������, �������� ���� �Է�
    printf("���� �ɼ��� �����ϼ��� (1: ��������, 2: ��������): ");
    scanf_s("%d", &option);

    CalcSortArray(arr, size, option == 1);   // �տ��� ������ ���� �迭 ����
    
    printf("���ĵ� �迭:\n");
    PrintArray(arr, size);

    return 0;
}
