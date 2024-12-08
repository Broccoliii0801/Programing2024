#include <stdio.h>

int main(void)
{
	char str[100];
	int count = 0;
	int i;

	printf("문장 입력 : ");
	gets_s(str);               // 빈칸을 포함해 문자열을 입력하는 함수

	for (i = 0; str[i] != '\0'; i++)        // 문자열의 끝에 도달했을 때, str[i] == \0이 되어서 반복문 종료.
		                                    // \n 사용 시 널 문자가 출력되어 오류 발생, 문자 배열 출력 시 \0 사용하면 정상 출력
	{
		if ('A' <= str[i] && str[i] <= 'Z')   // A ~ Z 사이의 대문자들에 해당할 경우
		{
			str[i] += 32;                // 아스키코드 값을 이용해 소문자로 변환
			count++;
		}
	}

	printf("바뀐 문장 : ");
	puts(str);                  // 문자열 출력
	printf("바뀐 문자 수 : %d\n", count);

	return 0;
}