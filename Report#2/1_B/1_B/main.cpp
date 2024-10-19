#include <stdio.h>

int main() 
{
    int num;

    printf("정수를 입력하세요: ");
    scanf_s("%d", &num);

    switch (num % 2)
    {
    case 0:
        printf("입력한 수 %d는 짝수입니다.\n", num);
        break;
    case 1:
        printf("입력한 수 %d는 홀수입니다.\n", num);
        break;
    default:
        printf("오류가 발생했습니다.\n");
        break;
    }

    return 0;
}
