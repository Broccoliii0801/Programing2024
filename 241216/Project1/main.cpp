#include <stdio.h>

int main(void)
{
	FILE* fp;

	fopen_s(&fp, "test_read.text", "r");
	if (fp == NULL)
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return 1;
	}
	printf("������ ���Ƚ��ϴ�.\n");
	fclose(fp);

	return 0;
}