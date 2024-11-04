#include <stdio.h>

int gugudan()
{
	int choice, start, end;

	printf("1. 특정 단 출력\n");      //입력한 숫자의 단 출력
	printf("2. 전체(2~9단) 출력\n");  //2~9단까지 전체 단 출력
	printf("선택(1이나 2): ");
	scanf_s("%d", &choice);

	if (choice == 1)
	{
		printf("출력할 단(2~9): ");
		scanf_s("%d", &start);

		if (start < 2 || start > 9)
		{
			printf("2~9 사이의 숫자 입력.\n");
			return 1;    //오류 종료
		}
		end = start;     //특정 단만 출력
	}
	else if (choice == 2)
	{
		start = 2;
		end = 9;       //2~9단까지 출력
	}
	else
	{
		printf("잘못된 선택입니다.\n");
		return 1;       //오류 종료
	}

	for (int i = start; i <= end; i++)
	{
		printf("---%단 ---\n", i);
		for (int j = 1; j <= 9; j++)
	}
	printf("\n");   //줄바꿈
}

return 0;
}