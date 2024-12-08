#include <stdio.h>

double calculateDotProduct(double* v1, double* v2)                   // 내적(dot product) 계산 함수
{
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

void calculateCrossProduct(double* v1, double* v2, double* result)   // 외적(cross product) 계산 함수
{
    result[0] = v1[1] * v2[2] - v1[2] * v2[1];                       // x 성분
    result[1] = v1[2] * v2[0] - v1[0] * v2[2];                       // y 성분
    result[2] = v1[0] * v2[1] - v1[1] * v2[0];                       // z 성분
}

void printVector(double* vector, int size)                           // 벡터 출력 함수
{
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", vector[i]);
    }
    printf("\n");
}

int main()
{
    double vector1[3], vector2[3];                                   // 두 개의 3차원 벡터 선언
    double crossProduct[3];                                          // 벡터의 외적의 결과는 3차원 벡터이므로 배열 크기 3으로 지정
    double dotProduct;

    printf("첫 번째 벡터 (x, y, z): ");
    scanf_s("%lf %lf %lf", &vector1[0], &vector1[1], &vector1[2]);

    printf("두 번째 벡터 (x, y, z): ");
    scanf_s
    ("%lf %lf %lf", &vector2[0], &vector2[1], &vector2[2]);

    dotProduct = calculateDotProduct(vector1, vector2);             // 내적 계산

    calculateCrossProduct(vector1, vector2, crossProduct);          // 외적 계산

    printf("내적 : %.2f\n", dotProduct);                            // 내적 결과는 스칼라 값으로 출력
    printf("외적 : ");                                              // 외적 결과는 3차원 벡터로 출력
    printVector(crossProduct, 3);                                   // 외적 결과를 출력하기 위한 함수

    return 0;
}
