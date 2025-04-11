#include <stdio.h>
#include <string.h>

typedef struct {
    char subject[50];
    char teacher[50];
    int marks;
    char grade[3]; // Allocate enough space for grades like "A-", "B+", "E", plus null terminator
    char comments[100];
} Subject;

const char* getGrade(int marks) {
    if (marks >= 75) return "A-";
    if (marks >= 70) return "B+";
    if (marks >= 65) return "B";
    if (marks >= 60) return "B-";
    if (marks >= 55) return "C+";
    if (marks >= 50) return "C";
    if (marks >= 45) return "C-";
    if (marks >= 40) return "D+";
    if (marks >= 35) return "D";
    if (marks >= 30) return "D-";
    return "E";
}

int main() {
    Subject student1[] = {
        {"English", "Mrs. Brown", 80, "", ""},
        {"Kiswahili", "Mr. Kamau", 65, "", ""},
        {"Mathematics", "Mr. Kimani", 92, "", ""},
        {"Science", "Mrs. Okoro", 78, "", ""},
        {"History", "Mr. Ochieng", 55, "", ""},
        {"Geography", "Ms. Wanjiku", 62, "", ""},
        {"Art", "Mr. Otieno", 70, "", ""},
        {"Music", "Mrs. Adongo", 85, "", ""},
        {"Physics", "Dr. Mwangi", 48, "", ""},
        {"Chemistry", "Ms. Chebet", 73, "", ""},
        {"Biology", "Mr. Juma", 59, "", ""},
        {"Commerce", "Mrs. Njeri", 68, "", ""},
        {"CRE", "Pastor Maina", 90, "", ""},
        {"Computer Studies", "Mr. Kamau", 88, "", ""},
        {"French", "Madam Dubois", 76, "", ""},
        {"German", "Herr Schmidt", 63, "", ""},
        {"Business Studies", "Mr. Patel", 52, "", ""},
        {"Agriculture", "Mr. Ruto", 40, "", ""},
        {"Home Science", "Mrs. Awino", 79, "", ""},
        {"Woodwork", "Mr. Barasa", 66, "", ""},
        {"Metalwork", "Mr. Omondi", 57, "", ""},
        {"Technical Drawing", "Mr. Kinyua", 82, "", ""},
        {"Accounting", "Mrs. Were", 71, "", ""},
        {"Economics", "Mr. Onyango", 61, "", ""},
        {"Literature", "Ms. Atieno", 54, "", ""},
        {"Library", "Mrs. Njoroge", 95, "", ""},
        {"Games", "Mr. Koech", 87, "", ""},
        {"Guidance and Counseling", "Mrs. Mueni", 74, "", ""},
        {"Social Studies", "Mr. Kamau", 69, "", ""},
        {"Environmental Science", "Ms. Cherono", 51, "", ""}
    };

    int numSubjects = sizeof(student1) / sizeof(student1[0]);

    printf("Student Report:\n");
    printf("---------------------------------------------------\n");
    printf("%-20s %-10s %-5s %-10s\n", "Subject", "Teacher", "Marks", "Grade");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < numSubjects; i++) {
        strcpy(student1[i].grade, getGrade(student1[i].marks));
        printf("%-20s %-10s %-5d %-10s\n",
               student1[i].subject, student1[i].teacher, student1[i].marks, student1[i].grade);
    }

    printf("---------------------------------------------------\n");

    // Example of accessing a specific subject's grade
    printf("\nGrade in English: %s\n", student1[0].grade);
    printf("Grade in Mathematics: %s\n", student1[2].grade);

    return 0;
}