#include <stdio.h>
#define PI 3.141592  //������ ��

int main(void)
{
	float radius, area;   //���� ������ �� �Է�

	printf("���� �������� �Է��ϼ��� : ");
	scanf_s("%f", &radius);

	area = PI * radius * radius;  //���� ���� ���ϴ� ����

	printf("���� ���� : %.2f\n", area);

	return 0;
}