#include <stdio.h>

#define Tria(base, height) ((base) * (height)* (1/2))  //�ﰢ���� ����


int main(void)
{
	double base;
	double height;
	double area;

	printf("base, height");
	scanf_s("%lf", "%height");
	area = Tria(base, height);

	return 0;
}