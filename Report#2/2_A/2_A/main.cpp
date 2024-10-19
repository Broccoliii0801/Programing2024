#include <stdio.h>

int main()
{
    int num1, num2;

    printf("수를 입력하세요: ");
    scanf_s("%d %d", &num1, &num2);

    if (num2 != 0 && num1 % num2 == 0)                  //배수 관계가 되기 위해서는 두번째 정수가 0이 아니어야 하고, 첫번째 수를 두번째 수로 나눴을 때 나머지가 0이어야 한다.
                                                        //또한 첫번째 정수가 두번째 정수의 배수가 되기 위해서는 앞의 조건들을 동시에 만족시켜야 한다.
    {        printf("%d는 %d의 배수입니다.\n", num1, num2);  
    }
    else
    {
        printf("%d는 %d의 배수가 아닙니다.\n", num1, num2);
    }

    return 0;
}
