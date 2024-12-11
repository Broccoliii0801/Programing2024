#include <stdio.h>
#include <string.h>

void reverseword(char *start, char *end)     // ���ڿ��� ������ �Լ�
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

int main()
{
	char input[100];

	printf("Enter a string: ");
	fgets(input, sizeof(input), stdin);

	input[strcspn(input, "\n")] = '\0';   // ���� ���ڸ� ����

	char *start = input;
	char *end = input;

	while (*end != '\0')        // �Է��� �� �ܾ ������
	{
		if (*end == ' ')        // �ּ� �ϳ��� ���ڰ� �־�� �ϹǷ� ������� �Է�
		{
			reverseword(start, end - 1);
			start = end + 1;
		}
		end++;
	}

	reverseword(start, end - 1);      // ���������� �ܾ� ������

	printf("Reversed string: %s\n", input);
	return 0;
}