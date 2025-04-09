#ifndef STUDENT_H
#define STUDENT_H

#define MAX_SUBJECTS 13
#define MAX_NAME_LEN 50
#define MAX_SUBJECT_NAME 30
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_SUBJECT_NAME];
    int mark;
    char teacher[MAX_NAME_LEN];
    char grade;
    char feedback[100];
} Subject;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    Subject subjects[MAX_SUBJECTS];
    float average;
} Student;

// Functions
void addStudent();
void displayStudents();
void searchStudent();
void updateMarks();
void deleteStudent();
void loadStudentsFromFile();
void saveStudentsToFile();

extern Student students[MAX_STUDENTS];
extern int studentCount;

#endif
