#include <stdio.h>

int main(void)
{
	float base, height, area;   //�ﰢ���� �غ�, ����, ���� ��

	printf("�ﰢ���� �غ��� �Է��ϼ��� : ");
	scanf_s("%f", &base);

	printf("�ﰢ���� ���̸� �Է��ϼ��� : ");
	scanf_s("%f", &height);

	area = (base * height) / 2;  //�ﰢ���� ���� ���ϴ� ����

	printf("�ﰢ���� ���� : %.2f\n", area);

	return 0;
}