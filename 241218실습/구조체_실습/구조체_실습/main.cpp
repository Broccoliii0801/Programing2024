#include <stdio.h>
#include <math.h>

struct Point3D                                             // 3차원 공간 상의 두 점을 나타내는 구조체 선언
{
    double coord[3];
};


double calculateDistance(struct Point3D* p1, struct Point3D* p2)         // Euclidean Distance 계산 함수 (유클리드 거리 공식)
{
    return sqrt(pow(p2 -> coord[0] - p1 -> coord[0], 2) +          // p1은 첫 번째, p2는 두 번째 점
                pow(p2 -> coord[1] - p1 -> coord[1], 2) +          // p2 -> coord[1]: p2 포인터가 가리키는 구조체의 y좌표
                pow(p2 -> coord[2] - p1 -> coord[2], 2));          // pow(~, 2): pow 함수를 이용해 제곱
}                                                        

int main()
{
    struct Point3D points[2];                      // 두 점의 좌표를 저장할 구조체 배열
    double distance;

    printf("첫 번째 점의 좌표 (x, y, z)를 입력하세요: ");
    for (int i = 0; i < 3; i++)                            // 반복문을 통해 좌표 3개 입력
    {
        scanf_s("%lf", &points[0].coord[i]);               // 첫 번째 점의 x, y, z 좌표 입력
    }

    printf("두 번째 점의 좌표 (x, y, z)를 입력하세요: ");
    for (int i = 0; i < 3; i++)
    {
        scanf_s("%lf", &points[1].coord[i]);                        // 두 번째 점의 x, y, z 좌표 입력
    }

    distance = calculateDistance(&points[0], &points[1]);          // 거리 계산 (배열의 시작 주소를 포인터로 전달)

    printf("두 점 사이의 거리: %.2lf\n", distance);

    return 0;
}
