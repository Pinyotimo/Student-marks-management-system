#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cairo.h>
#include <cairo-pdf.h>
#include "../include/student.h"
#include "../include/reports.h"
#include "../include/grading.h"

// Function to generate a PDF for one student
void generateReportCard(int studentID) {
    // Find the student based on ID from the global array
    Student *student = NULL;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentID) {
            student = &students[i];
            break;
        }
    }

    if (!student) {
        printf("Student not found (ID: %d).\n", studentID);
        return;
    }

    // Prepare output PDF file path
    char filename[150];
    snprintf(filename, sizeof(filename), "output/ReportCards/%d_ReportCard.pdf", student->id);

    // Create a Cairo PDF surface (A4 page: 595 x 842)
    cairo_surface_t *surface = cairo_pdf_surface_create(filename, 595, 842);
    cairo_t *cr = cairo_create(surface);

    // Title
    cairo_select_font_face(cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 18);
    cairo_move_to(cr, 50, 50);
    cairo_show_text(cr, "Student Report Card");

    // Student info: name, id, average marks
    cairo_set_font_size(cr, 12);
    cairo_move_to(cr, 50, 100);
    cairo_show_text(cr, "Student Name: ");
    cairo_show_text(cr, student->name);

    cairo_move_to(cr, 50, 120);
    cairo_show_text(cr, "Student ID: ");
    char temp[20];
    sprintf(temp, "%d", student->id);
    cairo_show_text(cr, temp);

    cairo_move_to(cr, 50, 140);
    cairo_show_text(cr, "Average Mark: ");
    sprintf(temp, "%.2f", student->average);
    cairo_show_text(cr, temp);

    // Subject details
    cairo_move_to(cr, 50, 180);
    cairo_show_text(cr, "Subjects:");
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        cairo_move_to(cr, 50, 200 + i * 20);
        cairo_show_text(cr, student->subjects[i].name);

        cairo_move_to(cr, 250, 200 + i * 20);
        sprintf(temp, "%d", student->subjects[i].mark);
        cairo_show_text(cr, temp);

        cairo_move_to(cr, 350, 200 + i * 20);
        char gradeStr[2] = { student->subjects[i].grade, '\0' };
        cairo_show_text(cr, gradeStr);
    }

    // Overall teacher comment
    cairo_move_to(cr, 50, 200 + MAX_SUBJECTS * 20 + 20);
    const char* comment = getTeacherComment(student->average);
    cairo_show_text(cr, "Teacher's Comment: ");
    cairo_move_to(cr, 50, 200 + MAX_SUBJECTS * 20 + 40);
    cairo_show_text(cr, comment);

    // Finish the PDF
    cairo_show_page(cr);
    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    printf("Report Card generated for Student ID %d: %s\n", student->id, filename);
}

// Wrapper function to generate report cards for ALL students
void generateReportCards() {
    if (studentCount == 0) {
        printf("No student records available.\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        generateReportCard(students[i].id);
    }
}
