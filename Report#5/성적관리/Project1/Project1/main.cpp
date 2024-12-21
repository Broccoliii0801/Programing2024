#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SUBJECTS 3    // �л��� ���� �� ����
#define MAX_STUDENTS 100  // �л� �� �迭�� �ִ� ũ�� ����
#define MAX_NAME_LEN 50   // �л� �̸��� �ִ� ���� ����, ����ü���� �ʵ��� �迭 ũ�� ����

typedef struct                          // ����ü ���� �� Student�� ���, �л��� ������ ����
{
    char name[MAX_NAME_LEN];            // �л��� �̸��� �迭�� ����
    int id;
    int scores[NUM_SUBJECTS];           // �л��� �� ���� ������ �迭�� ����
    float average;
    int classRank;
    int overallRank;
} Student;

void readFile(const char* filename, Student* students, int* count)        // ���� �б� �Լ� ����, �л� ������ students �迭�� ����, �� �л� ���� count�� �Է�
{
    FILE* file;                                                           // FILE Ÿ�� ������ ���
    errno_t err = fopen_s(&file, filename, "r");                          // fopen_s�� �ܵ����� ��� �� ���� �߻����� ���� ��ȯ��errno_t�� �̿���
    if (err != 0 || file == NULL)                                         // ��ȯ���� 0�� �� ���� �б� ����, ���� �� NULL ��ȯ
    {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);                                               // ���� �б� ���� �� ���α׷� ����
    }

    *count = 0;                                                           // count ���� �ʱ�ȭ
    while (fscanf_s(file, "%s %d %d %d %d",                               // ���Ϸκ��� ������ �б�
        students[*count].name, (unsigned)_countof(students[*count].name), // _���� �κ��� ���� �迭 ũ�⸦ ������
        &students[*count].id,
        &students[*count].scores[0],                                      // 0�� ����, 1�� ����, 2�� ���� ����
        &students[*count].scores[1],
        &students[*count].scores[2]) == 5)
    {
        (*count)++;                                                       // �� ���� �����͸� ���� ������ ���� �л����� �Ѿ
    }

    fclose(file);                                                         // �۾� ���� �� ���� �ݱ�
}

void writeFile(const char* filename, Student* students, int count)                    // �л� ������ ���Ͽ� ����
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");                                      // ���� �ۼ�, ���� ���� ���� �� 0 ��ȯ
    if (err != 0 || file == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%-12s%-20s%-10s%-10s%-10s%-12s%-15s%-15s\n",                       // ���� ���� �� ������ ����� ���� �� ��� ��� �� ���� ����
        "�й�", "�̸�", "����", "����", "����", "���", "���(�й�)", "���(��ü)");

    for (int i = 0; i < count; i++)                                                   // �ݺ��� ������� �����͸� ���Ͽ� ���
    {
        fprintf(file, "%-12d%-20s%-10d%-10d%-10d%-12.2f%-15d%-15d\n",
            students[i].id, students[i].name,
            students[i].scores[0], students[i].scores[1], students[i].scores[2],
            students[i].average, students[i].classRank, students[i].overallRank);
    }

    fclose(file);
    printf("Successfully wrote file: %s\n", filename);
}

void calculateAverage(Student* students, int count)               // ��� ���� ��� �� students ����ü �迭�� ����
{
    for (int i = 0; i < count; i++)                               // �ݺ����� ���� ��� �л��� ��� ���� ���
    {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++)                    // ���� �ش��ϴ� j
        {
            total += students[i].scores[j];                       // �л��� ���� ������ ����
        }
        students[i].average = total / (float)NUM_SUBJECTS;        // ��� ���
    }
}

void calculateRank(Student* students, int count)                  // ��� ��� �Լ�
{
    for (int i = 0; i < count; i++)
    {
        students[i].classRank = 1;                                // �л��� ���� �й� �� ����� 1������ �ʱ�ȭ �� �ٸ� �л����� ������ ��
        for (int j = 0; j < count; j++)                           // �ٸ� �л��� j�� ���� �� ���� �л�(i)�� ��
        {
            if (students[j].average > students[i].average)
            {
                students[i].classRank++;                          // �� ����� ������ �� ������ ���� �л��� ������� 1 ����
            }
        }
    }
}

void calculateOverallRank(Student* students1, int count1, Student* students2, int count2)  // �� �й��� �����͸� ���ļ� ��ü ��� ���
{
    for (int i = 0; i < count1; i++)                                                       // ù ��° �й��� ��� ���
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
    for (int i = 0; i < count2; i++)                                                       // �� ��° �й��� ��� ���
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

void calculateClassAverage(Student* students, int count, float* classAverage)      // ������� ��� �� classAverage�� ����
{
    if (count == 0)                                                                // �йݿ� �л� ���� ��� ó��, 0�̸� �Լ� ����
    {
        *classAverage = 0.0f;
        return;
    }
    float total = 0.0f;
    for (int i = 0; i < count; i++)                                                // �迭�� ��� �л��� ��� ���� �ջ�
    {
        total += students[i].average;
    }
    *classAverage = total / count;                                                 // �й��� ��ü ��������� classAverage �����Ϳ� ����
}  

void writeClassResults(const char* filename, Student* students1, int count1, float avg1, Student* students2, int count2, float avg2)
// �� �й��� ��������� ��ü ��������� ���Ͽ� ����
{
    FILE* file;
    errno_t err = fopen_s(&file, filename, "w");
    if (err != 0 || file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    float overallAverage = (count1 + count2 > 0) ? (avg1 * count1 + avg2 * count2) / (count1 + count2) : 0.0f;
    // �� �й��� ��������� ������� ��ü ��� ���� ���, �л� ���� 0���� ū ��쿡�� ���, �л� ���� 0�̸� ��� ���� 0���� ����
    int rank1 = avg1 > avg2 ? 1 : 2;      // ù��° �й��� ��� ������ �ι�° �й��� ������ ��
    int rank2 = avg1 > avg2 ? 2 : 1;

    fprintf(file, "Class 1 Average: %.2f (%d)\n", avg1, rank1);
    fprintf(file, "Class 2 Average: %.2f (%d)\n", avg2, rank2);
    fprintf(file, "Overall Average: %.2f\n", overallAverage);

    fclose(file);
    printf("Successfully wrote file: %s\n", filename);
}

int main()
{
    Student* students1 = (Student*)malloc(MAX_STUDENTS * sizeof(Student));        // ù ��° �й��� �����͸� ������ ���� �޸� �Ҵ�
    Student* students2 = (Student*)malloc(MAX_STUDENTS * sizeof(Student));        // �� ��° �й��� �����͸� ������ ���� �޸� �Ҵ�
    int count1 = 0, count2 = 0;                                                   // �� �й��� �л� ���� ������ ���� �ʱ�ȭ

    if (!students1 || !students2)                                                 // ���� �޸� �Ҵ� ���� Ȯ��
    {
        return EXIT_FAILURE;
    }

    readFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\��������\\students_1.txt", students1, &count1);  // ���Ͽ��� �����͸� ���� �� students1 �迭�� ����
    readFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\��������\\students_2.txt", students2, &count2);  // ���Ͽ��� �����͸� ���� �� students2 �迭�� ����

    if (count1 == 0 || count2 == 0)                                                                                           // �� ���� �� �ϳ��� �����Ͱ� ������ ���α׷� ����
    {
        printf("Error: One or more input files are empty or unreadable.\n");
        free(students1); // ���� �޸� ����
        free(students2);
        return EXIT_FAILURE;
    }

    calculateAverage(students1, count1);                                                                                      // �л� ��� ���� ��� �� ����
    calculateAverage(students2, count2);

    calculateRank(students1, count1);                                                                                         // �л� �й� �� ��� ��� �� ����
    calculateRank(students2, count2);

    calculateOverallRank(students1, count1, students2, count2);                                                               // �л� ��ü ��� ��� �� ����

    writeFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\��������\\students_1_results.txt", students1, count1);  // ù ��° �й��� ��� ������ ���Ϸ� ����
    writeFile("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\��������\\students_2_results.txt", students2, count2);  // �� ��° �й��� ��� ������ ���Ϸ� ����

    float class1Average = 0.0f, class2Average = 0.0f;                                                                                 // �� �й��� ��� ������ ������ ���� ���� �� �ʱ�ȭ
    calculateClassAverage(students1, count1, &class1Average);                                                                         // �й��� ��� ���� ��� �� ����
    calculateClassAverage(students2, count2, &class2Average);

    writeClassResults("C:\\Users\\didgm\\Documents\\GitHub\\Programing2024\\Report#5\\��������\\class_results.txt", students1, count1, class1Average, students2, count2, class2Average);
    // �� �й��� ��� ����, ��ü ��� ����, �й� ������ ���Ϸ� ����
    free(students1);  // ���� �޸� �Ҵ� ����
    free(students2);

    printf("Processing complete.\n");
    return 0;
}
