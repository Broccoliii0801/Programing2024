#include <stdio.h>

int main()
{
    int num;

    printf("������ �Է��ϼ���: ");
    scanf_s("%d", &num);

    if (num % 2 == 0)            // 2�� ������ �������� ��, �������� 0�̸� ¦��, �ƴϸ� Ȧ��.
    {                                   
        printf("�Է��� �� %d�� ¦���Դϴ�.\n", num);
    }
    else
    {
        printf("�Է��� �� %d�� Ȧ���Դϴ�.\n", num);
    }

    return 0;
}
