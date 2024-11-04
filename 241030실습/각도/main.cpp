#include <stdio.h>
#include <math.h>    //sin, cos 함수 사용을 위해 사용

#define PI 3.141592

double degtorad(double degree)
{
	return degree * (PI / 180.0);   //각도를 라디안으로 변환
}

int main()
{
	double degree, calsin, calcos;
	printf("각도를 입력하세요(0-180): \n");
	scanf_s("%lf", &degree);

	if (degree < 0 || degree > 180)    //각도 범위 확인
	{
		printf("잘못된 값입니다.\n");
		return 1;
	}

	calsin = sin(degtorad(degree));    /sin, cos 값 계산
	calcos = cos(degtorad(degree));

	printf("각도: %.0lf, sin: %.4lf, cos: %.4lf\n", degree, calsin, calcos);

	return 0;
}