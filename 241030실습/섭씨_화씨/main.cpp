#include <stdio.h>

int Celtofah(double celsius)   //������  ȭ���� ��ȯ�ϴ� �Լ�
{
	double fah = (celsius * 9.0 / 5.0) + 32.0;
	printf("ȭ���µ�: %.2f F\n", fah);
	return 0;
}

int Fahtocel(double fahrenheit)  //ȭ���� ������ ��ȯ�ϴ� �Լ�
{
	double cel = (fahrenheit - 32.0) * 5.0 / 9.0;
	printf("�����µ�: %.2f C\n", cel);
	return 0;
}
int main()
{
	int choice;
	double temp;

	printf("�µ���ȯ\n");
	printf("1.���� > ȭ��\n");
	printf("2.ȭ�� > ����\n");
	printf("����(1 �Ǵ� 2) :");
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		printf("���� �µ��� �Է��ϼ���: ");
		scanf_s("%lf", &temp);
		Celtofah(temp);
	}
	else if (choice == 2)
	{
		printf("ȭ�� �µ��� �Է��ϼ���: ");
		scanf_s("%lf", &temp);
		Fahtocel(temp);
	}
	else
	{
		printf("�����Դϴ�.\n");
	}

	return 0;
}