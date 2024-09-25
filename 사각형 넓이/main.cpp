#include <stdio.h>

int main(void)
{
	float base, height, area;   //사각형의 밑변, 높이, 넓이 값

	printf("사각형의 가로 길이를 입력하세요 : ");
	scanf_s("%f", &base);

	printf("사각형의 세로 길이를 입력하세요 : ");
	scanf_s("%f", &height);

	area = (base * height);  //사각형의 넓이 구하는 공식

	printf("사각형의 넓이 : %.2f\n", area);

	return 0;
}