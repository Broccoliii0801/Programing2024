#include <stdio.h>

int main()
{
	int a, b;
	char oper;

	printf("��Ģ���� �Է�(����):");
	scanf_s("%d %c %d", &a, &oper, sizeof(oper), &b);

	switch (oper)
	{
	case '+':
			printf("%d + %d = %d\n", a, b, a + b);
			break;
	case '-':
			printf("%d - %d = %d\n", a, b, a - b);
			break;
	case '*':
			printf("%d * %d = %d\n", a, b, a * b);
			break;
	case '/':
	  {
		if (b != 0)
			printf("%d / %d = %d\n", a, b, a / b);
		else
			printf("0���� ���� �� �����ϴ�.\n");
	   }
		break;
			default:
				printf("�߸��� �������Դϴ�.\n");
	}
	return 0;
}