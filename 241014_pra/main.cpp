#include <stdio.h>

int main()
{
	int a, b;     //���� 2�� ���� ������ ���� ����
	char cal;                //������ ������ ���� ����
	int result;

	printf("��Ģ���� �Է�(����): ");
	scanf_s("%d %c %d", &a, &cal, sizeof(cal), & b);     //���� ���� ������ ���� ������ ǥ���ǵ��� �ۼ�

	if(cal == '+')
	{
		result = a + b;
		printf("%d %c %d = %d\n", a, cal, b, result);   //�����ڰ� +�� ��� ���� �ΰ��� ���� ���
     }
	else if(cal == '-')
	{
		result = a - b;
		printf("%d %c %d = %d\n", a, cal, b, result);   //�����ڰ� -�� ��� ���� �ΰ��� ���� ���
	}
	else if (cal == '*')
	{
		result = a * b;
		printf("%d %c %d = %d\n", a, cal, b, result);   //�����ڰ� *�� ��� ���� �ΰ��� ���� ���
	}
	else if (cal == '/')
	{
		if (b != 0)
		{
			result = a / b;
			printf("%d %c %d = %d\n", a, cal, b, result);           //�����ڰ� /�� ��� ���� �ΰ��� ������ ���
		}
		else
			printf("0�� ����� �� �����ϴ�.\n");             //0���δ� ���� �� ����
	}
	else
	{
		printf("�߸��� ��ȣ�Դϴ�.\n");                      //��Ģ������ �ƴ� ���� ��ȣ �Է� �� ��µǴ� ����
	}

	return 0;
}