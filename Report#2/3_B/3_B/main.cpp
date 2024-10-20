#include <stdio.h>

int main()
{
    float score;  //점수는 실수 범위

    printf("점수를 입력하세요(0.0 ~ 100.0): ");
    scanf_s("%f", &score);

    if (score < 0.0 || score > 100.0)       //점수는 0.0보다 낮거나 100.0보다 높을 수 없음
    {
        printf("잘못된 점수입니다. 범위에 맞게 입력해 주세요.\n");
    }
    else
    {
        switch ((int)(score / 10))         //swtich-case 문에서는 정수형 변수만 입력 가능하므로 10으로 나눈 정수 부분을 사용
        {
        case 10:
        case 9:
            printf("A 입니다.\n");
            break;
        case 8:
            printf("B 입니다.\n");
            break;
        case 7:
            printf("C 입니다.\n");
            break;
        case 6:
            printf("D 입니다.\n");
            break;
        default:
            printf("F 입니다.\n");
            break;
        }
    }

    return 0;
}