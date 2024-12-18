#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_SUBJECTS 4
#define MAX_STUDENTS 100

typedef enum {
    KOREAN,
    ENGLISH,
    MATH,
    SCIENCE
} Subject;

typedef struct {
    char name[50];
    int id;
    int scores[NUM_SUBJECTS];
    float average;
    int classRank;
    int overallRank;
} Student;

void readFile(const char* filename, Student* students, int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%s %d %d %d %d %d", students[*count].name, &students[*count].id,
        &students[*count].scores[KOREAN], &students[*count].scores[ENGLISH],
        &students[*count].scores[MATH], &students[*count].scores[SCIENCE]) == 6) {
        (*count)++;
    }

    fclose(file);
}

void writeFile(const char* filename, Student* students, int count) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "ID\tName\tKorean\tEnglish\tMath\tScience\tAverage\tClassRank\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\t%s\t%d\t%d\t%d\t%d\t%.2f\t%d\n", students[i].id, students[i].name,
            students[i].scores[KOREAN], students[i].scores[ENGLISH],
            students[i].scores[MATH], students[i].scores[SCIENCE],
            students[i].average, students[i].classRank);
    }

    fclose(file);
}

void calculateAverage(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        int total = 0;
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            total += students[i].scores[j];
        }
        students[i].average = total / (float)NUM_SUBJECTS;
    }
}

void calculateRank(Student* students, int count) {
    for (int i = 0; i < count; i++) {
        students[i].classRank = 1;
        for (int j = 0; j < count; j++) {
            if (students[j].average > students[i].average) {
                students[i].classRank++;
            }
        }
    }
}

int main() {
    Student students1[MAX_STUDENTS], students2[MAX_STUDENTS];
    int count1 = 0, count2 = 0;

    // Read files
    readFile("students_1.txt", students1, &count1);
    readFile("students_2.txt", students2, &count2);

    // Calculate averages
    calculateAverage(students1, count1);
    calculateAverage(students2, count2);

    // Calculate ranks
    calculateRank(students1, count1);
    calculateRank(students2, count2);

    // Write results
    writeFile("students_1_results.txt", students1, count1);
    writeFile("students_2_results.txt", students2, count2);

    printf("Processing complete.\n");
    return 0;
}
