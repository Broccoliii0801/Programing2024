#include <stdio.h>

int main(void)
{
	float kg, slug;

	printf("kg�� �Է��ϼ��� : ");
	scanf_s("%f", &kg);

	slug = kg * 0.0685;

	printf("%.2f kg�� %.2f slug �Դϴ�.\n", kg, slug);

	return 0;
}