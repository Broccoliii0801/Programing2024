#include <stdio.h>
#include <stdlib.h>    // srand, rand �Լ��� ���ԵǾ� �ִ� �������
#include <time.h>      // time �Լ��� ���ԵǾ� �ִ� �������
#include <math.h>      // pow�Լ��� ���ԵǾ� �ִ� �������

int Duplicate(int* arr, int size, int num)   // �ߺ� Ȯ�� �Լ�
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num) return 1;         // �ߺ��̸� 1 ��ȯ
    }
    return 0;                                // �ߺ����� ���� ��� 0 ��ȯ
}

void genRandNum(int* arr, int size, int min, int max)   // ������ ���� ���� ���� �Լ�
{
    int count = 0;
    while (count < size)
    {
        int num = rand() % (max - min + 1) + min;  // min ~ max ������ ���� �� ����
        if (!Duplicate(arr, count, num))           // �ߺ� �˻�
        {     
            arr[count++] = num;                    // �迭�� �߰�
        }
    }
}

void calculateStats(int* arr, int size)                                // ��� ��� �� ���
{
    int sum = 0;
    double mean, variance = 0.0;
    for (int i = 0; i < size; i++) sum += arr[i];
    mean = (double)sum / size;
    for (int i = 0; i < size; i++) variance += pow(arr[i] - mean, 2);  // �������� ���ϴ� pow�Լ� ���
    printf("����: %d\n���: %.2f\n�л�: %.2f\nǥ������: %.2f\n", sum, mean, variance / size, sqrt(variance / size));
}

int main()
{
    srand(time(NULL));
    int numbers[100], choice[10], min, max;

    printf("�ּҰ��� �ִ밪�� �Է��ϼ��� (��: 1 100): ");
    scanf_s("%d %d", &min, &max);
    if (min > max) return printf("�ּҰ��� �ִ밪���� �۾ƾ� �մϴ�.\n");
    return 1;

    int range = max - min + 1;
    if (range < 100) return printf("������ �ʹ� �۾� 100���� ������ ������ �� �����ϴ�.\n");
    return 1;

    genRandNum(numbers, 100, min, max);

    for (int i = 0; i < 10; i++) choice[i] = numbers[i];       // 10���� ���� ����

    printf("����� ����: ");
    for (int i = 0; i < 10; i++) printf("%d ", choice[i]);
    printf("\n");

    calculateStats(choice, 10);
    return 0;
}
