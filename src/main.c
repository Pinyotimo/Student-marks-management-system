#include <stdio.h>
#include "student.h"
#include "grading.h"
#include "reports.h"
#include "analytics.h"
#include "csv_export.h"
#include "grading_config.h"

void showMenu() {
    printf("\n=== STUDENT MARK MANAGEMENT SYSTEM ===\n");
    printf("1. Add New Student Record\n");
    printf("2. Display All Student Records\n");
    printf("3. Search for a Student\n");
    printf("4. Update Student Marks\n");
    printf("5. Delete a Student Record\n");
    printf("6. Export Data to CSV (Excel Format)\n");
    printf("7. Generate Student Performance Report (PDF)\n");
    printf("8. Modify Grading System\n");
    printf("9. View Performance Analytics\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    // Load students on program start
    loadStudentsFromFile();

    do {
        showMenu();
        scanf("%d", &choice);
        getchar(); // clear input buffer

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateMarks(); break;
            case 5: deleteStudent(); break;
            case 6: exportToCSV(); break;
            case 7: generateReportCards(); break;
            case 8: modifyGradingSystem(); break;
            case 9: viewPerformanceAnalytics(); break;
            case 10: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 10);

    return 0;
}
