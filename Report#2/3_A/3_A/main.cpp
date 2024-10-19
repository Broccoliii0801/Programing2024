#include <stdio.h>

int main() {
    float score;  //점수가 실수 범위

    printf("점수를 입력하세요(0.0 ~ 100.0): ");
    scanf_s("%f", &score);

    if (score < 0.0 || score > 100.0)                 //0.0보다 작거나 100.0보다 큰 점수는 나올 수 없음.
    {
        printf("잘못된 점수입니다. 범위에 맞게 입력해 주세요.\n");
    }
    else if (score >= 90.0)           //학점은 각 10의 간격을 두고 구분하며, 60.0점 미만은 F학점으로 처리함.
    {
        printf("A 입니다.\n");
    }
    else if (score >= 80.0)
    {
        printf("B 입니다.\n");
    }
    else if (score >= 70.0)
    {
        printf("C 입니다.\n");
    }
    else if (score >= 60.0)
    {
        printf("D 입니다.\n");
    }
    else
    {
        printf("F 입니다.\n");
    }

    return 0;
}
