#include <stdio.h>

int main()
{
    int num;

    printf("정수를 입력하세요: ");
    scanf_s("%d", &num);

    if (num % 2 == 0)            // 2로 정수를 나누었을 때, 나머지가 0이면 짝수, 아니면 홀수.
    {                                   
        printf("입력한 수 %d는 짝수입니다.\n", num);
    }
    else
    {
        printf("입력한 수 %d는 홀수입니다.\n", num);
    }

    return 0;
}
