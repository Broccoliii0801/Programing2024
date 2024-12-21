#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SUBJECTS 3    // 학생의 과목 수 정의
#define MAX_STUDENTS 100  // 학생 수 배열의 최대 크기 정의
#define MAX_NAME_LEN 50   // 학생 이름의 최대 길이 정의, 구조체에서 필드의 배열 크기 설정

typedef struct                          // 구조체 정의 후 Student로 사용, 학생의 데이터 저장
{
    char name[MAX_NAME_LEN];            // 학생의 이름을 배열로 저장
    int id;
    int scores[NUM_SUBJECTS];           // 학생의 각 과목 점수를 배열로 저장
    float average;
    int classRank;
    int overallRank;
} Student;

void readFile(const char* filename, Student* students, int* count)        // 파일 읽기 함수 정의, 학생 정보를 students 배열에 저장, 총 학생 수를 count에 입력
{
    FILE* file;                                                           // FILE 타입 포인터 사용
    errno_t err = fopen_s(&file, filename, "r");                          // fopen_s만 단독으로 사용 시 오류 발생으로 인해 반환값errno_t를 이용함
    if (err != 0 || file == NULL)                                         // 반환값이 0일 시 파일 읽기 성공, 실패 시 NULL 반환
    {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);                                               // 파일 읽기 실패 시 프로그램 종료
    }

    *count = 0;                                                           // count 변수 초기화
    while (fscanf_s(file, "%s %d %d %d %d",                               // 파일로부터 데이터 읽기
        students[*count].name, (unsigned)_countof(students[*count].name), // _이후 부분을 통해 배열 크기를 가져옴
        &students[*count].id,
        &students[*count].scores[0],                                      // 0은 국어, 1은 영어, 2는 수학 점수
        &students[*count].scores[1],
        &students[*count].scores[2]) == 5)
    {
        (*count)++;                                                       // 한 명의 데이터를 읽을 때마다 다음 학생으로 넘어감
    }

    fclose(file);                                                         // 작업 종료 시 파일 닫기
}

void writeFile(const char* filename, Student* students, int count)                    // 학생 데이터 파일에 저장
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");                                      // 파일 작성, 파일 열기 성공 시 0 반환
    if (err != 0 || file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%-12s%-20s%-10s%-10s%-10s%-12s%-15s%-15s\n",                       // 파일 저장 시 가독성 향상을 위해 각 헤더 출력 시 간격 조정
        "학번", "이름", "국어", "영어", "수학", "평균", "등수(분반)", "등수(전체)");

    for (int i = 0; i < count; i++)                                                   // 반복문 사용으로 데이터를 파일에 출력
    {
        fprintf(file, "%-12d%-20s%-10d%-10d%-10d%-12.2f%-15d%-15d\n",
            students[i].id, students[i].name,
            students[i].scores[0], students[i].scores[1], students[i].scores[2],
            students[i].average, students[i].classRank, students[i].overallRank);
    }

    fclose(file);
    printf("Successfully wrote file: %s\n", filename);
}

void calculateAverage(Student* students, int count)               // 평균 점수 계산 후 students 구조체 배열에 저장
{
    for (int i = 0; i < count; i++)                               // 반복문을 통해 모든 학생의 평균 점수 계산
    {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++)                    // 과목에 해당하는 j
        {
            total += students[i].scores[j];                       // 학생의 과목 점수를 누적
        }
        students[i].average = total / (float)NUM_SUBJECTS;        // 평균 계산
    }
}

void calculateRank(Student* students, int count)                  // 등수 계산 함수
{
    for (int i = 0; i < count; i++)
    {
        students[i].classRank = 1;                                // 학생의 현재 분반 내 등수를 1등으로 초기화 후 다른 학생들의 점수와 비교
        for (int j = 0; j < count; j++)                           // 다른 학생을 j라 했을 때 현재 학생(i)과 비교
        {
            if (students[j].average > students[i].average)
            {
                students[i].classRank++;                          // 비교 대상의 점수가 더 높으면 현재 학생의 등수에서 1 증가
            }
        }
    }
}

void calculateOverallRank(Student* students1, int count1, Student* students2, int count2)  // 두 분반의 데이터를 합쳐서 전체 등수 계산
{
    for (int i = 0; i < count1; i++)                                                       // 첫 번째 분반의 등수 계산
    {
        students1[i].overallRank = 1;
        for (int j = 0; j < count1; j++)
        {
            if (students1[j].average > students1[i].average)
            {
                students1[i].overallRank++;
            }
        }
        for (int j = 0; j < count2; j++)
        {
            if (students2[j].average > students1[i].average)
            {
                students1[i].overallRank++;
            }
        }
    }
    for (int i = 0; i < count2; i++)                                                       // 두 번째 분반의 등수 계산
    {
        students2[i].overallRank = 1;
        for (int j = 0; j < count1; j++)
        {
            if (students1[j].average > students2[i].average)
            {
                students2[i].overallRank++;
            }
        }
        for (int j = 0; j < count2; j++)
        {
            if (students2[j].average > students2[i].average)
            {
                students2[i].overallRank++;
            }
        }
    }
}

void calculateClassAverage(Student* students, int count, float* classAverage)      // 평균점수 계산 후 classAverage에 저장
{
    if (count == 0)                                                                // 분반에 학생 없는 경우 처리, 0이면 함수 종료
    {
        *classAverage = 0.0f;
        return;
    }
    float total = 0.0f;
    for (int i = 0; i < count; i++)                                                // 배열의 모든 학생의 평균 점수 합산
    {
        total += students[i].average;
    }
    *classAverage = total / count;                                                 // 분반의 전체 평균점수를 classAverage 포인터에 저장
}  

void writeClassResults(const char* filename, Student* students1, int count1, float avg1, Student* students2, int count2, float avg2)
// 두 분반의 평균점수와 전체 평균점수를 파일에 저장
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    float overallAverage = (count1 + count2 > 0) ? (avg1 * count1 + avg2 * count2) / (count1 + count2) : 0.0f;
    // 두 분반의 평균점수를 기반으로 전체 평균 점수 계산, 학생 수가 0보다 큰 경우에만 계산, 학생 수가 0이면 평균 점수 0으로 설정
    int rank1 = avg1 > avg2 ? 1 : 2;      // 첫번째 분반의 평균 점수를 두번째 분반의 점수와 비교
    int rank2 = avg1 > avg2 ? 2 : 1;

    fprintf(file, "Class 1 Average: %.2f (%d)\n", avg1, rank1);
    fprintf(file, "Class 2 Average: %.2f (%d)\n", avg2, rank2);
    fprintf(file, "Overall Average: %.2f\n", overallAverage);

    fclose(file);
    printf("Successfully wrote file: %s\n", filename);
}

int main()
{
    Student* students1 = (Student*)malloc(MAX_STUDENTS * sizeof(Student));        // 첫 번째 분반의 데이터를 저장할 동적 메모리 할당
    Student* students2 = (Student*)malloc(MAX_STUDENTS * sizeof(Student));        // 두 번째 분반의 데이터를 저장할 동적 메모리 할당
    int count1 = 0, count2 = 0;                                                   // 두 분반의 학생 수를 저장할 변수 초기화

    if (!students1 || !students2)                                                 // 동적 메모리 할당 여부 확인
    {
        return EXIT_FAILURE;
    }

    readFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\students_1.txt", students1, &count1);  // 파일에서 데이터를 읽은 후 students1 배열에 저장
    readFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\students_2.txt", students2, &count2);  // 파일에서 데이터를 읽은 후 students2 배열에 저장

    if (count1 == 0 || count2 == 0)                                                                                           // 두 파일 중 하나라도 데이터가 없으면 프로그램 종료
    {
        printf("Error: One or more input files are empty or unreadable.\n");
        free(students1); // 동적 메모리 해제
        free(students2);
        return EXIT_FAILURE;
    }

    calculateAverage(students1, count1);                                                                                      // 학생 평균 점수 계산 후 저장
    calculateAverage(students2, count2);

    calculateRank(students1, count1);                                                                                         // 학생 분반 내 등수 계산 후 저장
    calculateRank(students2, count2);

    calculateOverallRank(students1, count1, students2, count2);                                                               // 학생 전체 등수 계산 후 저장

    writeFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\students_1_results.txt", students1, count1);  // 첫 번째 분반의 결과 데이터 파일로 저장
    writeFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\students_2_results.txt", students2, count2);  // 두 번째 분반의 결과 데이터 파일로 저장

    float class1Average = 0.0f, class2Average = 0.0f;                                                                                 // 두 분반의 평균 점수를 저장할 변수 선언 후 초기화
    calculateClassAverage(students1, count1, &class1Average);                                                                         // 분반의 평균 점수 계산 후 저장
    calculateClassAverage(students2, count2, &class2Average);

    writeClassResults("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\class_results.txt", students1, count1, class1Average, students2, count2, class2Average);
    // 두 분반의 평균 점수, 전체 평균 점수, 분반 순위를 파일로 저장
    free(students1);  // 동적 메모리 할당 해제
    free(students2);

    printf("Processing complete.\n");
    return 0;
}
