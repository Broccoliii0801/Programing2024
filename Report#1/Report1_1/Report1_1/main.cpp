#include <stdio.h>

double 360Range(double angle) {
    angle = (angle + 180) - 360 * (int)((angle + 180) / 360) - 180;              //0~360도 범위인 좌표를 -180~180도의 범위로 전환하기 위한 수식, 입력된 각도를 실수 범위까지 입력하기 위해 int 연산자 이용

    return angle;                                                                //위의 변환 함수에서 변환된 값을 반환
}

int main() {
    double angle;

    printf("0 ~ 360도 범위의 각도를 입력하세요: ");                              // 사용자로부터 각도를 입력받음
    scanf_s("%lf", &angle);

    double 180Range = 360Range(angle);                            // 각도를 -180 ~ 180도 범위로 변환하여 출력
    printf("변환된 각도: %lf 도\n", 180Range);

    return 0;
}
