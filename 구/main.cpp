#include<stdio.h>
#define PI 3.141592  //������ ����

int main(void)
{
	float radius, surfacearea, volume;

	printf("���� �������� �Է��ϼ���");
	scanf_s("%f", &radius);

	surfacearea = 4 * radius * radius * PI;
	volume = 4 / 3 * radius * radius * PI;

	printf("���� ǥ���� : %.2f\n", surfacearea);
	printf("���� ǥ���� : %.2f\n", volume);

	return 0;
}
