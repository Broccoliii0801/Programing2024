#include <stdio.h>
#include <math.h>

#define PI 3.141592

double degtorad(double degree)
{
	return degree * (PI / 180.0);
}

int main()
{
	double degree, calsin, calcos;
	printf("각도를 입력하세요(0-180): \n");
	scanf_s("%lf", &degree);

	if (degree < 0 || degree > 180)
	{
		printf("잘못된 값입니다.\n");
		return 1;
	}

	calsin = sin(degtorad(degree));
	calcos = cos(degtorad(degree));

	printf("각도: %.0lf, sin: %.4lf, cos: %.4lf\n", degree, calsin, calcos);

	return 0;
}