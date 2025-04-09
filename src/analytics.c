#include <stdio.h>
#include <string.h>
#include "../include/student.h"
#include "../include/analytics.h"

void showBestWorstSubjects(const Student *s) {
    if (!s) return;

    int best = 0, worst = 0;
    for (int i = 1; i < MAX_SUBJECTS; i++) {
        if (s->subjects[i].mark > s->subjects[best].mark) best = i;
        if (s->subjects[i].mark < s->subjects[worst].mark) worst = i;
    }

    printf("Best Subject: %s (%d)\n", s->subjects[best].name, s->subjects[best].mark);
    printf("Worst Subject: %s (%d)\n", s->subjects[worst].name, s->subjects[worst].mark);
}

void showClassAverages() {
    printf("\n📊 Class Averages by Subject:\n");

    for (int subj = 0; subj < MAX_SUBJECTS; subj++) {
        int total = 0, count = 0;
        char subjectName[MAX_SUBJECT_NAME] = "";

        for (int i = 0; i < studentCount; i++) {
            total += students[i].subjects[subj].mark;
            count++;
            if (i == 0) strcpy(subjectName, students[i].subjects[subj].name);
        }

        if (count > 0) {
            float avg = total / (float)count;
            printf(" - %s: %.2f\n", subjectName, avg);
        }
    }
}

void showSubjectToppers() {
    printf("\n🏅 Subject Toppers:\n");

    for (int subj = 0; subj < MAX_SUBJECTS; subj++) {
        int topMark = -1;
        char subjectName[MAX_SUBJECT_NAME] = "";
        char topper[MAX_NAME_LEN] = "";

        for (int i = 0; i < studentCount; i++) {
            int mark = students[i].subjects[subj].mark;
            if (mark > topMark) {
                topMark = mark;
                strcpy(topper, students[i].name);
                strcpy(subjectName, students[i].subjects[subj].name);
            }
        }

        if (topMark >= 0) {
            printf(" - %s: %s (%d)\n", subjectName, topper, topMark);
        }
    }
}

void viewPerformanceAnalytics() {
    int id;
    printf("\nEnter Student ID to analyze: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("\n📈 Performance Analysis for %s (Avg: %.2f)\n", students[i].name, students[i].average);
            showBestWorstSubjects(&students[i]);
            showClassAverages();
            showSubjectToppers();
            return;
        }
    }

    printf("Student ID not found.\n");
}
