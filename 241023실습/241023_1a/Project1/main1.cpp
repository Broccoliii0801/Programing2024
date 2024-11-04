#include <stdio.h>

void gugudan(int start, int end)      //입력받은 범위의 구구단을 출력하도록 설정
{
	for (int i = start; i <= end; i++)
	{
		printf("---%단 ---\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("%d * %d = %d\n", i, j, i * j);   //for문으로 연산을 숫자를 변경하면서 반복
		}
		printf("\n");    //단과 단 사이에 줄바꿈
	}
}

int main()
{
	int choice;   //사용자가 선택하도록 안내 문구 출력

	printf("1. 특정 단 출력\n");      //입력한 숫자의 단 출력
	printf("2. 전체(2~9단) 출력\n");  //2~9단까지 전체 단 출력
	printf("선택(1이나 2): ");
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		int dan = 0;
		printf("출력할 단(2~9) : ");
		scanf_s("%d", &dan);

		if (dan >= 2 && dan <= 9)
		{
			gugudan(dan, dan);         //특정 단 출력
		}
		else
		{
			printf("2~9 사이의 수를 입력하세요.\n");
		}
	}
	else if (choice == 2)
	{
		gugudan(2, 9);                 //2~9단까지 출력
	}
	else
	{
		printf("잘못된 선택입니다.\n");
	}

	return 0;
}