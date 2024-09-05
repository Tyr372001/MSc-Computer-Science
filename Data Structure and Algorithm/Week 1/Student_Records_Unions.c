/*
AIM: To store student records using Unions and structure in C language.
AUTHOR: Subhradeep Sarkar
PLATFORM: DEV C/C++
DATE: Friday, 23 August
*/

#include <stdio.h>
#include <string.h>

// Define a union for different types of student information
union StudentInfo {
    int student_id;
    float gpa;
    char name[50];
};

// Define a struct to hold the student's basic information and the union
struct Student {
    char type; // Type of information stored in the union ('I' for ID, 'G' for GPA, 'N' for Name)
    union StudentInfo info;
};

void printStudentInfo(struct Student student) {
    switch (student.type) {
        case 'I':
            printf("Student ID: %d\n", student.info.student_id);
            break;
        case 'G':
            printf("GPA: %.2f\n", student.info.gpa);
            break;
        case 'N':
            printf("Name: %s\n", student.info.name);
            break;
        default:
            printf("Unknown type\n");
    }
}

int main() {
    // Create a student record for ID
    struct Student student1;
    student1.type = 'I'; // Indicates that the union holds a student ID
    student1.info.student_id = 12345;
    
    // Create a student record for GPA
    struct Student student2;
    student2.type = 'G'; // Indicates that the union holds a GPA
    student2.info.gpa = 3.75;
    
    // Create a student record for Name
    struct Student student3;
    student3.type = 'N'; // Indicates that the union holds a Name
    strcpy(student3.info.name, "Alice Johnson");
    
    // Print out student information
    printStudentInfo(student1);
    printStudentInfo(student2);
    printStudentInfo(student3);
    
    return 0;
}

