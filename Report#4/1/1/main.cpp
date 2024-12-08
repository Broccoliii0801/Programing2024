#include <stdio.h>

double calculateDotProduct(double* v1, double* v2)                   // ����(dot product) ��� �Լ�
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

void calculateCrossProduct(double* v1, double* v2, double* result)   // ����(cross product) ��� �Լ�
{
    result[0] = v1[1] * v2[2] - v1[2] * v2[1];                       // x ����
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];                       // y ����
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];                       // z ����
}

void printVector(double* vector, int size)                           // ���� ��� �Լ�
{
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", vector[i]);
    }
    printf("\n");
}

int main()
{
    double vector1[3], vector2[3];                                   // �� ���� 3���� ���� ����
    double crossProduct[3];                                          // ������ ������ ����� 3���� �����̹Ƿ� �迭 ũ�� 3���� ����
    double dotProduct;

    printf("ù ��° ���� (x, y, z): ");
    scanf_s("%lf %lf %lf", &vector1[0], &vector1[1], &vector1[2]);

    printf("�� ��° ���� (x, y, z): ");
    scanf_s
    ("%lf %lf %lf", &vector2[0], &vector2[1], &vector2[2]);

    dotProduct = calculateDotProduct(vector1, vector2);             // ���� ���

    calculateCrossProduct(vector1, vector2, crossProduct);          // ���� ���

    printf("���� : %.2f\n", dotProduct);                            // ���� ����� ��Į�� ������ ���
    printf("���� : ");                                              // ���� ����� 3���� ���ͷ� ���
    printVector(crossProduct, 3);                                   // ���� ����� ����ϱ� ���� �Լ�

    return 0;
}
