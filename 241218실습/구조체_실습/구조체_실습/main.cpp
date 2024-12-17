#include <stdio.h>
#include <math.h>

// Euclidean Distance 계산 함수
double calculateDistance(double* p1, double* p2) {
    return sqrt(pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2) + pow(p2[2] - p1[2], 2));
}

int main() {
    double point1[3], point2[3]; // 두 점의 좌표를 저장할 배열
    double distance;

    // 사용자로부터 첫 번째 점의 좌표 입력 받기
    printf("첫 번째 점의 좌표 (x, y, z)를 입력하세요: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%lf", &point1[i]);
    }

    // 사용자로부터 두 번째 점의 좌표 입력 받기
    printf("두 번째 점의 좌표 (x, y, z)를 입력하세요: ");
    for (int i = 0; i < 3; i++) {
        scanf_s("%lf", &point2[i]);
    }

    // 거리 계산 (배열의 시작 주소를 포인터로 전달)
    distance = calculateDistance(point1, point2);

    // 결과 출력
    printf("두 점 사이의 거리: %.2lf\n", distance);

    return 0;
}
