#include<stdio.h>
#define PI 3.141592  //원주율 정의

int main(void)
{
	float radius, surfacearea, volume;

	printf("구의 반지름을 입력하세요");
	scanf_s("%f", &radius);

	surfacearea = 4 * radius * radius * PI;
	volume = 4 / 3 * radius * radius * PI;

	printf("구의 표면적 : %.2f\n", surfacearea);
	printf("구의 표면적 : %.2f\n", volume);

	return 0;
}
