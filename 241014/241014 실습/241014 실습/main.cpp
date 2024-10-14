#include <stdio.h>

int main()
{
    int Num1, Num2, Result;                                     //정수 두개, 연산기호에 따른 결과값 저장 변수 지정
    char oper;                                                  //연산기호 변수 지정

    printf("사칙연산 입력(정수): ");
    scanf_s("%d %c %d", &Num1, &oper, sizeof(oper), &Num2);

    if (oper == '+')                                            //입력한 연산자가 +일때의 조건문
    {
        Result = Num1 + Num2;
        printf("%d + %d = %d\n", Num1, Num2, Result);
    }
    else if (oper == '-')                                       //입력한 연산자가 -일때의 조건문
    {
        Result = Num1 - Num2;
        printf("%d - %d = %d\n", Num1, Num2, Result);
    }
    else if (oper == '*')                                       //입력한 연산자가 *일때의 조건문
    {
        Result = Num1 * Num2;
        printf("%d * %d = %d\n", Num1, Num2, Result);
    }
    else if (oper == '/')                                       //입력한 연산자가 /일때의 조건문
    {
        if (Num2 != 0)                                          //나눗셈의 경우 0으로 나눌 수 없으므로 나누는 수가 0이 아닐 때와 0일 때로 구분
        {
            Result = Num1 / Num2;
            printf("%d / %d = %d\n", Num1, Num2, Result);
        }
        else
        {
            printf("0으로 나눌 수 없습니다.\n");
        }
    }
    else                                                        //사칙연산 외의 다른 연산기호 사용 시 계산하지 않음
    {
        printf("잘못된 연산자입니다.\n");
    }

    return 0;
}
