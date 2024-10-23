#include <stdio.h>

int main()
{
	int num1, num2, a, b;
	printf("두 수를 입력하세요: ");
	scanf_s("%d %d", &num1, &num2);

	a = num1;
	b = num2;
	do {
		a = a + b;
		b = a - b;
		a = a - b;
		b = a % b;
	} while (b != 0);

	printf("최소공배수: %d\n", a);
	printf("최대공약수: %d\n", (num1 * num2) / a);

	return 0;
}