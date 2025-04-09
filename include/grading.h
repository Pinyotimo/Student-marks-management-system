#ifndef GRADING_H
#define GRADING_H

// Default grade thresholds
#define GRADE_A 85
#define GRADE_B 70
#define GRADE_C 55
#define GRADE_D 40
#define GRADE_E 0

char getGrade(int mark);
const char* getFeedback(char grade);
const char* getTeacherComment(float average);

// For future use if grading scale is made dynamic
void modifyGradingSystem();

#endif
