#include <stdio.h>
#include "grading.h"

char getGrade(int mark) {
    if (mark >= GRADE_A) return 'A';
    else if (mark >= GRADE_B) return 'B';
    else if (mark >= GRADE_C) return 'C';
    else if (mark >= GRADE_D) return 'D';
    else return 'E';
}

const char* getFeedback(char grade) {
    switch (grade) {
        case 'A': return "Excellent performance.";
        case 'B': return "Good understanding.";
        case 'C': return "Satisfactory effort.";
        case 'D': return "Needs improvement.";
        case 'E': return "Unsatisfactory. Work harder!";
        default: return "Invalid grade.";
    }
}

const char* getTeacherComment(float average) {
    if (average >= GRADE_A) return "Outstanding student!";
    else if (average >= GRADE_B) return "Above average performance.";
    else if (average >= GRADE_C) return "Average performance.";
    else if (average >= GRADE_D) return "Below average. Needs support.";
    else return "Poor performance. Consider extra help.";
}

void modifyGradingSystem() {
    printf("Custom grading thresholds feature coming soon.\n");
    // Optional: implement config file reader or CLI thresholds here
}
