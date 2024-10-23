#include <stdio.h>

int main()
{
	int num1, num2, a, b;
	printf("두 수를 입력하세요: ");
	scanf_s("%d %d", &num1, &num2);

	a = num1;
	b = num2;
	
	while (b != 0)        //두 수의 공배수, 약수 구하기 위해 숫자가 0이 아니어야 함
	{
		a = a + b;
		b = a - b;
		a = a - b;
		b = a % b;        //최소공배수와 최대공약수 구하기 위한 알고리즘 과정
	}

	printf("최소공배수: %d", a);
	printf("최대공약수: %d\n", (num1 * num2) / a);  //최소공배수를 구한 값으로 최대공약수 출력

	return 0;
}