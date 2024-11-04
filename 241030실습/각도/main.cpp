#include <stdio.h>
#include <math.h>    //sin, cos �Լ� ����� ���� ���

#define PI 3.141592

double degtorad(double degree)
{
	return degree * (PI / 180.0);   //������ �������� ��ȯ
}

int main()
{
	double degree, calsin, calcos;
	printf("������ �Է��ϼ���(0-180): \n");
	scanf_s("%lf", &degree);

	if (degree < 0 || degree > 180)    //���� ���� Ȯ��
	{
		printf("�߸��� ���Դϴ�.\n");
		return 1;
	}

	calsin = sin(degtorad(degree));    /sin, cos �� ���
	calcos = cos(degtorad(degree));

	printf("����: %.0lf, sin: %.4lf, cos: %.4lf\n", degree, calsin, calcos);

	return 0;
}