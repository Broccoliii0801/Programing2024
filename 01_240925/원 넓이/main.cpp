#include <stdio.h>
#define PI 3.141592  //원주율 값

int main(void)
{
	float radius, area;   //원의 반지름 값 입력

	printf("원의 반지름을 입력하세요 : ");
	scanf_s("%f", &radius);

	area = PI * radius * radius;  //원의 넓이 구하는 공식

	printf("원의 넓이 : %.2f\n", area);

	return 0;
}