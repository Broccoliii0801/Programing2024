#include <stdio.h>
#include <string.h>

void reverseword(char *start, char *end)     // 문자열을 뒤집는 함수
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

	input[strcspn(input, "\n")] = '\0';   // 개행 문자를 제거

	char *start = input;
	char *end = input;

	while (*end != '\0')        // 입력한 각 단어를 뒤집기
	{
		if (*end == ' ')        // 최소 하나의 문자가 있어야 하므로 띄워쓰기 입력
		{
			reverseword(start, end - 1);
			start = end + 1;
		}
		end++;
	}

	reverseword(start, end - 1);      // 마지막으로 단어 뒤집기

	printf("Reversed string: %s\n", input);
	return 0;
}