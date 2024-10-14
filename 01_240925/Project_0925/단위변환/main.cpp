#include <stdio.h>

int main(void)
{
	float meter, feet, inch;

	printf("미터를 입력하세요 : ");
	scanf_s("%f", &meter);

	feet = meter * 3.281;
	inch = meter * 39.37;

	printf("%.2f 미터는 %.2f 피트 / %.2f 인치입니다.\n", meter, feet, inch);

		return 0;

}