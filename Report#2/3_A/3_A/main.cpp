#include <stdio.h>

int main() {
    float score;  //������ �Ǽ� ����

    printf("������ �Է��ϼ���(0.0 ~ 100.0): ");
    scanf_s("%f", &score);

    if (score < 0.0 || score > 100.0)                 //0.0���� �۰ų� 100.0���� ū ������ ���� �� ����.
    {
        printf("�߸��� �����Դϴ�. ������ �°� �Է��� �ּ���.\n");
    }
    else if (score >= 90.0)           //������ �� 10�� ������ �ΰ� �����ϸ�, 60.0�� �̸��� F�������� ó����.
    {
        printf("A �Դϴ�.\n");
    }
    else if (score >= 80.0)
    {
        printf("B �Դϴ�.\n");
    }
    else if (score >= 70.0)
    {
        printf("C �Դϴ�.\n");
    }
    else if (score >= 60.0)
    {
        printf("D �Դϴ�.\n");
    }
    else
    {
        printf("F �Դϴ�.\n");
    }

    return 0;
}
