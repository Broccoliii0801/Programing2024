#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculate(int* arr, int size, double* sum, double* mean, double* variance, double* std_dev) // 합계, 평균, 분산, 표준편차를 구하기 위한 계산 함수
{
    double sqr_sum = 0;    // 편차의 제곱의 합계 저장하기 위해 변수 sqr_sum 사용
    *sum = 0;
    for (int i = 0; i < size; i++)
    *sum += arr[i];
    *mean = *sum / size;
    for (int i = 0; i < size; i++) 
    sqr_sum += pow(arr[i] - *mean, 2);   // pow(arr[i] - *mean, 2) : 배열의 각 값에서 평균을 빼고 이를 제곱한 값, 이 값을 sqr_sum에 누적해서 더해나감
    *variance = sqr_sum / size;   // 분산 계산
    *std_dev = sqrt(*variance);   // 표준편차 = 분산의 제곱근
}

int main()
{
    int* arr = NULL, size, extra;  // NULL로 동적 메모리를 할당하기 전에 초기화

    printf("초기 배열 크기 입력: ");
    scanf_s("%d", &size);
    
    arr = (int *)malloc(size * sizeof(int));  // 입력받은 크기에 따라 동적 메모리 할당, 포인터를 int *로 변환
    if (!arr)
    {
        printf("메모리 할당 실패\n");
        return 1;    // 할당 실패 시 종료
    }

    printf("%d개의 정수 입력: ", size);
    for (int i = 0; i < size; i++)
        scanf_s("%d", &arr[i]);

    double initialsum, initialmean, initialvariance, initialstd_dev;
    calculate(arr, size, &initialsum, &initialmean, &initialvariance, &initialstd_dev);

    printf("\n추가할 배열 크기 입력: ");
    scanf_s("%d", &extra);

   int *temp = (int *)realloc(arr, (size + extra) * sizeof(int));  // realloc으로 기존 배열 확장, 
    if (!temp)
    {
        printf("메모리 재할당 실패\n");
        free(arr);   // 기존 메모리 해제
        return 1;
    }
    arr = temp;

    printf("%d개의 추가값 입력: ", extra);
    for (int i = size; i < size + extra; i++)
        scanf_s("%d", &arr[i]);

    double finalsum, finalmean, finalvariance, finalstd_dev;
    size += extra;
    calculate(arr, size, &finalsum, &finalmean, &finalvariance, &finalstd_dev);

    printf("초기 배열 크기: %d\n", size - extra);
    printf("입력된 값: ");
    for (int i = 0; i < size - extra; i++)
        printf("%d ", arr[i]);
    printf("합계: %.2f\n",initialsum);
    printf("평균: %.2f\n", initialmean);
    printf("분산: %.2f\n", initialvariance);
    printf("표준 편차: %.2f\n", initialstd_dev);

    printf("추가 배열 크기: %d\n", extra);
    printf("추가된 값: ");
    for (int i = size - extra; i < size; i++)
        printf("%d ", arr[i]);
    printf("새로운 합계: %.2f\n", finalsum);
    printf("새로운 평균: %.2f\n", finalmean);
    printf("새로운 분산: %.2f\n", finalvariance);
    printf("새로운 표준 편차: %.2f\n", finalstd_dev);

    free(arr);   // 동적 메모리 해제
    return 0;
}