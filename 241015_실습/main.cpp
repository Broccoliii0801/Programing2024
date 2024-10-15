#include <stdio.h>

int main()
{
	int a, b;
	char oper;

	printf("사칙연산 입력(정수):");
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
			printf("0으로 나눌 수 없습니다.\n");
	   }
		break;
			default:
				printf("잘못된 연산자입니다.\n");
	}
	return 0;
}