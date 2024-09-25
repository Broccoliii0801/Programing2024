#include <stdio.h>

int main(void)
{
	float base, height, area;   //삼각형의 밑변, 높이, 넓이 값

	printf("삼각형의 밑변을 입력하세요 : ");
	scanf_s("%f", &base);

	printf("삼각형의 높이를 입력하세요 : ");
	scanf_s("%f", &height);

	area = (base * height) / 2;  //삼각형의 넓이 구하는 공식

	printf("삼각형의 넓이 : %.2f\n", area);

	return 0;
}