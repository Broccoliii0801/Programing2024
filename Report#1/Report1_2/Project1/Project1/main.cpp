#include <stdio.h>

int main() {
    int Money, Price, Totalchange, change;         // ������ �ݾ�, ���� ����, �Ž�����, ����(����) ����
    int W1000, W500, W100;                         // 1000���� ����, 500���� ����, 100���� ����

    // �Է¹ޱ�
    printf("������ �ݾװ� ���ǰ��� ���ʴ�� �Է��ϼ��� (��): ");
    scanf_s("%d %d", &Money, &Price);

    Totalchange = (Money - Price);  // �� �Ž����� �Ի�

    W1000 = Totalchange / 1000;     // 1000�� ���� ����, �� �Ž��������� ���
    change = Totalchange % 1000;

    W500 = change / 500;       // 500�� ���� ����, 1000�� ���� ������ �������� ���
    change = change % 500;

    W100 = change / 100;       // 100�� ���� ����, 500�� ���� ������ �������� ���
    change = change % 100;

    printf("�Ž������� ������ �����ϴ�:\n");       // 1000�� ������� ������������ ������ ���� ���
    printf("�Ž�����: %d��\n", Totalchange);       // �� �Ÿ����� �׼� ���
    printf("1000�� ����: %d��\n", W1000);
    printf("500�� ����: %d��\n", W500);
    printf("100�� ����: %d��\n", W100);
    printf("���� �ܵ�: %d��\n", change);

    return 0;
}