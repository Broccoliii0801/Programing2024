#include <stdio.h>

int main()
{
    int Num1, Num2, Result;                                     //���� �ΰ�, �����ȣ�� ���� ����� ���� ���� ����
    char oper;                                                  //�����ȣ ���� ����

    printf("��Ģ���� �Է�(����): ");
    scanf_s("%d %c %d", &Num1, &oper, sizeof(oper), &Num2);

    if (oper == '+')                                            //�Է��� �����ڰ� +�϶��� ���ǹ�
    {
        Result = Num1 + Num2;
        printf("%d + %d = %d\n", Num1, Num2, Result);
    }
    else if (oper == '-')                                       //�Է��� �����ڰ� -�϶��� ���ǹ�
    {
        Result = Num1 - Num2;
        printf("%d - %d = %d\n", Num1, Num2, Result);
    }
    else if (oper == '*')                                       //�Է��� �����ڰ� *�϶��� ���ǹ�
    {
        Result = Num1 * Num2;
        printf("%d * %d = %d\n", Num1, Num2, Result);
    }
    else if (oper == '/')                                       //�Է��� �����ڰ� /�϶��� ���ǹ�
    {
        if (Num2 != 0)                                          //�������� ��� 0���� ���� �� �����Ƿ� ������ ���� 0�� �ƴ� ���� 0�� ���� ����
        {
            Result = Num1 / Num2;
            printf("%d / %d = %d\n", Num1, Num2, Result);
        }
        else
        {
            printf("0���� ���� �� �����ϴ�.\n");
        }
    }
    else                                                        //��Ģ���� ���� �ٸ� �����ȣ ��� �� ������� ����
    {
        printf("�߸��� �������Դϴ�.\n");
    }

    return 0;
}
