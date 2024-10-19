#include <stdio.h>

int main()
{
    int num1, num2;

    printf("두 개의 수를 입력하세요: ");
    scanf_s("%d %d", &num1, &num2);

    switch (num2)
    {
    case 0:                                 //첫 case는 두 번째 정수가 0일 경우이다. 
                                            //두 번째 수가 0인 상황에서는 두 수가 배수 관계가 될 수 없으므로 먼저 case를 구분해준다.
        printf("0으로 나눌 수 없습니다.\n");
        break;
    default:
        switch (num1 % num2)                                   //두 번째 정수가 0이 아닌 경우에는 다음 case를 적용한다.
        {
        case 0:                                                //다음 case로 첫 번째 수를 두 번째 수로 나눴을 때의 나머지로 두 수의 배수 관계를 판단한다.
            printf("%d는 %d의 배수입니다.\n", num1, num2);
            break;
        default:
            printf("%d는 %d의 배수가 아닙니다.\n", num1, num2);
            break;
        }
    }

    return 0;
}
