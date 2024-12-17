#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate(int* arr, int size, double* sum, double* mean, double* variance, double* std_dev) // �հ�, ���, �л�, ǥ�������� ���ϱ� ���� ��� �Լ�
{
    double sqr_sum = 0;    // ������ ������ �հ� �����ϱ� ���� ���� sqr_sum ���
    *sum = 0;
    for (int i = 0; i < size; i++)
    *sum += arr[i];
    *mean = *sum / size;
    for (int i = 0; i < size; i++) 
    sqr_sum += pow(arr[i] - *mean, 2);   // pow(arr[i] - *mean, 2) : �迭�� �� ������ ����� ���� �̸� ������ ��, �� ���� sqr_sum�� �����ؼ� ���س���
    *variance = sqr_sum / size;   // �л� ���
    *std_dev = sqrt(*variance);   // ǥ������ = �л��� ������
}

int main()
{
    int* arr = NULL, size, extra;  // NULL�� ���� �޸𸮸� �Ҵ��ϱ� ���� �ʱ�ȭ

    printf("�ʱ� �迭 ũ�� �Է�: ");
    scanf_s("%d", &size);
    
    arr = (int *)malloc(size * sizeof(int));  // �Է¹��� ũ�⿡ ���� ���� �޸� �Ҵ�, �����͸� int *�� ��ȯ
    if (!arr)
    {
        printf("�޸� �Ҵ� ����\n");
        return 1;    // �Ҵ� ���� �� ����
    }

    printf("%d���� ���� �Է�: ", size);
    for (int i = 0; i < size; i++)
        scanf_s("%d", &arr[i]);

    double initialsum, initialmean, initialvariance, initialstd_dev;
    calculate(arr, size, &initialsum, &initialmean, &initialvariance, &initialstd_dev);

    printf("\n�߰��� �迭 ũ�� �Է�: ");
    scanf_s("%d", &extra);

   int *temp = (int *)realloc(arr, (size + extra) * sizeof(int));  // realloc���� ���� �迭 Ȯ��, 
    if (!temp)
    {
        printf("�޸� ���Ҵ� ����\n");
        free(arr);   // ���� �޸� ����
        return 1;
    }
    arr = temp;

    printf("%d���� �߰��� �Է�: ", extra);
    for (int i = size; i < size + extra; i++)
        scanf_s("%d", &arr[i]);

    double finalsum, finalmean, finalvariance, finalstd_dev;
    size += extra;
    calculate(arr, size, &finalsum, &finalmean, &finalvariance, &finalstd_dev);

    printf("�ʱ� �迭 ũ��: %d\n", size - extra);
    printf("�Էµ� ��: ");
    for (int i = 0; i < size - extra; i++)
        printf("%d ", arr[i]);
    printf("�հ�: %.2f\n",initialsum);
    printf("���: %.2f\n", initialmean);
    printf("�л�: %.2f\n", initialvariance);
    printf("ǥ�� ����: %.2f\n", initialstd_dev);

    printf("�߰� �迭 ũ��: %d\n", extra);
    printf("�߰��� ��: ");
    for (int i = size - extra; i < size; i++)
        printf("%d ", arr[i]);
    printf("���ο� �հ�: %.2f\n", finalsum);
    printf("���ο� ���: %.2f\n", finalmean);
    printf("���ο� �л�: %.2f\n", finalvariance);
    printf("���ο� ǥ�� ����: %.2f\n", finalstd_dev);

    free(arr);   // ���� �޸� ����
    return 0;
}