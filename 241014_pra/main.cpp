#include <stdio.h>

int main()
{
	int a, b;     //정수 2개 각각 저장할 변수 설정
	char cal;                //연산자 저장할 변수 설정
	int result;

	printf("사칙연산 입력(정수): ");
	scanf_s("%d %c %d", &a, &cal, sizeof(cal), & b);     //식이 정수 연산자 정수 순으로 표현되도록 작성

	if(cal == '+')
	{
		result = a + b;
		printf("%d %c %d = %d\n", a, cal, b, result);   //연산자가 +일 경우 정수 두개로 덧셈 계산
     }
	else if(cal == '-')
	{
		result = a - b;
		printf("%d %c %d = %d\n", a, cal, b, result);   //연산자가 -일 경우 정수 두개로 뺄셈 계산
	}
	else if (cal == '*')
	{
		result = a * b;
		printf("%d %c %d = %d\n", a, cal, b, result);   //연산자가 *일 경우 정수 두개로 곱셈 계산
	}
	else if (cal == '/')
	{
		if (b != 0)
		{
			result = a / b;
			printf("%d %c %d = %d\n", a, cal, b, result);           //연산자가 /일 경우 정수 두개로 나눗셈 계산
		}
		else
			printf("0은 사용할 수 없습니다.\n");             //0으로는 나눌 수 없음
	}
	else
	{
		printf("잘못된 기호입니다.\n");                      //사칙연산이 아닌 연산 기호 입력 시 출력되는 문장
	}

	return 0;
}