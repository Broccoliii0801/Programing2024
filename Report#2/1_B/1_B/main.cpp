#include <stdio.h>

int main() 
{
    int num;

    printf("������ �Է��ϼ���: ");
    scanf_s("%d", &num);

    switch (num % 2)
    {
    case 0:
        printf("�Է��� �� %d�� ¦���Դϴ�.\n", num);
        break;
    case 1:
        printf("�Է��� �� %d�� Ȧ���Դϴ�.\n", num);
        break;
    default:
        printf("������ �߻��߽��ϴ�.\n");
        break;
    }

    return 0;
}
