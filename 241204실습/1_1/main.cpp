#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void GenerateArray(double arr[], int size, double min, double max)
{
    int i = 0;
    while (i < size)
    {
        arr[i] = (max - min) * ((double)rand() / RAND_MAX) + min; // ���� �Ǽ� ����, RAND_MAX�� <stdlib.h> ���̺귯���� ���ǵ� �Լ��� rand() �Լ��� �����ϴ� ������ �ִ밪 �ǹ�
        i++;
    }
}

void CalcSortArray(double arr[], int size, int Ascending)   // ����/�������� ���� �Լ�, Ascending == 1 �̸� ������������, 0�̸� ������������
{
    int i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - 1 - i)
        {
            if ((Ascending && arr[j] > arr[j + 1]) || (!Ascending && arr[j] < arr[j + 1]))
            {
                double temp = arr[j];   // ���� �� �ڸ� ��ȯ
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
    srand(time(NULL)); // ���� �Լ� �ʱ�ȭ

    const int size = 10; // �迭 ũ�� 10���� ����
    double arr[size];
    double min = -100.0, max = 100.0; // ���� ����

    GenerateArray(arr, size, min, max);  // �迭 ����

    printf("������ �迭:\n");
    PrintArray(arr, size);

    int option;   // ��������/�������� ���� ����
    printf("���� �ɼ��� �����ϼ��� (1: ��������, 2: ��������): ");
    scanf_s("%d", &option);

    CalcSortArray(arr, size, option == 1);

    printf("���ĵ� �迭:\n");
    PrintArray(arr, size);

    return 0;
}