#include <stdio.h>

int Celtofah(double celsius)   //섭씨를  화씨로 변환하는 함수
{
	double fah = (celsius * 9.0 / 5.0) + 32.0;
	printf("화씨온도: %.2f F\n", fah);
	return 0;
}

int Fahtocel(double fahrenheit)  //화씨를 섭씨로 변환하는 함수
{
	double cel = (fahrenheit - 32.0) * 5.0 / 9.0;
	printf("섭씨온도: %.2f C\n", cel);
	return 0;
}
int main()
{
	int choice;
	double temp;

	printf("온도변환\n");
	printf("1.섭씨 > 화씨\n");
	printf("2.화씨 > 섭씨\n");
	printf("선택(1 또는 2) :");
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		printf("섭씨 온도를 입력하세요: ");
		scanf_s("%lf", &temp);
		Celtofah(temp);
	}
	else if (choice == 2)
	{
		printf("화씨 온도를 입력하세요: ");
		scanf_s("%lf", &temp);
		Fahtocel(temp);
	}
	else
	{
		printf("오류입니다.\n");
	}

	return 0;
}