#include <stdio.h>

int main(void)
{
	float base, height, area;   //�簢���� �غ�, ����, ���� ��

	printf("�簢���� ���� ���̸� �Է��ϼ��� : ");
	scanf_s("%f", &base);

	printf("�簢���� ���� ���̸� �Է��ϼ��� : ");
	scanf_s("%f", &height);

	area = (base * height);  //�簢���� ���� ���ϴ� ����

	printf("�簢���� ���� : %.2f\n", area);

	return 0;
}