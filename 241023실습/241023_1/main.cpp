#include <stdio.h>

int gugudan()
{
	int choice, start, end;

	printf("1. Ư�� �� ���\n");      //�Է��� ������ �� ���
	printf("2. ��ü(2~9��) ���\n");  //2~9�ܱ��� ��ü �� ���
	printf("����(1�̳� 2): ");
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		printf("����� ��(2~9): ");
		scanf_s("%d", &start);

		if (start < 2 || start > 9)
		{
			printf("2~9 ������ ���� �Է�.\n");
			return 1;    //���� ����
		}
		end = start;     //Ư�� �ܸ� ���
	}
	else if (choice == 2)
	{
		start = 2;
		end = 9;       //2~9�ܱ��� ���
	}
	else
	{
		printf("�߸��� �����Դϴ�.\n");
		return 1;       //���� ����
	}

	for (int i = start; i <= end; i++)
	{
		printf("---%�� ---\n", i);
		for (int j = 1; j <= 9; j++)
	}
	printf("\n");   //�ٹٲ�
}

return 0;
}