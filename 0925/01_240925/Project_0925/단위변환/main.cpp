#include <stdio.h>

int main(void)
{
	float meter, feet, inch;

	printf("���͸� �Է��ϼ��� : ");
	scanf_s("%f", &meter);

	feet = meter * 3.281;
	inch = meter * 39.37;

	printf("%.2f ���ʹ� %.2f ��Ʈ / %.2f ��ġ�Դϴ�.\n", meter, feet, inch);

		return 0;

}