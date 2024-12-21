#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h> // For current working directory

#define NUM_SUBJECTS 3
#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50

typedef enum
{
    KOREAN,
    ENGLISH,
    MATH
} Subject;

typedef struct
{
    char name[MAX_NAME_LEN];
    int id;
    int scores[NUM_SUBJECTS];
    float average;
    int classRank;
    int overallRank;
} Student;

void printWorkingDirectory()
{
    char cwd[1024];
    if (_getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("Current working directory: %s\n", cwd);
    }
    else
    {
        perror("getcwd error");
    }
}

void readFile(const char* filename, Student* students, int* count)
{
    printf("Attempting to open file: %s\n", filename);
    FILE* file;
    errno_t err = fopen_s(&file, filename, "r");
    if (err != 0 || file == NULL)
    {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf_s(file, "%s %d %d %d %d",
        students[*count].name, (unsigned)_countof(students[*count].name),
        &students[*count].id,
        &students[*count].scores[KOREAN],
        &students[*count].scores[ENGLISH],
        &students[*count].scores[MATH]) == 5)
    {
        (*count)++;
    }

    if (*count == 0)
    {
        printf("Error: No data found in file %s\n", filename);
    }
    else {
        printf("Successfully read %d records from %s\n", *count, filename);
    }

    fclose(file);
}

void writeFile(const char* filename, Student* students, int count)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // 헤더 작성 (간격 조정)
    fprintf(file, "%-12s%-20s%-10s%-10s%-10s%-12s%-15s%-15s\n",
        "학번", "이름", "국어", "영어", "수학", "평균", "등수(분반)", "등수(전체)");

    // 데이터 출력 (간격 조정)
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%-12d%-20s%-10d%-10d%-10d%-12.2f%-15d%-15d\n",
            students[i].id, students[i].name,
            students[i].scores[KOREAN], students[i].scores[ENGLISH], students[i].scores[MATH],
            students[i].average, students[i].classRank, students[i].overallRank);
    }

    fclose(file);
    printf("Successfully wrote file: %s\n", filename);
}

void calculateAverage(Student* students, int count)
{
    for (int i = 0; i < count; i++)
    {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++)
        {
            total += students[i].scores[j];
        }
        students[i].average = total / (float)NUM_SUBJECTS;
    }
}

void calculateRank(Student* students, int count)
{
    for (int i = 0; i < count; i++)
    {
        students[i].classRank = 1;
        for (int j = 0; j < count; j++)
        {
            if (students[j].average > students[i].average)
            {
                students[i].classRank++;
            }
        }
    }
}

void calculateOverallRank(Student* students1, int count1, Student* students2, int count2)
{
    for (int i = 0; i < count1; i++)
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
    for (int i = 0; i < count2; i++)
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

void writeClassResults(const char* filename, Student* students1, int count1, float avg1,
    Student* students2, int count2, float avg2)
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    float overallAverage = (count1 + count2 > 0) ? (avg1 * count1 + avg2 * count2) / (count1 + count2) : 0.0f;

    int rank1 = avg1 > avg2 ? 1 : 2;
    int rank2 = avg1 > avg2 ? 2 : 1;

    fprintf(file, "Class 1 Average: %.2f (%d)\n", avg1, rank1);
    fprintf(file, "Class 2 Average: %.2f (%d)\n", avg2, rank2);
    fprintf(file, "Overall Average: %.2f\n", overallAverage);

    fclose(file);
    printf("Successfully wrote file: %s\n", filename);
}

void calculateClassAverage(Student* students, int count, float* classAverage)
{
    if (count == 0)
    {
        *classAverage = 0.0f;
        return;
    }
    float total = 0.0f;
    for (int i = 0; i < count; i++)
    {
        total += students[i].average; // 학생들의 평균 점수를 합산
    }
    *classAverage = total / count; // 분반 평균 계산
}


int main()
{
    printWorkingDirectory();

    Student* students1 = (Student*)malloc(MAX_STUDENTS * sizeof(Student));
    Student* students2 = (Student*)malloc(MAX_STUDENTS * sizeof(Student));
    int count1 = 0, count2 = 0;

    if (!students1 || !students2)
    {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    readFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\students_1.txt", students1, &count1);
    readFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\students_2.txt", students2, &count2);

    if (count1 == 0 || count2 == 0)
    {
        printf("Error: One or more input files are empty or unreadable.\n");
        free(students1);
        free(students2);
        return EXIT_FAILURE;
    }

    calculateAverage(students1, count1);
    calculateAverage(students2, count2);

    calculateRank(students1, count1);
    calculateRank(students2, count2);

    calculateOverallRank(students1, count1, students2, count2);

    writeFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\students_1_results.txt", students1, count1);
    writeFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\students_2_results.txt", students2, count2);

    float class1Average = 0.0f, class2Average = 0.0f;
    calculateClassAverage(students1, count1, &class1Average);
    calculateClassAverage(students2, count2, &class2Average);

    writeClassResults("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\성적관리\\class_results.txt", students1, count1, class1Average, students2, count2, class2Average);

    free(students1);
    free(students2);

    printf("Processing complete.\n");
    return 0;
}