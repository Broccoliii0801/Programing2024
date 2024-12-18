#include <stdio.h>
#include <math.h>

struct Point3D                                             // 3���� ���� ���� �� ���� ��Ÿ���� ����ü ����
{
    double coord[3];
};


double calculateDistance(struct Point3D* p1, struct Point3D* p2)         // Euclidean Distance ��� �Լ� (��Ŭ���� �Ÿ� ����)
{
    return sqrt(pow(p2 -> coord[0] - p1 -> coord[0], 2) +          // p1�� ù ��°, p2�� �� ��° ��
                pow(p2 -> coord[1] - p1 -> coord[1], 2) +          // p2 -> coord[1]: p2 �����Ͱ� ����Ű�� ����ü�� y��ǥ
                pow(p2 -> coord[2] - p1 -> coord[2], 2));          // pow(~, 2): pow �Լ��� �̿��� ����
}                                                        

int main()
{
    struct Point3D points[2];                      // �� ���� ��ǥ�� ������ ����ü �迭
    double distance;

    printf("ù ��° ���� ��ǥ (x, y, z)�� �Է��ϼ���: ");
    for (int i = 0; i < 3; i++)                            // �ݺ����� ���� ��ǥ 3�� �Է�
    {
        scanf_s("%lf", &points[0].coord[i]);               // ù ��° ���� x, y, z ��ǥ �Է�
    }

    printf("�� ��° ���� ��ǥ (x, y, z)�� �Է��ϼ���: ");
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%lf", &points[1].coord[i]);                        // �� ��° ���� x, y, z ��ǥ �Է�
    }

    distance = calculateDistance(&points[0], &points[1]);          // �Ÿ� ��� (�迭�� ���� �ּҸ� �����ͷ� ����)

    printf("�� �� ������ �Ÿ�: %.2lf\n", distance);

    return 0;
}
