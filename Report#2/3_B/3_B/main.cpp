#include <stdio.h>

int main()
{
    float score;  //������ �Ǽ� ����

    printf("������ �Է��ϼ���(0.0 ~ 100.0): ");
    scanf_s("%f", &score);

    if (score < 0.0 || score > 100.0)       //������ 0.0���� ���ų� 100.0���� ���� �� ����
    {
        printf("�߸��� �����Դϴ�. ������ �°� �Է��� �ּ���.\n");
    }
    else
    {
        switch ((int)(score / 10))         //swtich-case �������� ������ ������ �Է� �����ϹǷ� 10���� ���� ���� �κ��� ���
        {
        case 10:
        case 9:
            printf("A �Դϴ�.\n");
            break;
        case 8:
            printf("B �Դϴ�.\n");
            break;
        case 7:
            printf("C �Դϴ�.\n");
            break;
        case 6:
            printf("D �Դϴ�.\n");
            break;
        default:
            printf("F �Դϴ�.\n");
            break;
        }
    }

    return 0;
}