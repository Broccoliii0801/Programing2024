#include <stdio.h>

int main()
{
    int num1, num2;

    printf("�� ���� ���� �Է��ϼ���: ");
    scanf_s("%d %d", &num1, &num2);

    switch (num2)
    {
    case 0:                                 //ù case�� �� ��° ������ 0�� ����̴�. 
                                            //�� ��° ���� 0�� ��Ȳ������ �� ���� ��� ���谡 �� �� �����Ƿ� ���� case�� �������ش�.
        printf("0���� ���� �� �����ϴ�.\n");
        break;
    default:
        switch (num1 % num2)                                   //�� ��° ������ 0�� �ƴ� ��쿡�� ���� case�� �����Ѵ�.
        {
        case 0:                                                //���� case�� ù ��° ���� �� ��° ���� ������ ���� �������� �� ���� ��� ���踦 �Ǵ��Ѵ�.
            printf("%d�� %d�� ����Դϴ�.\n", num1, num2);
            break;
        default:
            printf("%d�� %d�� ����� �ƴմϴ�.\n", num1, num2);
            break;
        }
    }

    return 0;
}
