#include <stdio.h>

double 360Range(double angle) {
    angle = (angle + 180) - 360 * (int)((angle + 180) / 360) - 180;              //0~360�� ������ ��ǥ�� -180~180���� ������ ��ȯ�ϱ� ���� ����, �Էµ� ������ �Ǽ� �������� �Է��ϱ� ���� int ������ �̿�

    return angle;                                                                //���� ��ȯ �Լ����� ��ȯ�� ���� ��ȯ
}

int main() {
    double angle;

    printf("0 ~ 360�� ������ ������ �Է��ϼ���: ");                              // ����ڷκ��� ������ �Է¹���
    scanf_s("%lf", &angle);

    double 180Range = 360Range(angle);                            // ������ -180 ~ 180�� ������ ��ȯ�Ͽ� ���
    printf("��ȯ�� ����: %lf ��\n", 180Range);

    return 0;
}
