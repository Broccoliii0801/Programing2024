#include <stdio.h>

void gugudan(int start, int end)      //�Է¹��� ������ �������� ����ϵ��� ����
{
	for (int i = start; i <= end; i++)
	{
		printf("---%�� ---\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);   //for������ ������ ���ڸ� �����ϸ鼭 �ݺ�
		}
		printf("\n");    //�ܰ� �� ���̿� �ٹٲ�
	}
}

int main()
{
	int choice;   //����ڰ� �����ϵ��� �ȳ� ���� ���

	printf("1. Ư�� �� ���\n");      //�Է��� ������ �� ���
	printf("2. ��ü(2~9��) ���\n");  //2~9�ܱ��� ��ü �� ���
	printf("����(1�̳� 2): ");
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		int dan = 0;
		printf("����� ��(2~9) : ");
		scanf_s("%d", &dan);

		if (dan >= 2 && dan <= 9)
		{
			gugudan(dan, dan);         //Ư�� �� ���
		}
		else
		{
			printf("2~9 ������ ���� �Է��ϼ���.\n");
		}
	}
	else if (choice == 2)
	{
		gugudan(2, 9);                 //2~9�ܱ��� ���
	}
	else
	{
		printf("�߸��� �����Դϴ�.\n");
	}

	return 0;
}