#include <stdio.h>

int main(void)
{
	float kg, slug;

	printf("kg를 입력하세요 : ");
	scanf_s("%f", &kg);

	slug = kg * 0.0685;

	printf("%.2f kg는 %.2f slug 입니다.\n", kg, slug);

	return 0;
}