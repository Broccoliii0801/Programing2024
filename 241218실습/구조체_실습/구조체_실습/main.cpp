#include <stdio.h>
#include <math.h>

// Euclidean Distance ��� �Լ�
double calculateDistance(double* p1, double* p2) {
    return sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2) + pow(p2[2] - p1[2], 2));
}

int main() {
    double point1[3], point2[3]; // �� ���� ��ǥ�� ������ �迭
    double distance;

    // ����ڷκ��� ù ��° ���� ��ǥ �Է� �ޱ�
    printf("ù ��° ���� ��ǥ (x, y, z)�� �Է��ϼ���: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%lf", &point1[i]);
    }

    // ����ڷκ��� �� ��° ���� ��ǥ �Է� �ޱ�
    printf("�� ��° ���� ��ǥ (x, y, z)�� �Է��ϼ���: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%lf", &point2[i]);
    }

    // �Ÿ� ��� (�迭�� ���� �ּҸ� �����ͷ� ����)
    distance = calculateDistance(point1, point2);

    // ��� ���
    printf("�� �� ������ �Ÿ�: %.2lf\n", distance);

    return 0;
}
