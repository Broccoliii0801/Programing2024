#include <stdio.h>

int main()
{
	int num1, num2, a, b;
	printf("�� ���� �Է��ϼ���: ");
	scanf_s("%d %d", &num1, &num2);

	a = num1;
	b = num2;
	do {
		a = a + b;
		b = a - b;
		a = a - b;
		b = a % b;
	} while (b != 0);

	printf("�ּҰ����: %d\n", a);
	printf("�ִ�����: %d\n", (num1 * num2) / a);

	return 0;
}