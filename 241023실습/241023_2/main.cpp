#include <stdio.h>

int main()
{
	int num1, num2, a, b;
	printf("�� ���� �Է��ϼ���: ");
	scanf_s("%d %d", &num1, &num2);

	a = num1;
	b = num2;
	
	while (b != 0)        //�� ���� �����, ��� ���ϱ� ���� ���ڰ� 0�� �ƴϾ�� ��
	{
		a = a + b;
		b = a - b;
		a = a - b;
		b = a % b;        //�ּҰ������ �ִ����� ���ϱ� ���� �˰��� ����
	}

	printf("�ּҰ����: %d", a);
	printf("�ִ�����: %d\n", (num1 * num2) / a);  //�ּҰ������ ���� ������ �ִ����� ���

	return 0;
}